#include <linux/fs.h>

#include <uapi/linux/ptrace.h>
#include <linux/uaccess.h>
#include <bcc/proto.h>
BPF_STACK_TRACE(stack_traces, 128);
BPF_HASH(calls, int);



int kprobe__I_BDEV(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____bdev_dax_supported(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____bforget(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____bio_add_page(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____blkdev_issue_discard(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____blkdev_issue_zeroout(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____block_write_begin(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____blockdev_direct_IO(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____bread_gfp(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____breadahead_gfp(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____brelse(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____cleancache_get_page(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____cleancache_init_fs(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____fdget(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____filemap_set_wb_err(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____find_get_block(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____generic_file_fsync(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____generic_file_write_iter(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____getblk_gfp(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____init_waitqueue_head(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____lock_buffer(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____mark_inode_dirty(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____mb_cache_entry_free(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____page_symlink(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____pagevec_release(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____percpu_down_read(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____percpu_init_rwsem(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____put_page(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____refrigerator(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____set_page_dirty_buffers(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____set_page_dirty_nobuffers(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____sync_dirty_buffer(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____test_set_page_writeback(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____var_waitqueue(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____wait_on_buffer(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____wake_up(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe____warn_printk(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__add_to_page_cache_lru(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__bdev_read_only(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__bdevname(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__bh_submit_read(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__bh_uptodate_or_lock(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__bio_alloc_bioset(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__bio_devname(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__bio_put(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__blk_finish_plug(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__blk_start_plug(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__blk_status_to_errno(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__blkdev_get_by_dev(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__blkdev_issue_discard(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__blkdev_issue_flush(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__blkdev_put(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__block_commit_write(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__block_invalidatepage(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__block_page_mkwrite(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__block_read_full_page(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__block_write_end(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__capable(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__clean_bdev_aliases(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__clear_inode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__clear_nlink(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__clear_page_dirty_for_io(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__create_empty_buffers(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__crypto_alloc_shash(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__crypto_destroy_tfm(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__crypto_shash_update(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__current_time(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_find_any_alias(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_instantiate(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_instantiate_new(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_make_root(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_obtain_alias(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_path(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_splice_alias(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__d_tmpfile(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dax_finish_sync_fault(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dax_iomap_fault(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dax_iomap_rw(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dax_layout_busy_page(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dax_writeback_mapping_range(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__del_timer_sync(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__destroy_workqueue(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dget_parent(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dput(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__drop_nlink(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__dump_page(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__end_page_writeback(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__fiemap_fill_next_extent(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__file_check_and_advance_wb_err(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__file_path(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__file_remove_privs(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__file_update_time(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__file_write_and_wait_range(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__filemap_fault(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__filemap_flush(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__filemap_write_and_wait_range(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__find_inode_nowait(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__flush_workqueue(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__fput(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__freeze_bdev(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__freezing_slow_path(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__from_kgid(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__from_kgid_munged(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__from_kprojid(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__fs_dax_get_by_bdev(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_block_bmap(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_block_fiemap(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_check_addressable(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_fh_to_dentry(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_fh_to_parent(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_file_llseek_size(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_file_read_iter(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_fillattr(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__generic_write_end(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    // char comm[200];
    // bpf_get_current_comm(&comm, sizeof(comm));
    // int key = stack_traces.get_stackid(ctx, 0);
    // u64 zero = 0, *val;
    // val = calls.lookup_or_try_init(&key, &zero);
    // struct bpf_stacktrace * = stack_traces.
    // for (int i = 0;i < stack_traces.)
    
    
    // bpf_trace_printk("%s  key:%d caller: %lx\n", comm, key, __builtin_return_address(0));
    // bpf_trace_printk("%s  key:%d \n", comm, key);
    
    return 0;
}


int kprobe__generic_writepages(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__get_acl(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__grab_cache_page_write_begin(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__iget_failed(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__iget_locked(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__igrab(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__ihold(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__in_group_p(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inc_nlink(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__init_special_inode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__init_timer_key(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__init_wait_entry(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__init_wait_var_entry(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_dio_wait(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_init_once(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_init_owner(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_needs_sync(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_newsize_ok(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_nohighmem(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_owner_or_capable(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__inode_set_flags(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__insert_inode_locked(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__invalidate_bdev(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__invalidate_inode_buffers(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__iomap_seek_data(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__iomap_seek_hole(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__iomap_zero_range(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__iput(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__is_bad_inode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__kern_path(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__kstrdup(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__kstrndup(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__kthread_create_on_node(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__kthread_should_stop(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__kthread_stop(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__ktime_get(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__ktime_get_real_seconds(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__ktime_get_with_offset(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__ll_rw_block(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__lock_two_nondirectories(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__make_bad_inode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__make_kgid(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__make_kprojid(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__make_kuid(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mark_buffer_dirty(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mark_buffer_dirty_inode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_create(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_destroy(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_entry_create(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_entry_delete(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_entry_find_first(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_entry_find_next(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_entry_get(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mb_cache_entry_touch(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mnt_drop_write_file(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mnt_want_write_file(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mod_timer(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__mount_bdev(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__new_inode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__page_mapped(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__page_zero_new_buffers(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__pagecache_get_page(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__pagecache_isize_extended(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__pagevec_lookup_range(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__parse_options(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__path_put(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__percpu_down_write(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__percpu_free_rwsem(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__percpu_up_write(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__posix_acl_alloc(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__posix_acl_chmod(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__posix_acl_create(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__posix_acl_update_mode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__prepare_to_wait_event(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__printk(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__put_dax(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__queue_work_on(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__read_cache_pages(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__redirty_page_for_writepage(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__register_filesystem(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__register_shrinker(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__sb_min_blocksize(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__sb_set_blocksize(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__seq_escape(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__seq_printf(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__seq_putc(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__seq_puts(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__set_blocksize(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__set_cached_acl(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__set_nlink(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__set_task_ioprio(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__setattr_copy(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__setattr_prepare(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__submit_bh(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__submit_bio(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__submit_bio_wait(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__sync_blockdev(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__sync_dirty_buffer(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__sync_filesystem(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__sync_inode_metadata(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__sync_mapping_buffers(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__tag_pages_for_writeback(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__thaw_bdev(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__touch_atime(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__truncate_inode_pages(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__truncate_inode_pages_final(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__truncate_pagecache(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__truncate_pagecache_range(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__try_to_free_buffers(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__try_to_writeback_inodes_sb(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__unlock_buffer(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__unlock_new_inode(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__unlock_two_nondirectories(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__unregister_filesystem(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__vfs_fsync_range(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}


int kprobe__vfs_setpos(struct pt_regs *ctx) 
{
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    return 0;
}

