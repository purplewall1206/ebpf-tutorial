#include "monitor.h"

DEFINE_PER_CPU(bool, ext4_executing) = false;



static struct kretprobe *fn_kps[240] = {
    	[I_BDEV_PROBE] = &I_BDEV_kp,
	[__BDEV_DAX_SUPPORTED_PROBE] = &__bdev_dax_supported_kp,
	[__BFORGET_PROBE] = &__bforget_kp,
	[__BIO_ADD_PAGE_PROBE] = &__bio_add_page_kp,
	[__BLKDEV_ISSUE_DISCARD_PROBE] = &__blkdev_issue_discard_kp,
	[__BLKDEV_ISSUE_ZEROOUT_PROBE] = &__blkdev_issue_zeroout_kp,
	[__BLOCK_WRITE_BEGIN_PROBE] = &__block_write_begin_kp,
	[__BLOCKDEV_DIRECT_IO_PROBE] = &__blockdev_direct_IO_kp,
	[__BREAD_GFP_PROBE] = &__bread_gfp_kp,
	[__BREADAHEAD_GFP_PROBE] = &__breadahead_gfp_kp,
	[__BRELSE_PROBE] = &__brelse_kp,
	[__CLEANCACHE_GET_PAGE_PROBE] = &__cleancache_get_page_kp,
	[__CLEANCACHE_INIT_FS_PROBE] = &__cleancache_init_fs_kp,
	[__FDGET_PROBE] = &__fdget_kp,
	[__FILEMAP_SET_WB_ERR_PROBE] = &__filemap_set_wb_err_kp,
	[__FIND_GET_BLOCK_PROBE] = &__find_get_block_kp,
	[__GENERIC_FILE_FSYNC_PROBE] = &__generic_file_fsync_kp,
	[__GENERIC_FILE_WRITE_ITER_PROBE] = &__generic_file_write_iter_kp,
	[__GETBLK_GFP_PROBE] = &__getblk_gfp_kp,
	[__INIT_WAITQUEUE_HEAD_PROBE] = &__init_waitqueue_head_kp,
	[__LOCK_BUFFER_PROBE] = &__lock_buffer_kp,
	[__MARK_INODE_DIRTY_PROBE] = &__mark_inode_dirty_kp,
	[__MB_CACHE_ENTRY_FREE_PROBE] = &__mb_cache_entry_free_kp,
	[__PAGE_SYMLINK_PROBE] = &__page_symlink_kp,
	[__PAGEVEC_RELEASE_PROBE] = &__pagevec_release_kp,
	[__PERCPU_DOWN_READ_PROBE] = &__percpu_down_read_kp,
	[__PERCPU_INIT_RWSEM_PROBE] = &__percpu_init_rwsem_kp,
	[__PUT_PAGE_PROBE] = &__put_page_kp,
	[__REFRIGERATOR_PROBE] = &__refrigerator_kp,
	[__SET_PAGE_DIRTY_BUFFERS_PROBE] = &__set_page_dirty_buffers_kp,
	[__SET_PAGE_DIRTY_NOBUFFERS_PROBE] = &__set_page_dirty_nobuffers_kp,
	[__SYNC_DIRTY_BUFFER_PROBE] = &__sync_dirty_buffer_kp,
	[__TEST_SET_PAGE_WRITEBACK_PROBE] = &__test_set_page_writeback_kp,
	[__VAR_WAITQUEUE_PROBE] = &__var_waitqueue_kp,
	[__WAIT_ON_BUFFER_PROBE] = &__wait_on_buffer_kp,
	[__WAKE_UP_PROBE] = &__wake_up_kp,
	[__WARN_PRINTK_PROBE] = &__warn_printk_kp,
	[ADD_TO_PAGE_CACHE_LRU_PROBE] = &add_to_page_cache_lru_kp,
	[BDEV_READ_ONLY_PROBE] = &bdev_read_only_kp,
	[BDEVNAME_PROBE] = &bdevname_kp,
	[BH_SUBMIT_READ_PROBE] = &bh_submit_read_kp,
	[BH_UPTODATE_OR_LOCK_PROBE] = &bh_uptodate_or_lock_kp,
	[BIO_ALLOC_BIOSET_PROBE] = &bio_alloc_bioset_kp,
	[BIO_DEVNAME_PROBE] = &bio_devname_kp,
	[BIO_PUT_PROBE] = &bio_put_kp,
	[BLK_FINISH_PLUG_PROBE] = &blk_finish_plug_kp,
	[BLK_START_PLUG_PROBE] = &blk_start_plug_kp,
	[BLK_STATUS_TO_ERRNO_PROBE] = &blk_status_to_errno_kp,
	[BLKDEV_GET_BY_DEV_PROBE] = &blkdev_get_by_dev_kp,
	[BLKDEV_ISSUE_DISCARD_PROBE] = &blkdev_issue_discard_kp,
	[BLKDEV_ISSUE_FLUSH_PROBE] = &blkdev_issue_flush_kp,
	[BLKDEV_PUT_PROBE] = &blkdev_put_kp,
	[BLOCK_COMMIT_WRITE_PROBE] = &block_commit_write_kp,
	[BLOCK_INVALIDATEPAGE_PROBE] = &block_invalidatepage_kp,
	[BLOCK_PAGE_MKWRITE_PROBE] = &block_page_mkwrite_kp,
	[BLOCK_READ_FULL_PAGE_PROBE] = &block_read_full_page_kp,
	[BLOCK_WRITE_END_PROBE] = &block_write_end_kp,
	[CAPABLE_PROBE] = &capable_kp,
	[CLEAN_BDEV_ALIASES_PROBE] = &clean_bdev_aliases_kp,
	[CLEAR_INODE_PROBE] = &clear_inode_kp,
	[CLEAR_NLINK_PROBE] = &clear_nlink_kp,
	[CLEAR_PAGE_DIRTY_FOR_IO_PROBE] = &clear_page_dirty_for_io_kp,
	[CREATE_EMPTY_BUFFERS_PROBE] = &create_empty_buffers_kp,
	[CRYPTO_ALLOC_SHASH_PROBE] = &crypto_alloc_shash_kp,
	[CRYPTO_DESTROY_TFM_PROBE] = &crypto_destroy_tfm_kp,
	[CRYPTO_SHASH_UPDATE_PROBE] = &crypto_shash_update_kp,
	[CURRENT_TIME_PROBE] = &current_time_kp,
	[D_FIND_ANY_ALIAS_PROBE] = &d_find_any_alias_kp,
	[D_INSTANTIATE_PROBE] = &d_instantiate_kp,
	[D_INSTANTIATE_NEW_PROBE] = &d_instantiate_new_kp,
	[D_MAKE_ROOT_PROBE] = &d_make_root_kp,
	[D_OBTAIN_ALIAS_PROBE] = &d_obtain_alias_kp,
	[D_PATH_PROBE] = &d_path_kp,
	[D_SPLICE_ALIAS_PROBE] = &d_splice_alias_kp,
	[D_TMPFILE_PROBE] = &d_tmpfile_kp,
	[DAX_FINISH_SYNC_FAULT_PROBE] = &dax_finish_sync_fault_kp,
	[DAX_IOMAP_FAULT_PROBE] = &dax_iomap_fault_kp,
	[DAX_IOMAP_RW_PROBE] = &dax_iomap_rw_kp,
	[DAX_LAYOUT_BUSY_PAGE_PROBE] = &dax_layout_busy_page_kp,
	[DAX_WRITEBACK_MAPPING_RANGE_PROBE] = &dax_writeback_mapping_range_kp,
	[DEL_TIMER_SYNC_PROBE] = &del_timer_sync_kp,
	[DESTROY_WORKQUEUE_PROBE] = &destroy_workqueue_kp,
	[DGET_PARENT_PROBE] = &dget_parent_kp,
	[DPUT_PROBE] = &dput_kp,
	[DROP_NLINK_PROBE] = &drop_nlink_kp,
	[DUMP_PAGE_PROBE] = &dump_page_kp,
	[END_PAGE_WRITEBACK_PROBE] = &end_page_writeback_kp,
	[FIEMAP_FILL_NEXT_EXTENT_PROBE] = &fiemap_fill_next_extent_kp,
	[FILE_CHECK_AND_ADVANCE_WB_ERR_PROBE] = &file_check_and_advance_wb_err_kp,
	[FILE_PATH_PROBE] = &file_path_kp,
	[FILE_REMOVE_PRIVS_PROBE] = &file_remove_privs_kp,
	[FILE_UPDATE_TIME_PROBE] = &file_update_time_kp,
	[FILE_WRITE_AND_WAIT_RANGE_PROBE] = &file_write_and_wait_range_kp,
	[FILEMAP_FAULT_PROBE] = &filemap_fault_kp,
	[FILEMAP_FLUSH_PROBE] = &filemap_flush_kp,
	[FILEMAP_WRITE_AND_WAIT_RANGE_PROBE] = &filemap_write_and_wait_range_kp,
	[FIND_INODE_NOWAIT_PROBE] = &find_inode_nowait_kp,
	[FLUSH_WORKQUEUE_PROBE] = &flush_workqueue_kp,
	[FPUT_PROBE] = &fput_kp,
	[FREEZE_BDEV_PROBE] = &freeze_bdev_kp,
	[FREEZING_SLOW_PATH_PROBE] = &freezing_slow_path_kp,
	[FROM_KGID_PROBE] = &from_kgid_kp,
	[FROM_KGID_MUNGED_PROBE] = &from_kgid_munged_kp,
	[FROM_KPROJID_PROBE] = &from_kprojid_kp,
	[FS_DAX_GET_BY_BDEV_PROBE] = &fs_dax_get_by_bdev_kp,
	[GENERIC_BLOCK_BMAP_PROBE] = &generic_block_bmap_kp,
	[GENERIC_BLOCK_FIEMAP_PROBE] = &generic_block_fiemap_kp,
	[GENERIC_CHECK_ADDRESSABLE_PROBE] = &generic_check_addressable_kp,
	[GENERIC_FH_TO_DENTRY_PROBE] = &generic_fh_to_dentry_kp,
	[GENERIC_FH_TO_PARENT_PROBE] = &generic_fh_to_parent_kp,
	[GENERIC_FILE_LLSEEK_SIZE_PROBE] = &generic_file_llseek_size_kp,
	[GENERIC_FILE_READ_ITER_PROBE] = &generic_file_read_iter_kp,
	[GENERIC_FILLATTR_PROBE] = &generic_fillattr_kp,
	[GENERIC_WRITE_END_PROBE] = &generic_write_end_kp,
	[GENERIC_WRITEPAGES_PROBE] = &generic_writepages_kp,
	[GET_ACL_PROBE] = &get_acl_kp,
	[GRAB_CACHE_PAGE_WRITE_BEGIN_PROBE] = &grab_cache_page_write_begin_kp,
	[IGET_FAILED_PROBE] = &iget_failed_kp,
	[IGET_LOCKED_PROBE] = &iget_locked_kp,
	[IGRAB_PROBE] = &igrab_kp,
	[IHOLD_PROBE] = &ihold_kp,
	[IN_GROUP_P_PROBE] = &in_group_p_kp,
	[INC_NLINK_PROBE] = &inc_nlink_kp,
	[INIT_SPECIAL_INODE_PROBE] = &init_special_inode_kp,
	[INIT_TIMER_KEY_PROBE] = &init_timer_key_kp,
	[INIT_WAIT_ENTRY_PROBE] = &init_wait_entry_kp,
	[INIT_WAIT_VAR_ENTRY_PROBE] = &init_wait_var_entry_kp,
	[INODE_DIO_WAIT_PROBE] = &inode_dio_wait_kp,
	[INODE_INIT_ONCE_PROBE] = &inode_init_once_kp,
	[INODE_INIT_OWNER_PROBE] = &inode_init_owner_kp,
	[INODE_NEEDS_SYNC_PROBE] = &inode_needs_sync_kp,
	[INODE_NEWSIZE_OK_PROBE] = &inode_newsize_ok_kp,
	[INODE_NOHIGHMEM_PROBE] = &inode_nohighmem_kp,
	[INODE_OWNER_OR_CAPABLE_PROBE] = &inode_owner_or_capable_kp,
	[INODE_SET_FLAGS_PROBE] = &inode_set_flags_kp,
	[INSERT_INODE_LOCKED_PROBE] = &insert_inode_locked_kp,
	[INVALIDATE_BDEV_PROBE] = &invalidate_bdev_kp,
	[INVALIDATE_INODE_BUFFERS_PROBE] = &invalidate_inode_buffers_kp,
	[IOMAP_SEEK_DATA_PROBE] = &iomap_seek_data_kp,
	[IOMAP_SEEK_HOLE_PROBE] = &iomap_seek_hole_kp,
	[IOMAP_ZERO_RANGE_PROBE] = &iomap_zero_range_kp,
	[IPUT_PROBE] = &iput_kp,
	[IS_BAD_INODE_PROBE] = &is_bad_inode_kp,
	[KERN_PATH_PROBE] = &kern_path_kp,
	[KSTRDUP_PROBE] = &kstrdup_kp,
	[KSTRNDUP_PROBE] = &kstrndup_kp,
	[KTHREAD_CREATE_ON_NODE_PROBE] = &kthread_create_on_node_kp,
	[KTHREAD_SHOULD_STOP_PROBE] = &kthread_should_stop_kp,
	[KTHREAD_STOP_PROBE] = &kthread_stop_kp,
	[KTIME_GET_PROBE] = &ktime_get_kp,
	[KTIME_GET_REAL_SECONDS_PROBE] = &ktime_get_real_seconds_kp,
	[KTIME_GET_WITH_OFFSET_PROBE] = &ktime_get_with_offset_kp,
	[LL_RW_BLOCK_PROBE] = &ll_rw_block_kp,
	[LOCK_TWO_NONDIRECTORIES_PROBE] = &lock_two_nondirectories_kp,
	[MAKE_BAD_INODE_PROBE] = &make_bad_inode_kp,
	[MAKE_KGID_PROBE] = &make_kgid_kp,
	[MAKE_KPROJID_PROBE] = &make_kprojid_kp,
	[MAKE_KUID_PROBE] = &make_kuid_kp,
	[MARK_BUFFER_DIRTY_PROBE] = &mark_buffer_dirty_kp,
	[MARK_BUFFER_DIRTY_INODE_PROBE] = &mark_buffer_dirty_inode_kp,
	[MB_CACHE_CREATE_PROBE] = &mb_cache_create_kp,
	[MB_CACHE_DESTROY_PROBE] = &mb_cache_destroy_kp,
	[MB_CACHE_ENTRY_CREATE_PROBE] = &mb_cache_entry_create_kp,
	[MB_CACHE_ENTRY_DELETE_PROBE] = &mb_cache_entry_delete_kp,
	[MB_CACHE_ENTRY_FIND_FIRST_PROBE] = &mb_cache_entry_find_first_kp,
	[MB_CACHE_ENTRY_FIND_NEXT_PROBE] = &mb_cache_entry_find_next_kp,
	[MB_CACHE_ENTRY_GET_PROBE] = &mb_cache_entry_get_kp,
	[MB_CACHE_ENTRY_TOUCH_PROBE] = &mb_cache_entry_touch_kp,
	[MNT_DROP_WRITE_FILE_PROBE] = &mnt_drop_write_file_kp,
	[MNT_WANT_WRITE_FILE_PROBE] = &mnt_want_write_file_kp,
	[MOD_TIMER_PROBE] = &mod_timer_kp,
	[MOUNT_BDEV_PROBE] = &mount_bdev_kp,
	[NEW_INODE_PROBE] = &new_inode_kp,
	[PAGE_MAPPED_PROBE] = &page_mapped_kp,
	[PAGE_ZERO_NEW_BUFFERS_PROBE] = &page_zero_new_buffers_kp,
	[PAGECACHE_GET_PAGE_PROBE] = &pagecache_get_page_kp,
	[PAGECACHE_ISIZE_EXTENDED_PROBE] = &pagecache_isize_extended_kp,
	[PAGEVEC_LOOKUP_RANGE_PROBE] = &pagevec_lookup_range_kp,
	[PARSE_OPTIONS_PROBE] = &parse_options_kp,
	[PATH_PUT_PROBE] = &path_put_kp,
	[PERCPU_DOWN_WRITE_PROBE] = &percpu_down_write_kp,
	[PERCPU_FREE_RWSEM_PROBE] = &percpu_free_rwsem_kp,
	[PERCPU_UP_WRITE_PROBE] = &percpu_up_write_kp,
	[POSIX_ACL_ALLOC_PROBE] = &posix_acl_alloc_kp,
	[POSIX_ACL_CHMOD_PROBE] = &posix_acl_chmod_kp,
	[POSIX_ACL_CREATE_PROBE] = &posix_acl_create_kp,
	[POSIX_ACL_UPDATE_MODE_PROBE] = &posix_acl_update_mode_kp,
	[PREPARE_TO_WAIT_EVENT_PROBE] = &prepare_to_wait_event_kp,
	[PRINTK_PROBE] = &printk_kp,
	[PUT_DAX_PROBE] = &put_dax_kp,
	[QUEUE_WORK_ON_PROBE] = &queue_work_on_kp,
	[READ_CACHE_PAGES_PROBE] = &read_cache_pages_kp,
	[REDIRTY_PAGE_FOR_WRITEPAGE_PROBE] = &redirty_page_for_writepage_kp,
	[REGISTER_FILESYSTEM_PROBE] = &register_filesystem_kp,
	[REGISTER_SHRINKER_PROBE] = &register_shrinker_kp,
	[SB_MIN_BLOCKSIZE_PROBE] = &sb_min_blocksize_kp,
	[SB_SET_BLOCKSIZE_PROBE] = &sb_set_blocksize_kp,
	[SEQ_ESCAPE_PROBE] = &seq_escape_kp,
	[SEQ_PRINTF_PROBE] = &seq_printf_kp,
	[SEQ_PUTC_PROBE] = &seq_putc_kp,
	[SEQ_PUTS_PROBE] = &seq_puts_kp,
	[SET_BLOCKSIZE_PROBE] = &set_blocksize_kp,
	[SET_CACHED_ACL_PROBE] = &set_cached_acl_kp,
	[SET_NLINK_PROBE] = &set_nlink_kp,
	[SET_TASK_IOPRIO_PROBE] = &set_task_ioprio_kp,
	[SETATTR_COPY_PROBE] = &setattr_copy_kp,
	[SETATTR_PREPARE_PROBE] = &setattr_prepare_kp,
	[SUBMIT_BH_PROBE] = &submit_bh_kp,
	[SUBMIT_BIO_PROBE] = &submit_bio_kp,
	[SUBMIT_BIO_WAIT_PROBE] = &submit_bio_wait_kp,
	[SYNC_BLOCKDEV_PROBE] = &sync_blockdev_kp,
	[SYNC_DIRTY_BUFFER_PROBE] = &sync_dirty_buffer_kp,
	[SYNC_FILESYSTEM_PROBE] = &sync_filesystem_kp,
	[SYNC_INODE_METADATA_PROBE] = &sync_inode_metadata_kp,
	[SYNC_MAPPING_BUFFERS_PROBE] = &sync_mapping_buffers_kp,
	[TAG_PAGES_FOR_WRITEBACK_PROBE] = &tag_pages_for_writeback_kp,
	[THAW_BDEV_PROBE] = &thaw_bdev_kp,
	[TOUCH_ATIME_PROBE] = &touch_atime_kp,
	[TRUNCATE_INODE_PAGES_PROBE] = &truncate_inode_pages_kp,
	[TRUNCATE_INODE_PAGES_FINAL_PROBE] = &truncate_inode_pages_final_kp,
	[TRUNCATE_PAGECACHE_PROBE] = &truncate_pagecache_kp,
	[TRUNCATE_PAGECACHE_RANGE_PROBE] = &truncate_pagecache_range_kp,
	[TRY_TO_FREE_BUFFERS_PROBE] = &try_to_free_buffers_kp,
	[TRY_TO_WRITEBACK_INODES_SB_PROBE] = &try_to_writeback_inodes_sb_kp,
	[UNLOCK_BUFFER_PROBE] = &unlock_buffer_kp,
	[UNLOCK_NEW_INODE_PROBE] = &unlock_new_inode_kp,
	[UNLOCK_TWO_NONDIRECTORIES_PROBE] = &unlock_two_nondirectories_kp,
	[UNREGISTER_FILESYSTEM_PROBE] = &unregister_filesystem_kp,
	[VFS_FSYNC_RANGE_PROBE] = &vfs_fsync_range_kp,
	[VFS_SETPOS_PROBE] = &vfs_setpos_kp,

};

int I_BDEV_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int I_BDEV_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __bdev_dax_supported_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __bdev_dax_supported_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __bforget_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __bforget_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __bio_add_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __bio_add_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __blkdev_issue_discard_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __blkdev_issue_discard_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __blkdev_issue_zeroout_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __blkdev_issue_zeroout_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __block_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __block_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __blockdev_direct_IO_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __blockdev_direct_IO_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __bread_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __bread_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __breadahead_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __breadahead_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __brelse_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __brelse_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __cleancache_get_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __cleancache_get_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __cleancache_init_fs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __cleancache_init_fs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __fdget_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __fdget_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __filemap_set_wb_err_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __filemap_set_wb_err_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __find_get_block_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __find_get_block_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __generic_file_fsync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __generic_file_fsync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __generic_file_write_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __generic_file_write_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __getblk_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __getblk_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __init_waitqueue_head_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __init_waitqueue_head_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __lock_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __lock_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __mark_inode_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __mark_inode_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __mb_cache_entry_free_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __mb_cache_entry_free_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __page_symlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __page_symlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __pagevec_release_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __pagevec_release_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __percpu_down_read_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __percpu_down_read_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __percpu_init_rwsem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __percpu_init_rwsem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __put_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __put_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __refrigerator_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __refrigerator_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __set_page_dirty_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __set_page_dirty_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __set_page_dirty_nobuffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __set_page_dirty_nobuffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __sync_dirty_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __sync_dirty_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __test_set_page_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __test_set_page_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __var_waitqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __var_waitqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __wait_on_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __wait_on_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __wake_up_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __wake_up_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int __warn_printk_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int __warn_printk_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int add_to_page_cache_lru_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int add_to_page_cache_lru_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int bdev_read_only_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int bdev_read_only_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int bdevname_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int bdevname_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int bh_submit_read_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int bh_submit_read_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int bh_uptodate_or_lock_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int bh_uptodate_or_lock_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int bio_alloc_bioset_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int bio_alloc_bioset_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int bio_devname_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int bio_devname_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int bio_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int bio_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int blk_finish_plug_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int blk_finish_plug_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int blk_start_plug_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int blk_start_plug_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int blk_status_to_errno_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int blk_status_to_errno_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int blkdev_get_by_dev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int blkdev_get_by_dev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int blkdev_issue_discard_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int blkdev_issue_discard_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int blkdev_issue_flush_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int blkdev_issue_flush_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int blkdev_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int blkdev_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int block_commit_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int block_commit_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int block_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int block_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int block_page_mkwrite_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int block_page_mkwrite_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int block_read_full_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int block_read_full_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int block_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int block_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int capable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int capable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int clean_bdev_aliases_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int clean_bdev_aliases_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int clear_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int clear_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int clear_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int clear_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int clear_page_dirty_for_io_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int clear_page_dirty_for_io_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int create_empty_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int create_empty_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int crypto_alloc_shash_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int crypto_alloc_shash_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int crypto_destroy_tfm_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int crypto_destroy_tfm_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int crypto_shash_update_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int crypto_shash_update_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int current_time_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int current_time_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_find_any_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_find_any_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_instantiate_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_instantiate_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_instantiate_new_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_instantiate_new_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_make_root_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_make_root_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_obtain_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_obtain_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_splice_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_splice_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int d_tmpfile_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int d_tmpfile_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dax_finish_sync_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dax_finish_sync_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dax_iomap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dax_iomap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dax_iomap_rw_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dax_iomap_rw_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dax_layout_busy_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dax_layout_busy_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dax_writeback_mapping_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dax_writeback_mapping_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int del_timer_sync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int del_timer_sync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int destroy_workqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int destroy_workqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dget_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dget_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int drop_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int drop_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int dump_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int dump_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int end_page_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int end_page_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int fiemap_fill_next_extent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int fiemap_fill_next_extent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int file_check_and_advance_wb_err_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int file_check_and_advance_wb_err_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int file_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int file_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int file_remove_privs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int file_remove_privs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int file_update_time_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int file_update_time_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int file_write_and_wait_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int file_write_and_wait_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int filemap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int filemap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int filemap_flush_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int filemap_flush_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int filemap_write_and_wait_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int filemap_write_and_wait_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int find_inode_nowait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int find_inode_nowait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int flush_workqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int flush_workqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int fput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int fput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int freeze_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int freeze_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int freezing_slow_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int freezing_slow_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int from_kgid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int from_kgid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int from_kgid_munged_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int from_kgid_munged_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int from_kprojid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int from_kprojid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int fs_dax_get_by_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int fs_dax_get_by_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_block_bmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_block_bmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_block_fiemap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_block_fiemap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_check_addressable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_check_addressable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_fh_to_dentry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_fh_to_dentry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_fh_to_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_fh_to_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_file_llseek_size_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_file_llseek_size_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_file_read_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_file_read_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_fillattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_fillattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int generic_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int generic_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int get_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int get_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int grab_cache_page_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int grab_cache_page_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int iget_failed_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int iget_failed_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int iget_locked_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int iget_locked_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int igrab_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int igrab_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int ihold_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int ihold_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int in_group_p_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int in_group_p_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inc_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inc_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int init_special_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int init_special_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int init_timer_key_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int init_timer_key_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int init_wait_entry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int init_wait_entry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int init_wait_var_entry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int init_wait_var_entry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_dio_wait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_dio_wait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_init_once_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_init_once_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_init_owner_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_init_owner_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_needs_sync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_needs_sync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_newsize_ok_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_newsize_ok_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_nohighmem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_nohighmem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_owner_or_capable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_owner_or_capable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int inode_set_flags_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int inode_set_flags_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int insert_inode_locked_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int insert_inode_locked_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int invalidate_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int invalidate_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int invalidate_inode_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int invalidate_inode_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int iomap_seek_data_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int iomap_seek_data_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int iomap_seek_hole_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int iomap_seek_hole_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int iomap_zero_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int iomap_zero_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int iput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int iput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int is_bad_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int is_bad_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int kern_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int kern_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int kstrdup_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int kstrdup_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int kstrndup_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int kstrndup_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int kthread_create_on_node_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int kthread_create_on_node_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int kthread_should_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int kthread_should_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int kthread_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int kthread_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int ktime_get_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int ktime_get_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int ktime_get_real_seconds_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int ktime_get_real_seconds_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int ktime_get_with_offset_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int ktime_get_with_offset_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int ll_rw_block_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int ll_rw_block_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int lock_two_nondirectories_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int lock_two_nondirectories_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int make_bad_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int make_bad_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int make_kgid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int make_kgid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int make_kprojid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int make_kprojid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int make_kuid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int make_kuid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mark_buffer_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mark_buffer_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mark_buffer_dirty_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mark_buffer_dirty_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_destroy_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_destroy_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_entry_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_entry_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_entry_delete_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_entry_delete_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_entry_find_first_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_entry_find_first_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_entry_find_next_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_entry_find_next_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_entry_get_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_entry_get_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mb_cache_entry_touch_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mb_cache_entry_touch_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mnt_drop_write_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mnt_drop_write_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mnt_want_write_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mnt_want_write_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mod_timer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mod_timer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int mount_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int mount_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int new_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int new_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int page_mapped_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int page_mapped_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int page_zero_new_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int page_zero_new_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int pagecache_get_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int pagecache_get_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int pagecache_isize_extended_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int pagecache_isize_extended_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int pagevec_lookup_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int pagevec_lookup_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int parse_options_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int parse_options_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int path_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int path_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int percpu_down_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int percpu_down_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int percpu_free_rwsem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int percpu_free_rwsem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int percpu_up_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int percpu_up_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int posix_acl_alloc_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int posix_acl_alloc_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int posix_acl_chmod_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int posix_acl_chmod_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int posix_acl_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int posix_acl_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int posix_acl_update_mode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int posix_acl_update_mode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int prepare_to_wait_event_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int prepare_to_wait_event_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int printk_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int printk_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int put_dax_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int put_dax_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int queue_work_on_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int queue_work_on_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int read_cache_pages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int read_cache_pages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int redirty_page_for_writepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int redirty_page_for_writepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int register_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int register_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int register_shrinker_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int register_shrinker_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int sb_min_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int sb_min_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int sb_set_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int sb_set_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int seq_escape_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int seq_escape_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int seq_printf_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int seq_printf_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int seq_putc_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int seq_putc_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int seq_puts_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int seq_puts_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int set_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int set_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int set_cached_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int set_cached_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int set_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int set_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int set_task_ioprio_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int set_task_ioprio_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int setattr_copy_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int setattr_copy_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int setattr_prepare_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int setattr_prepare_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int submit_bh_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int submit_bh_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int submit_bio_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int submit_bio_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int submit_bio_wait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int submit_bio_wait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int sync_blockdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int sync_blockdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int sync_dirty_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int sync_dirty_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int sync_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int sync_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int sync_inode_metadata_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int sync_inode_metadata_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int sync_mapping_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int sync_mapping_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int tag_pages_for_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int tag_pages_for_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int thaw_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int thaw_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int touch_atime_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int touch_atime_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int truncate_inode_pages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int truncate_inode_pages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int truncate_inode_pages_final_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int truncate_inode_pages_final_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int truncate_pagecache_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int truncate_pagecache_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int truncate_pagecache_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int truncate_pagecache_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int try_to_free_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int try_to_free_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int try_to_writeback_inodes_sb_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int try_to_writeback_inodes_sb_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int unlock_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int unlock_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int unlock_new_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int unlock_new_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int unlock_two_nondirectories_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int unlock_two_nondirectories_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int unregister_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int unregister_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int vfs_fsync_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int vfs_fsync_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

int vfs_setpos_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int vfs_setpos_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}

// --------------------------------------------------------------------------------------------


static struct kretprobe *fp_kps[70] = {
    	[EXT4_ALLOC_INODE_PROBE] = &ext4_alloc_inode_kp,
	[EXT4_BMAP_PROBE] = &ext4_bmap_kp,
	[EXT4_DA_INVALIDATEPAGE_PROBE] = &ext4_da_invalidatepage_kp,
	[EXT4_DA_WRITE_BEGIN_PROBE] = &ext4_da_write_begin_kp,
	[EXT4_DA_WRITE_END_PROBE] = &ext4_da_write_end_kp,
	[EXT4_DAX_WRITEPAGES_PROBE] = &ext4_dax_writepages_kp,
	[EXT4_DESTROY_INODE_PROBE] = &ext4_destroy_inode_kp,
	[EXT4_DIR_LLSEEK_PROBE] = &ext4_dir_llseek_kp,
	[EXT4_DIR_OPEN_PROBE] = &ext4_dir_open_kp,
	[EXT4_DIRECT_IO_PROBE] = &ext4_direct_IO_kp,
	[EXT4_DIRTY_INODE_PROBE] = &ext4_dirty_inode_kp,
	[EXT4_DROP_INODE_PROBE] = &ext4_drop_inode_kp,
	[EXT4_EVICT_INODE_PROBE] = &ext4_evict_inode_kp,
	[EXT4_FALLOCATE_PROBE] = &ext4_fallocate_kp,
	[EXT4_FH_TO_DENTRY_PROBE] = &ext4_fh_to_dentry_kp,
	[EXT4_FH_TO_PARENT_PROBE] = &ext4_fh_to_parent_kp,
	[EXT4_FIEMAP_PROBE] = &ext4_fiemap_kp,
	[EXT4_FILE_GETATTR_PROBE] = &ext4_file_getattr_kp,
	[EXT4_FILE_MMAP_PROBE] = &ext4_file_mmap_kp,
	[EXT4_FILE_OPEN_PROBE] = &ext4_file_open_kp,
	[EXT4_FILE_READ_ITER_PROBE] = &ext4_file_read_iter_kp,
	[EXT4_FILE_WRITE_ITER_PROBE] = &ext4_file_write_iter_kp,
	[EXT4_FILEMAP_FAULT_PROBE] = &ext4_filemap_fault_kp,
	[EXT4_FREEZE_PROBE] = &ext4_freeze_kp,
	[EXT4_GET_ACL_PROBE] = &ext4_get_acl_kp,
	[EXT4_GET_PARENT_PROBE] = &ext4_get_parent_kp,
	[EXT4_INVALIDATEPAGE_PROBE] = &ext4_invalidatepage_kp,
	[EXT4_IOCTL_PROBE] = &ext4_ioctl_kp,
	[EXT4_IOMAP_BEGIN_PROBE] = &ext4_iomap_begin_kp,
	[EXT4_IOMAP_END_PROBE] = &ext4_iomap_end_kp,
	[EXT4_LISTXATTR_PROBE] = &ext4_listxattr_kp,
	[EXT4_LLSEEK_PROBE] = &ext4_llseek_kp,
	[EXT4_MB_SEQ_GROUPS_NEXT_PROBE] = &ext4_mb_seq_groups_next_kp,
	[EXT4_MB_SEQ_GROUPS_SHOW_PROBE] = &ext4_mb_seq_groups_show_kp,
	[EXT4_MB_SEQ_GROUPS_START_PROBE] = &ext4_mb_seq_groups_start_kp,
	[EXT4_MB_SEQ_GROUPS_STOP_PROBE] = &ext4_mb_seq_groups_stop_kp,
	[EXT4_MOUNT_PROBE] = &ext4_mount_kp,
	[EXT4_NFS_COMMIT_METADATA_PROBE] = &ext4_nfs_commit_metadata_kp,
	[EXT4_PAGE_MKWRITE_PROBE] = &ext4_page_mkwrite_kp,
	[EXT4_PUT_SUPER_PROBE] = &ext4_put_super_kp,
	[EXT4_READDIR_PROBE] = &ext4_readdir_kp,
	[EXT4_READPAGE_PROBE] = &ext4_readpage_kp,
	[EXT4_READPAGES_PROBE] = &ext4_readpages_kp,
	[EXT4_RELEASE_DIR_PROBE] = &ext4_release_dir_kp,
	[EXT4_RELEASE_FILE_PROBE] = &ext4_release_file_kp,
	[EXT4_RELEASEPAGE_PROBE] = &ext4_releasepage_kp,
	[EXT4_REMOUNT_PROBE] = &ext4_remount_kp,
	[EXT4_SET_ACL_PROBE] = &ext4_set_acl_kp,
	[EXT4_SET_PAGE_DIRTY_PROBE] = &ext4_set_page_dirty_kp,
	[EXT4_SETATTR_PROBE] = &ext4_setattr_kp,
	[EXT4_SHOW_OPTIONS_PROBE] = &ext4_show_options_kp,
	[EXT4_STATFS_PROBE] = &ext4_statfs_kp,
	[EXT4_SYNC_FILE_PROBE] = &ext4_sync_file_kp,
	[EXT4_SYNC_FS_PROBE] = &ext4_sync_fs_kp,
	[EXT4_UNFREEZE_PROBE] = &ext4_unfreeze_kp,
	[EXT4_WRITE_BEGIN_PROBE] = &ext4_write_begin_kp,
	[EXT4_WRITE_END_PROBE] = &ext4_write_end_kp,
	[EXT4_WRITE_INODE_PROBE] = &ext4_write_inode_kp,
	[EXT4_WRITEPAGE_PROBE] = &ext4_writepage_kp,
	[EXT4_WRITEPAGES_PROBE] = &ext4_writepages_kp,

};

int ext4_alloc_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_alloc_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_bmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_bmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_da_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_da_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_da_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_da_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_da_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_da_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_dax_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_dax_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_destroy_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_destroy_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_dir_llseek_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_dir_llseek_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_dir_open_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_dir_open_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_direct_IO_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_direct_IO_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_dirty_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_dirty_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_drop_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_drop_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_evict_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_evict_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_fallocate_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_fallocate_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_fh_to_dentry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_fh_to_dentry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_fh_to_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_fh_to_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_fiemap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_fiemap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_file_getattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_file_getattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_file_mmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_file_mmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_file_open_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_file_open_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_file_read_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_file_read_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_file_write_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_file_write_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_filemap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_filemap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_freeze_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_freeze_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_get_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_get_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_get_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_get_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_ioctl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_ioctl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_iomap_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_iomap_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_iomap_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_iomap_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_listxattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_listxattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_llseek_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_llseek_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_mb_seq_groups_next_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_mb_seq_groups_next_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_mb_seq_groups_show_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_mb_seq_groups_show_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_mb_seq_groups_start_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_mb_seq_groups_start_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_mb_seq_groups_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_mb_seq_groups_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_mount_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_mount_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_nfs_commit_metadata_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_nfs_commit_metadata_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_page_mkwrite_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_page_mkwrite_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_put_super_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_put_super_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_readdir_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_readdir_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_readpage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_readpage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_readpages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_readpages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_release_dir_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_release_dir_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_release_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_release_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_releasepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_releasepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_remount_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_remount_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_set_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_set_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_set_page_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_set_page_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_setattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_setattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_show_options_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_show_options_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_statfs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_statfs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_sync_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_sync_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_sync_fs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_sync_fs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_unfreeze_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_unfreeze_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_write_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_write_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_writepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_writepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

int ext4_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int ext4_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}

