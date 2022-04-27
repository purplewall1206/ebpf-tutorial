#include "monitor.h"


MODULE_LICENSE("GPL");

static int __init kprobe_init(void)
{
    // int ret;
    // // kp.pre_handler = handler_pre;//---------------------------------------------------初始化kp的三个回调函数。
    // // kp.post_handler = handler_post;
    // // kp.fault_handler = handler_fault;

    // ret = register_kprobes(kps, 230);//-----------------------------------------------------注册kp探测点到内核。
    // if (ret < 0) {
    //     pr_err("register_kprobe failed, returned %d\n", ret);
    //     return ret;
    // }
    // pr_info("Planted kprobe at %pF\n", kps);

    int ret;

    ret = register_kretprobes(fn_kps, 230);
    if (ret < 0) {
        pr_err("register_kretprobes failed, fn_kps returned %d\n", ret);
        return ret;
    }

    ret = register_kretprobes(fp_kps, 60);
    if (ret < 0) {
        pr_err("register_kretprobes failed, fp_kps returned %d\n", ret);
        return ret;
    }

    pr_info("Planted fn & fp kretprobes\n");

    return 0;
}

static void __exit kprobe_exit(void)
{
    // struct module *(*find_modulex)(char *);
    // struct module *ext4_mod;
    // find_modulex = 0xffffffff9bbf0330;

    // ext4_mod = find_modulex("ext4");
    // if (!ext4_mod) {
    //     pr_info("ext4 not found\n");
    // } else {
    //     pr_info("ext4 base: %016lx, text_size:%u\n", ext4_mod->core_layout.base, ext4_mod->core_layout.text_size);
    // }
    unregister_kretprobes(fn_kps, 230);
    unregister_kretprobes(fp_kps, 60);
    pr_info("kretprobe unregistered\n");
}

module_init(kprobe_init)
module_exit(kprobe_exit)


