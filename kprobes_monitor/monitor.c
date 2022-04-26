#include "monitor.h"

unsigned long count = 0;
static int ext4_monitor(struct kprobe *p, struct pt_regs *regs)
{
    char name_sym[100];
    if (++count % 10000 != 0)
        return 0;

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

static int __init kprobe_init(void)
{
    int ret;
    // kp.pre_handler = handler_pre;//---------------------------------------------------初始化kp的三个回调函数。
    // kp.post_handler = handler_post;
    // kp.fault_handler = handler_fault;

    ret = register_kprobes(kps, 230);//-----------------------------------------------------注册kp探测点到内核。
    if (ret < 0) {
        pr_err("register_kprobe failed, returned %d\n", ret);
        return ret;
    }
    pr_info("Planted kprobe at %pF\n", kps);
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
    unregister_kprobes(kps, 230);
    pr_info("kprobe at %pF unregistered\n", kps);
}

module_init(kprobe_init)
module_exit(kprobe_exit)
MODULE_LICENSE("GPL");


// ------------------------------------------------

int I_BDEV_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __bdev_dax_supported_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __bforget_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __bio_add_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __blkdev_issue_discard_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __blkdev_issue_zeroout_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __block_write_begin_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __blockdev_direct_IO_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __bread_gfp_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __breadahead_gfp_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __brelse_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __cleancache_get_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __cleancache_init_fs_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __fdget_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __filemap_set_wb_err_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __find_get_block_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __generic_file_fsync_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __generic_file_write_iter_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __getblk_gfp_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __init_waitqueue_head_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __lock_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __mark_inode_dirty_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __mb_cache_entry_free_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __page_symlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __pagevec_release_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __percpu_down_read_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __percpu_init_rwsem_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __put_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __refrigerator_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __set_page_dirty_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __set_page_dirty_nobuffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __sync_dirty_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __test_set_page_writeback_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __var_waitqueue_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __wait_on_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __wake_up_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int __warn_printk_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int add_to_page_cache_lru_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int bdev_read_only_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int bdevname_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int bh_submit_read_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int bh_uptodate_or_lock_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int bio_alloc_bioset_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int bio_devname_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int bio_put_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int blk_finish_plug_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int blk_start_plug_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int blk_status_to_errno_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int blkdev_get_by_dev_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int blkdev_issue_discard_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int blkdev_issue_flush_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int blkdev_put_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int block_commit_write_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int block_invalidatepage_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int block_page_mkwrite_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int block_read_full_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int block_write_end_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int capable_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int clean_bdev_aliases_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int clear_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int clear_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int clear_page_dirty_for_io_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int create_empty_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int crypto_alloc_shash_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int crypto_destroy_tfm_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int crypto_shash_update_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int current_time_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_find_any_alias_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_instantiate_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_instantiate_new_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_make_root_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_obtain_alias_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_splice_alias_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int d_tmpfile_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dax_finish_sync_fault_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dax_iomap_fault_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dax_iomap_rw_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dax_layout_busy_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dax_writeback_mapping_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int del_timer_sync_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int destroy_workqueue_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dget_parent_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dput_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int drop_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int dump_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int end_page_writeback_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int fiemap_fill_next_extent_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int file_check_and_advance_wb_err_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int file_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int file_remove_privs_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int file_update_time_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int file_write_and_wait_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int filemap_fault_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int filemap_flush_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int filemap_write_and_wait_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int find_inode_nowait_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int flush_workqueue_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int fput_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int freeze_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int freezing_slow_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int from_kgid_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int from_kgid_munged_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int from_kprojid_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int fs_dax_get_by_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_block_bmap_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_block_fiemap_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_check_addressable_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_fh_to_dentry_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_fh_to_parent_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_file_llseek_size_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_file_read_iter_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    char name_sym[100];
    pr_info("<%s> pre_handler: p->addr = %pF, ip = %lx, flags = 0x%lx\n",
        p->symbol_name, p->addr, regs->ip, regs->flags);
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_fillattr_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_write_end_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int generic_writepages_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int get_acl_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int grab_cache_page_write_begin_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int iget_failed_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int iget_locked_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int igrab_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int ihold_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int in_group_p_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inc_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int init_special_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int init_timer_key_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int init_wait_entry_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int init_wait_var_entry_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_dio_wait_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_init_once_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_init_owner_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_needs_sync_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_newsize_ok_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_nohighmem_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_owner_or_capable_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int inode_set_flags_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int insert_inode_locked_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int invalidate_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int invalidate_inode_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int iomap_seek_data_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int iomap_seek_hole_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int iomap_zero_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int iput_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int is_bad_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int kern_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int kstrdup_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int kstrndup_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int kthread_create_on_node_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int kthread_should_stop_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int kthread_stop_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int ktime_get_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int ktime_get_real_seconds_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int ktime_get_with_offset_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int ll_rw_block_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int lock_two_nondirectories_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int make_bad_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int make_kgid_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int make_kprojid_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int make_kuid_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mark_buffer_dirty_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mark_buffer_dirty_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_create_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_destroy_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_entry_create_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_entry_delete_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_entry_find_first_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_entry_find_next_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_entry_get_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mb_cache_entry_touch_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mnt_drop_write_file_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mnt_want_write_file_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mod_timer_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int mount_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int new_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int page_mapped_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int page_zero_new_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int pagecache_get_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int pagecache_isize_extended_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int pagevec_lookup_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int parse_options_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int path_put_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int percpu_down_write_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int percpu_free_rwsem_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int percpu_up_write_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int posix_acl_alloc_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int posix_acl_chmod_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int posix_acl_create_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int posix_acl_update_mode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int prepare_to_wait_event_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int printk_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int put_dax_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int queue_work_on_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int read_cache_pages_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int redirty_page_for_writepage_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int register_filesystem_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int register_shrinker_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int sb_min_blocksize_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int sb_set_blocksize_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int seq_escape_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int seq_printf_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int seq_putc_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int seq_puts_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int set_blocksize_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int set_cached_acl_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int set_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int set_task_ioprio_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int setattr_copy_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int setattr_prepare_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int submit_bh_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int submit_bio_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int submit_bio_wait_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int sync_blockdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int sync_dirty_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int sync_filesystem_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int sync_inode_metadata_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int sync_mapping_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int tag_pages_for_writeback_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int thaw_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int touch_atime_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int truncate_inode_pages_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int truncate_inode_pages_final_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int truncate_pagecache_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int truncate_pagecache_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int try_to_free_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int try_to_writeback_inodes_sb_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int unlock_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int unlock_new_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int unlock_two_nondirectories_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int unregister_filesystem_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int vfs_fsync_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

int vfs_setpos_ext4_monitor(struct kprobe *p, struct pt_regs *regs) 
{
    if (!is_called_by_ext4()) 
        return 0;
    
    return 0;
}

