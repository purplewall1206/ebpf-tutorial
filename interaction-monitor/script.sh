echo "===================================="
echo I_BDEV
sudo bpftrace -l | grep I_BDEV
echo "===================================="
echo "===================================="
echo __bforget
sudo bpftrace -l | grep __bforget
echo "===================================="
echo "===================================="
echo __block_write_begin
sudo bpftrace -l | grep __block_write_begin
echo "===================================="
echo "===================================="
echo __blockdev_direct_IO
sudo bpftrace -l | grep __blockdev_direct_IO
echo "===================================="
echo "===================================="
echo __bread_gfp
sudo bpftrace -l | grep __bread_gfp
echo "===================================="
echo "===================================="
echo __breadahead_gfp
sudo bpftrace -l | grep __breadahead_gfp
echo "===================================="
echo "===================================="
echo __brelse
sudo bpftrace -l | grep __brelse
echo "===================================="
echo "===================================="
echo __fdget
sudo bpftrace -l | grep __fdget
echo "===================================="
echo "===================================="
echo __find_get_block
sudo bpftrace -l | grep __find_get_block
echo "===================================="
echo "===================================="
echo __generic_file_fsync
sudo bpftrace -l | grep __generic_file_fsync
echo "===================================="
echo "===================================="
echo __getblk_gfp
sudo bpftrace -l | grep __getblk_gfp
echo "===================================="
echo "===================================="
echo __lock_buffer
sudo bpftrace -l | grep __lock_buffer
echo "===================================="
echo "===================================="
echo __mark_inode_dirty
sudo bpftrace -l | grep __mark_inode_dirty
echo "===================================="
echo "===================================="
echo __mb_cache_entry_free
sudo bpftrace -l | grep __mb_cache_entry_free
echo "===================================="
echo "===================================="
echo __page_symlink
sudo bpftrace -l | grep __page_symlink
echo "===================================="
echo "===================================="
echo __sb_end_write
sudo bpftrace -l | grep __sb_end_write
echo "===================================="
echo "===================================="
echo __sb_start_write
sudo bpftrace -l | grep __sb_start_write
echo "===================================="
echo "===================================="
echo __set_page_dirty_buffers
sudo bpftrace -l | grep __set_page_dirty_buffers
echo "===================================="
echo "===================================="
echo __sync_dirty_buffer
sudo bpftrace -l | grep __sync_dirty_buffer
echo "===================================="
echo "===================================="
echo __wait_on_buffer
sudo bpftrace -l | grep __wait_on_buffer
echo "===================================="
echo "===================================="
echo bh_submit_read
sudo bpftrace -l | grep bh_submit_read
echo "===================================="
echo "===================================="
echo bh_uptodate_or_lock
sudo bpftrace -l | grep bh_uptodate_or_lock
echo "===================================="
echo "===================================="
echo blkdev_get_by_dev
sudo bpftrace -l | grep blkdev_get_by_dev
echo "===================================="
echo "===================================="
echo blkdev_put
sudo bpftrace -l | grep blkdev_put
echo "===================================="
echo "===================================="
echo block_commit_write
sudo bpftrace -l | grep block_commit_write
echo "===================================="
echo "===================================="
echo block_invalidatepage
sudo bpftrace -l | grep block_invalidatepage
echo "===================================="
echo "===================================="
echo block_page_mkwrite
sudo bpftrace -l | grep block_page_mkwrite
echo "===================================="
echo "===================================="
echo block_read_full_page
sudo bpftrace -l | grep block_read_full_page
echo "===================================="
echo "===================================="
echo block_write_end
sudo bpftrace -l | grep block_write_end
echo "===================================="
echo "===================================="
echo clean_bdev_aliases
sudo bpftrace -l | grep clean_bdev_aliases
echo "===================================="
echo "===================================="
echo clear_inode
sudo bpftrace -l | grep clear_inode
echo "===================================="
echo "===================================="
echo clear_nlink
sudo bpftrace -l | grep clear_nlink
echo "===================================="
echo "===================================="
echo create_empty_buffers
sudo bpftrace -l | grep create_empty_buffers
echo "===================================="
echo "===================================="
echo current_time
sudo bpftrace -l | grep current_time
echo "===================================="
echo "===================================="
echo d_find_any_alias
sudo bpftrace -l | grep d_find_any_alias
echo "===================================="
echo "===================================="
echo d_instantiate
sudo bpftrace -l | grep d_instantiate
echo "===================================="
echo "===================================="
echo d_instantiate_new
sudo bpftrace -l | grep d_instantiate_new
echo "===================================="
echo "===================================="
echo d_make_root
sudo bpftrace -l | grep d_make_root
echo "===================================="
echo "===================================="
echo d_obtain_alias
sudo bpftrace -l | grep d_obtain_alias
echo "===================================="
echo "===================================="
echo d_path
sudo bpftrace -l | grep d_path
echo "===================================="
echo "===================================="
echo d_splice_alias
sudo bpftrace -l | grep d_splice_alias
echo "===================================="
echo "===================================="
echo d_tmpfile
sudo bpftrace -l | grep d_tmpfile
echo "===================================="
echo "===================================="
echo dax_finish_sync_fault
sudo bpftrace -l | grep dax_finish_sync_fault
echo "===================================="
echo "===================================="
echo dax_iomap_fault
sudo bpftrace -l | grep dax_iomap_fault
echo "===================================="
echo "===================================="
echo dax_iomap_rw
sudo bpftrace -l | grep dax_iomap_rw
echo "===================================="
echo "===================================="
echo dax_layout_busy_page
sudo bpftrace -l | grep dax_layout_busy_page
echo "===================================="
echo "===================================="
echo dax_writeback_mapping_range
sudo bpftrace -l | grep dax_writeback_mapping_range
echo "===================================="
echo "===================================="
echo dget_parent
sudo bpftrace -l | grep dget_parent
echo "===================================="
echo "===================================="
echo dput
sudo bpftrace -l | grep dput
echo "===================================="
echo "===================================="
echo drop_nlink
sudo bpftrace -l | grep drop_nlink
echo "===================================="
echo "===================================="
echo fiemap_check_flags
sudo bpftrace -l | grep fiemap_check_flags
echo "===================================="
echo "===================================="
echo fiemap_fill_next_extent
sudo bpftrace -l | grep fiemap_fill_next_extent
echo "===================================="
echo "===================================="
echo file_path
sudo bpftrace -l | grep file_path
echo "===================================="
echo "===================================="
echo file_remove_privs
sudo bpftrace -l | grep file_remove_privs
echo "===================================="
echo "===================================="
echo file_update_time
sudo bpftrace -l | grep file_update_time
echo "===================================="
echo "===================================="
echo find_inode_nowait
sudo bpftrace -l | grep find_inode_nowait
echo "===================================="
echo "===================================="
echo fput
sudo bpftrace -l | grep fput
echo "===================================="
echo "===================================="
echo freeze_bdev
sudo bpftrace -l | grep freeze_bdev
echo "===================================="
echo "===================================="
echo generic_block_bmap
sudo bpftrace -l | grep generic_block_bmap
echo "===================================="
echo "===================================="
echo generic_block_fiemap
sudo bpftrace -l | grep generic_block_fiemap
echo "===================================="
echo "===================================="
echo generic_check_addressable
sudo bpftrace -l | grep generic_check_addressable
echo "===================================="
echo "===================================="
echo generic_fh_to_dentry
sudo bpftrace -l | grep generic_fh_to_dentry
echo "===================================="
echo "===================================="
echo generic_fh_to_parent
sudo bpftrace -l | grep generic_fh_to_parent
echo "===================================="
echo "===================================="
echo generic_file_llseek_size
sudo bpftrace -l | grep generic_file_llseek_size
echo "===================================="
echo "===================================="
echo generic_fillattr
sudo bpftrace -l | grep generic_fillattr
echo "===================================="
echo "===================================="
echo generic_write_end
sudo bpftrace -l | grep generic_write_end
echo "===================================="
echo "===================================="
echo get_acl
sudo bpftrace -l | grep get_acl
echo "===================================="
echo "===================================="
echo iget_failed
sudo bpftrace -l | grep iget_failed
echo "===================================="
echo "===================================="
echo iget_locked
sudo bpftrace -l | grep iget_locked
echo "===================================="
echo "===================================="
echo igrab
sudo bpftrace -l | grep igrab
echo "===================================="
echo "===================================="
echo ihold
sudo bpftrace -l | grep ihold
echo "===================================="
echo "===================================="
echo inc_nlink
sudo bpftrace -l | grep inc_nlink
echo "===================================="
echo "===================================="
echo init_special_inode
sudo bpftrace -l | grep init_special_inode
echo "===================================="
echo "===================================="
echo inode_dio_wait
sudo bpftrace -l | grep inode_dio_wait
echo "===================================="
echo "===================================="
echo inode_init_once
sudo bpftrace -l | grep inode_init_once
echo "===================================="
echo "===================================="
echo inode_init_owner
sudo bpftrace -l | grep inode_init_owner
echo "===================================="
echo "===================================="
echo inode_needs_sync
sudo bpftrace -l | grep inode_needs_sync
echo "===================================="
echo "===================================="
echo inode_newsize_ok
sudo bpftrace -l | grep inode_newsize_ok
echo "===================================="
echo "===================================="
echo inode_nohighmem
sudo bpftrace -l | grep inode_nohighmem
echo "===================================="
echo "===================================="
echo inode_owner_or_capable
sudo bpftrace -l | grep inode_owner_or_capable
echo "===================================="
echo "===================================="
echo inode_set_flags
sudo bpftrace -l | grep inode_set_flags
echo "===================================="
echo "===================================="
echo insert_inode_locked
sudo bpftrace -l | grep insert_inode_locked
echo "===================================="
echo "===================================="
echo invalidate_bdev
sudo bpftrace -l | grep invalidate_bdev
echo "===================================="
echo "===================================="
echo invalidate_inode_buffers
sudo bpftrace -l | grep invalidate_inode_buffers
echo "===================================="
echo "===================================="
echo iomap_seek_data
sudo bpftrace -l | grep iomap_seek_data
echo "===================================="
echo "===================================="
echo iomap_seek_hole
sudo bpftrace -l | grep iomap_seek_hole
echo "===================================="
echo "===================================="
echo iomap_zero_range
sudo bpftrace -l | grep iomap_zero_range
echo "===================================="
echo "===================================="
echo iput
sudo bpftrace -l | grep iput
echo "===================================="
echo "===================================="
echo is_bad_inode
sudo bpftrace -l | grep is_bad_inode
echo "===================================="
echo "===================================="
echo kern_path
sudo bpftrace -l | grep kern_path
echo "===================================="
echo "===================================="
echo ll_rw_block
sudo bpftrace -l | grep ll_rw_block
echo "===================================="
echo "===================================="
echo lock_two_nondirectories
sudo bpftrace -l | grep lock_two_nondirectories
echo "===================================="
echo "===================================="
echo make_bad_inode
sudo bpftrace -l | grep make_bad_inode
echo "===================================="
echo "===================================="
echo mark_buffer_dirty
sudo bpftrace -l | grep mark_buffer_dirty
echo "===================================="
echo "===================================="
echo mark_buffer_dirty_inode
sudo bpftrace -l | grep mark_buffer_dirty_inode
echo "===================================="
echo "===================================="
echo mb_cache_create
sudo bpftrace -l | grep mb_cache_create
echo "===================================="
echo "===================================="
echo mb_cache_destroy
sudo bpftrace -l | grep mb_cache_destroy
echo "===================================="
echo "===================================="
echo mb_cache_entry_create
sudo bpftrace -l | grep mb_cache_entry_create
echo "===================================="
echo "===================================="
echo mb_cache_entry_delete
sudo bpftrace -l | grep mb_cache_entry_delete
echo "===================================="
echo "===================================="
echo mb_cache_entry_find_first
sudo bpftrace -l | grep mb_cache_entry_find_first
echo "===================================="
echo "===================================="
echo mb_cache_entry_find_next
sudo bpftrace -l | grep mb_cache_entry_find_next
echo "===================================="
echo "===================================="
echo mb_cache_entry_get
sudo bpftrace -l | grep mb_cache_entry_get
echo "===================================="
echo "===================================="
echo mb_cache_entry_touch
sudo bpftrace -l | grep mb_cache_entry_touch
echo "===================================="
echo "===================================="
echo mnt_drop_write_file
sudo bpftrace -l | grep mnt_drop_write_file
echo "===================================="
echo "===================================="
echo mnt_want_write_file
sudo bpftrace -l | grep mnt_want_write_file
echo "===================================="
echo "===================================="
echo mount_bdev
sudo bpftrace -l | grep mount_bdev
echo "===================================="
echo "===================================="
echo new_inode
sudo bpftrace -l | grep new_inode
echo "===================================="
echo "===================================="
echo page_zero_new_buffers
sudo bpftrace -l | grep page_zero_new_buffers
echo "===================================="
echo "===================================="
echo path_put
sudo bpftrace -l | grep path_put
echo "===================================="
echo "===================================="
echo posix_acl_alloc
sudo bpftrace -l | grep posix_acl_alloc
echo "===================================="
echo "===================================="
echo posix_acl_chmod
sudo bpftrace -l | grep posix_acl_chmod
echo "===================================="
echo "===================================="
echo posix_acl_create
sudo bpftrace -l | grep posix_acl_create
echo "===================================="
echo "===================================="
echo posix_acl_update_mode
sudo bpftrace -l | grep posix_acl_update_mode
echo "===================================="
echo "===================================="
echo register_filesystem
sudo bpftrace -l | grep register_filesystem
echo "===================================="
echo "===================================="
echo sb_min_blocksize
sudo bpftrace -l | grep sb_min_blocksize
echo "===================================="
echo "===================================="
echo sb_set_blocksize
sudo bpftrace -l | grep sb_set_blocksize
echo "===================================="
echo "===================================="
echo seq_escape
sudo bpftrace -l | grep seq_escape
echo "===================================="
echo "===================================="
echo seq_printf
sudo bpftrace -l | grep seq_printf
echo "===================================="
echo "===================================="
echo seq_putc
sudo bpftrace -l | grep seq_putc
echo "===================================="
echo "===================================="
echo seq_puts
sudo bpftrace -l | grep seq_puts
echo "===================================="
echo "===================================="
echo set_blocksize
sudo bpftrace -l | grep set_blocksize
echo "===================================="



# echo "===================================="
# echo set_cached_acl
# sudo bpftrace -l | grep set_cached_acl
# echo "===================================="
# echo "===================================="
# echo set_nlink
# sudo bpftrace -l | grep set_nlink
# echo "===================================="
# echo "===================================="
# echo setattr_copy
# sudo bpftrace -l | grep setattr_copy
# echo "===================================="
# echo "===================================="
# echo setattr_prepare
# sudo bpftrace -l | grep setattr_prepare
# echo "===================================="
# echo "===================================="
# echo submit_bh
# sudo bpftrace -l | grep submit_bh
# echo "===================================="
# echo "===================================="
# echo sync_blockdev
# sudo bpftrace -l | grep sync_blockdev
# echo "===================================="
# echo "===================================="
# echo sync_dirty_buffer
# sudo bpftrace -l | grep sync_dirty_buffer
# echo "===================================="
# echo "===================================="
# echo sync_filesystem
# sudo bpftrace -l | grep sync_filesystem
# echo "===================================="
# echo "===================================="
# echo sync_inode_metadata
# sudo bpftrace -l | grep sync_inode_metadata
# echo "===================================="
# echo "===================================="
# echo sync_mapping_buffers
# sudo bpftrace -l | grep sync_mapping_buffers
# echo "===================================="
# echo "===================================="
# echo thaw_bdev
# sudo bpftrace -l | grep thaw_bdev
# echo "===================================="
# echo "===================================="
# echo touch_atime
# sudo bpftrace -l | grep touch_atime
# echo "===================================="
# echo "===================================="
# echo try_to_free_buffers
# sudo bpftrace -l | grep try_to_free_buffers
# echo "===================================="
# echo "===================================="
# echo try_to_writeback_inodes_sb
# sudo bpftrace -l | grep try_to_writeback_inodes_sb
# echo "===================================="
# echo "===================================="
# echo unlock_buffer
# sudo bpftrace -l | grep unlock_buffer
# echo "===================================="
# echo "===================================="
# echo unlock_new_inode
# sudo bpftrace -l | grep unlock_new_inode
# echo "===================================="
# echo "===================================="
# echo unlock_two_nondirectories
# sudo bpftrace -l | grep unlock_two_nondirectories
# echo "===================================="
# echo "===================================="
# echo unregister_filesystem
# sudo bpftrace -l | grep unregister_filesystem
# echo "===================================="
# echo "===================================="
# echo vfs_fsync_range
# sudo bpftrace -l | grep vfs_fsync_range
# echo "===================================="
# echo "===================================="
# echo vfs_setpos
# sudo bpftrace -l | grep vfs_setpos
# echo "===================================="
# echo "===================================="
# echo wbc_account_i
# sudo bpftrace -l | grep wbc_account_i
# echo "===================================="
