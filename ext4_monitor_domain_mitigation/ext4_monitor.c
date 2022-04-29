#include "monitor.h"
#include <linux/sched.h>

#define SWITCH_KERENL_STACK \
					unsigned long RSP; \
                    asm volatile ("mov %%rsp, %0" : "=m"(RSP):); \
        	        asm volatile ("mov %0, %%rsp": :""(RSP)); 

#define SWITCH_EXTENSION_STACK
					unsigned long RSP; \	
                    asm volatile ("mov %%rsp, %0" : "=m"(RSP):); \
        	        asm volatile ("mov %0, %%rsp": :""(RSP)); 

static inline long kvm_vmfunc(unsigned int eptp)
{
    long ret;
    asm volatile("vmfunc"
            : "=q"(ret)
            : "c" (eptp), "a" (0)
            : "cc");
    return ret;
}

#define SWITCH_KERNEL_EPT kvm_vmfunc(0);

#define SWITCH_EXTENSION_EPT kvm_vmfunc(1);

struct inode *dummy_inode;

#define SYNC  SYNC_INODE(dummy_inode, dummy_inode->shadow_obj);

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

    pr_info("kprobe_init\n ");

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

	dummy_inode = (struct inode *) kmalloc(sizeof(struct inode), GFP_KERNEL);
	dummy_inode->shadow_obj = (struct inode *) kmalloc(sizeof(struct inode), GFP_KERNEL);

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
    pr_info("kprobe exit\n");
    unregister_kretprobes(fn_kps, 230);
    unregister_kretprobes(fp_kps, 60);
    pr_info("kretprobe unregistered\n");
}

module_init(kprobe_init)
module_exit(kprobe_exit)




// =====================================================



DEFINE_PER_CPU(bool, ext4_executing) = false;





static int I_BDEV_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int I_BDEV_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __bdev_dax_supported_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __bdev_dax_supported_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __bforget_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __bforget_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __bio_add_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __bio_add_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __blkdev_issue_discard_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __blkdev_issue_discard_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __blkdev_issue_zeroout_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __blkdev_issue_zeroout_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __block_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __block_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __blockdev_direct_IO_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __blockdev_direct_IO_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __bread_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __bread_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __breadahead_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __breadahead_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __brelse_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __brelse_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __cleancache_get_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __cleancache_get_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __cleancache_init_fs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __cleancache_init_fs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __fdget_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __fdget_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __filemap_set_wb_err_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __filemap_set_wb_err_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __find_get_block_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __find_get_block_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __generic_file_fsync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __generic_file_fsync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __generic_file_write_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __generic_file_write_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __getblk_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __getblk_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __init_waitqueue_head_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __init_waitqueue_head_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __lock_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __lock_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __mark_inode_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __mark_inode_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __mb_cache_entry_free_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __mb_cache_entry_free_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __page_symlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __page_symlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __pagevec_release_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __pagevec_release_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __percpu_down_read_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __percpu_down_read_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __percpu_init_rwsem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __percpu_init_rwsem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __put_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __put_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __refrigerator_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __refrigerator_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __set_page_dirty_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __set_page_dirty_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __set_page_dirty_nobuffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __set_page_dirty_nobuffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __sync_dirty_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __sync_dirty_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __test_set_page_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __test_set_page_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __var_waitqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __var_waitqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __wait_on_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __wait_on_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __wake_up_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __wake_up_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int __warn_printk_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int __warn_printk_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int add_to_page_cache_lru_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int add_to_page_cache_lru_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int bdev_read_only_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int bdev_read_only_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int bdevname_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int bdevname_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int bh_submit_read_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int bh_submit_read_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int bh_uptodate_or_lock_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int bh_uptodate_or_lock_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int bio_alloc_bioset_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int bio_alloc_bioset_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int bio_devname_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int bio_devname_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int bio_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int bio_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int blk_finish_plug_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int blk_finish_plug_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int blk_start_plug_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int blk_start_plug_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int blk_status_to_errno_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int blk_status_to_errno_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int blkdev_get_by_dev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int blkdev_get_by_dev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int blkdev_issue_discard_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int blkdev_issue_discard_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int blkdev_issue_flush_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int blkdev_issue_flush_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int blkdev_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int blkdev_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int block_commit_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int block_commit_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int block_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int block_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int block_page_mkwrite_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int block_page_mkwrite_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int block_read_full_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int block_read_full_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int block_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int block_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int capable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int capable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int clean_bdev_aliases_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int clean_bdev_aliases_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int clear_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int clear_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int clear_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int clear_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int clear_page_dirty_for_io_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int clear_page_dirty_for_io_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int create_empty_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int create_empty_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int crypto_alloc_shash_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int crypto_alloc_shash_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int crypto_destroy_tfm_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int crypto_destroy_tfm_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int crypto_shash_update_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int crypto_shash_update_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int current_time_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int current_time_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_find_any_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_find_any_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_instantiate_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_instantiate_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_instantiate_new_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_instantiate_new_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_make_root_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_make_root_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_obtain_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_obtain_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_splice_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_splice_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int d_tmpfile_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int d_tmpfile_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dax_finish_sync_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dax_finish_sync_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dax_iomap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dax_iomap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dax_iomap_rw_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dax_iomap_rw_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dax_layout_busy_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dax_layout_busy_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dax_writeback_mapping_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dax_writeback_mapping_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int del_timer_sync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int del_timer_sync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int destroy_workqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int destroy_workqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dget_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dget_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int drop_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int drop_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int dump_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int dump_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int end_page_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int end_page_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int fiemap_fill_next_extent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int fiemap_fill_next_extent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int file_check_and_advance_wb_err_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int file_check_and_advance_wb_err_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int file_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int file_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int file_remove_privs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int file_remove_privs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int file_update_time_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int file_update_time_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int file_write_and_wait_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int file_write_and_wait_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int filemap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int filemap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int filemap_flush_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int filemap_flush_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int filemap_write_and_wait_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int filemap_write_and_wait_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int find_inode_nowait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int find_inode_nowait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int flush_workqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int flush_workqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int fput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int fput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int freeze_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int freeze_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int freezing_slow_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int freezing_slow_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int from_kgid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int from_kgid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int from_kgid_munged_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int from_kgid_munged_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int from_kprojid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int from_kprojid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int fs_dax_get_by_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int fs_dax_get_by_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_block_bmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_block_bmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_block_fiemap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_block_fiemap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_check_addressable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_check_addressable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_fh_to_dentry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_fh_to_dentry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_fh_to_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_fh_to_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_file_llseek_size_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_file_llseek_size_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_file_read_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_file_read_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_fillattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_fillattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int generic_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int generic_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int get_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int get_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int grab_cache_page_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int grab_cache_page_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int iget_failed_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int iget_failed_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int iget_locked_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int iget_locked_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int igrab_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int igrab_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int ihold_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int ihold_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int in_group_p_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int in_group_p_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inc_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inc_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int init_special_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int init_special_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int init_timer_key_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int init_timer_key_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int init_wait_entry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int init_wait_entry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int init_wait_var_entry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int init_wait_var_entry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_dio_wait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_dio_wait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_init_once_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_init_once_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_init_owner_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_init_owner_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_needs_sync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_needs_sync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_newsize_ok_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_newsize_ok_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_nohighmem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_nohighmem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_owner_or_capable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_owner_or_capable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int inode_set_flags_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int inode_set_flags_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int insert_inode_locked_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int insert_inode_locked_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int invalidate_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int invalidate_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int invalidate_inode_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int invalidate_inode_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int iomap_seek_data_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int iomap_seek_data_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int iomap_seek_hole_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int iomap_seek_hole_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int iomap_zero_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int iomap_zero_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int iput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int iput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int is_bad_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int is_bad_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int kern_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int kern_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int kstrdup_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int kstrdup_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int kstrndup_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int kstrndup_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int kthread_create_on_node_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int kthread_create_on_node_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int kthread_should_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int kthread_should_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int kthread_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int kthread_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int ktime_get_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int ktime_get_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int ktime_get_real_seconds_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int ktime_get_real_seconds_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int ktime_get_with_offset_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int ktime_get_with_offset_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int ll_rw_block_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int ll_rw_block_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int lock_two_nondirectories_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int lock_two_nondirectories_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int make_bad_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int make_bad_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int make_kgid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int make_kgid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int make_kprojid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int make_kprojid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int make_kuid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int make_kuid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mark_buffer_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mark_buffer_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mark_buffer_dirty_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mark_buffer_dirty_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_destroy_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_destroy_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_entry_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_entry_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_entry_delete_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_entry_delete_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_entry_find_first_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_entry_find_first_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_entry_find_next_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_entry_find_next_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_entry_get_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_entry_get_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mb_cache_entry_touch_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mb_cache_entry_touch_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mnt_drop_write_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mnt_drop_write_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mnt_want_write_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mnt_want_write_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mod_timer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mod_timer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int mount_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int mount_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int new_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int new_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int page_mapped_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int page_mapped_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int page_zero_new_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int page_zero_new_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int pagecache_get_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int pagecache_get_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int pagecache_isize_extended_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int pagecache_isize_extended_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int pagevec_lookup_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int pagevec_lookup_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int parse_options_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int parse_options_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int path_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int path_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int percpu_down_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int percpu_down_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int percpu_free_rwsem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int percpu_free_rwsem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int percpu_up_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int percpu_up_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int posix_acl_alloc_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int posix_acl_alloc_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int posix_acl_chmod_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int posix_acl_chmod_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int posix_acl_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int posix_acl_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int posix_acl_update_mode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int posix_acl_update_mode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int prepare_to_wait_event_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int prepare_to_wait_event_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int printk_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int printk_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int put_dax_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int put_dax_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int queue_work_on_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int queue_work_on_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int read_cache_pages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int read_cache_pages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int redirty_page_for_writepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int redirty_page_for_writepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int register_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int register_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int register_shrinker_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int register_shrinker_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int sb_min_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int sb_min_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int sb_set_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int sb_set_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int seq_escape_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int seq_escape_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int seq_printf_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int seq_printf_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int seq_putc_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int seq_putc_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int seq_puts_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int seq_puts_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int set_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int set_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int set_cached_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int set_cached_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int set_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int set_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int set_task_ioprio_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int set_task_ioprio_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int setattr_copy_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int setattr_copy_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int setattr_prepare_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int setattr_prepare_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int submit_bh_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int submit_bh_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int submit_bio_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int submit_bio_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int submit_bio_wait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int submit_bio_wait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int sync_blockdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int sync_blockdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int sync_dirty_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int sync_dirty_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int sync_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int sync_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int sync_inode_metadata_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int sync_inode_metadata_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int sync_mapping_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int sync_mapping_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int tag_pages_for_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int tag_pages_for_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int thaw_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int thaw_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int touch_atime_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int touch_atime_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int truncate_inode_pages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int truncate_inode_pages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int truncate_inode_pages_final_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int truncate_inode_pages_final_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int truncate_pagecache_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int truncate_pagecache_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int truncate_pagecache_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int truncate_pagecache_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int try_to_free_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int try_to_free_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int try_to_writeback_inodes_sb_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int try_to_writeback_inodes_sb_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int unlock_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int unlock_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int unlock_new_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int unlock_new_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int unlock_two_nondirectories_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int unlock_two_nondirectories_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int unregister_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int unregister_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int vfs_fsync_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int vfs_fsync_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}

static int vfs_setpos_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_KERENL_STACK
        SWITCH_KERNEL_EPT
    }
    return 0;
}
static int vfs_setpos_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {
        SWITCH_EXTENSION_STACK
        SWITCH_EXTENSION_EPT
    }
    return 0;
}



// =========================================================
static int ext4_alloc_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_alloc_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_bmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_bmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_da_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_da_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_da_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_da_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_da_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_da_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_dax_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_dax_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_destroy_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_destroy_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_dir_llseek_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_dir_llseek_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_dir_open_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_dir_open_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_direct_IO_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_direct_IO_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_dirty_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_dirty_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_drop_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_drop_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_evict_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_evict_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_fallocate_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_fallocate_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_fh_to_dentry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_fh_to_dentry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_fh_to_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_fh_to_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_fiemap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_fiemap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_file_getattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_file_getattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_file_mmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_file_mmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_file_open_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_file_open_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_file_read_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_file_read_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_file_write_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_file_write_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_filemap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_filemap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_freeze_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_freeze_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_get_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_get_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_get_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_get_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_ioctl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_ioctl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_iomap_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_iomap_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_iomap_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_iomap_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_listxattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_listxattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_llseek_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_llseek_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_mb_seq_groups_next_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_mb_seq_groups_next_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_mb_seq_groups_show_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_mb_seq_groups_show_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_mb_seq_groups_start_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_mb_seq_groups_start_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_mb_seq_groups_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_mb_seq_groups_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_mount_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_mount_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_nfs_commit_metadata_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_nfs_commit_metadata_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_page_mkwrite_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_page_mkwrite_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_put_super_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_put_super_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_readdir_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_readdir_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_readpage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_readpage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_readpages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_readpages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_release_dir_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_release_dir_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_release_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_release_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_releasepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_releasepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_remount_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_remount_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_set_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_set_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_set_page_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_set_page_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_setattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_setattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_show_options_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_show_options_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_statfs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_statfs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_sync_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_sync_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_sync_fs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_sync_fs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_unfreeze_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_unfreeze_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_write_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_write_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_writepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_writepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}

static int ext4_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    SWITCH_EXTENSION_STACK
    SWITCH_EXTENSION_EPT
    SYNC
    return 0;
}
static int ext4_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    SWITCH_KERENL_STACK
    SWITCH_KERNEL_EPT
    SYNC
    return 0;
}