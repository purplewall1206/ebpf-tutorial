#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>

#define MAX_SYMBOL_LEN    64
static char symbol[MAX_SYMBOL_LEN] = "generic_file_read_iter";
module_param_string(symbol, symbol, sizeof(symbol), 0644);



/* For each probe you need to allocate a kprobe structure */
static struct kprobe kp = {//---------------------------------------------------------定义一个实例kp并初始化symbol_name为"_do_fork"，将探测_do_fork函数。
    .symbol_name    = symbol,
};

// void show_pre_2(unsigned long *sp)
// {
//     struct unwind_state state;
// 	struct stack_info stack_info = {0};
// 	unsigned long visit_mask = 0;
// 	int graph_idx = 0;
// 	bool partial = false;
//     struct task_struct *task = current;
//     void *stack = NULL;

//     unwind_start(&state, task, regs, stack);
// 	stack = stack ? : get_stack_pointer(task, regs);
// 	regs = unwind_get_entry_regs(&state, &partial);
// }

/* kprobe pre_handler: called just before the probed instruction is executed */
static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
    char name_sym[100];
    pr_info("<%s> pre_handler: p->addr = %pF, ip = %lx, flags = 0x%lx\n",
        p->symbol_name, p->addr, regs->ip, regs->flags);

    // pr_info("caller %016lx\n", __builtin_return_address(0));
    // pr_info("caller's caller  %016lx\n", __builtin_return_address(1));
    // pr_info("caller* 3  %016lx\n", __builtin_return_address(2));
    // pr_info("caller* 4  %016lx\n", __builtin_return_address(3));
    /* A dump_stack() here will give a stack backtrace */
    // dump_stack();
    return 0;
}

/* kprobe post_handler: called after the probed instruction is executed */
static void handler_post(struct kprobe *p, struct pt_regs *regs,
                unsigned long flags)
{
    pr_info("<%s> post_handler: p->addr = %pF, flags = 0x%lx\n",
        p->symbol_name, p->addr, regs->flags);

}

/*
 * fault_handler: this is called if an exception is generated for any
 * instruction within the pre- or post-handler, or when Kprobes
 * single-steps the probed instruction.
 */
static int handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr)
{
    pr_info("fault_handler: p->addr = %pF, trap #%dn", p->addr, trapnr);
    /* Return 0 because we don't handle the fault. */
    return 0;
}

static int __init kprobe_init(void)
{
    int ret;
    kp.pre_handler = handler_pre;//---------------------------------------------------初始化kp的三个回调函数。
    // kp.post_handler = handler_post;
    // kp.fault_handler = handler_fault;

    ret = register_kprobe(&kp);//-----------------------------------------------------注册kp探测点到内核。
    if (ret < 0) {
        pr_err("register_kprobe failed, returned %d\n", ret);
        return ret;
    }
    pr_info("Planted kprobe at %pF\n", kp.addr);
    return 0;
}

static void __exit kprobe_exit(void)
{
    struct module *(*find_modulex)(char *);
    struct module *ext4_mod;
    find_modulex = 0xffffffff9bbf0330;

    ext4_mod = find_modulex("ext4");
    if (!ext4_mod) {
        pr_info("ext4 not found\n");
    } else {
        pr_info("ext4 base: %016lx, text_size:%u\n", ext4_mod->core_layout.base, ext4_mod->core_layout.text_size);
    }
    unregister_kprobe(&kp);
    pr_info("kprobe at %pF unregistered\n", kp.addr);
}

module_init(kprobe_init)
module_exit(kprobe_exit)
MODULE_LICENSE("GPL");