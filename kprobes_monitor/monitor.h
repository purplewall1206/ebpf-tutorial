#define I_BDEV_PROBE 0
#define __BDEV_DAX_SUPPORTED_PROBE 1
#define __BFORGET_PROBE 2
#define __BIO_ADD_PAGE_PROBE 3
#define __BLKDEV_ISSUE_DISCARD_PROBE 4
#define __BLKDEV_ISSUE_ZEROOUT_PROBE 5
#define __BLOCK_WRITE_BEGIN_PROBE 6
#define __BLOCKDEV_DIRECT_IO_PROBE 7
#define __BREAD_GFP_PROBE 8
#define __BREADAHEAD_GFP_PROBE 9
#define __BRELSE_PROBE 10
#define __CLEANCACHE_GET_PAGE_PROBE 11
#define __CLEANCACHE_INIT_FS_PROBE 12
#define __FDGET_PROBE 13
#define __FILEMAP_SET_WB_ERR_PROBE 14
#define __FIND_GET_BLOCK_PROBE 15
#define __GENERIC_FILE_FSYNC_PROBE 16
#define __GENERIC_FILE_WRITE_ITER_PROBE 17
#define __GETBLK_GFP_PROBE 18
#define __INIT_WAITQUEUE_HEAD_PROBE 19
#define __LOCK_BUFFER_PROBE 20
#define __MARK_INODE_DIRTY_PROBE 21
#define __MB_CACHE_ENTRY_FREE_PROBE 22
#define __PAGE_SYMLINK_PROBE 23
#define __PAGEVEC_RELEASE_PROBE 24
#define __PERCPU_DOWN_READ_PROBE 25
#define __PERCPU_INIT_RWSEM_PROBE 26
#define __PUT_PAGE_PROBE 27
#define __REFRIGERATOR_PROBE 28
#define __SET_PAGE_DIRTY_BUFFERS_PROBE 29
#define __SET_PAGE_DIRTY_NOBUFFERS_PROBE 30
#define __SYNC_DIRTY_BUFFER_PROBE 31
#define __TEST_SET_PAGE_WRITEBACK_PROBE 32
#define __VAR_WAITQUEUE_PROBE 33
#define __WAIT_ON_BUFFER_PROBE 34
#define __WAKE_UP_PROBE 35
#define __WARN_PRINTK_PROBE 36
#define ADD_TO_PAGE_CACHE_LRU_PROBE 37
#define BDEV_READ_ONLY_PROBE 38
#define BDEVNAME_PROBE 39
#define BH_SUBMIT_READ_PROBE 40
#define BH_UPTODATE_OR_LOCK_PROBE 41
#define BIO_ALLOC_BIOSET_PROBE 42
#define BIO_DEVNAME_PROBE 43
#define BIO_PUT_PROBE 44
#define BLK_FINISH_PLUG_PROBE 45
#define BLK_START_PLUG_PROBE 46
#define BLK_STATUS_TO_ERRNO_PROBE 47
#define BLKDEV_GET_BY_DEV_PROBE 48
#define BLKDEV_ISSUE_DISCARD_PROBE 49
#define BLKDEV_ISSUE_FLUSH_PROBE 50
#define BLKDEV_PUT_PROBE 51
#define BLOCK_COMMIT_WRITE_PROBE 52
#define BLOCK_INVALIDATEPAGE_PROBE 53
#define BLOCK_PAGE_MKWRITE_PROBE 54
#define BLOCK_READ_FULL_PAGE_PROBE 55
#define BLOCK_WRITE_END_PROBE 56
#define CAPABLE_PROBE 57
#define CLEAN_BDEV_ALIASES_PROBE 58
#define CLEAR_INODE_PROBE 59
#define CLEAR_NLINK_PROBE 60
#define CLEAR_PAGE_DIRTY_FOR_IO_PROBE 61
#define CREATE_EMPTY_BUFFERS_PROBE 62
#define CRYPTO_ALLOC_SHASH_PROBE 63
#define CRYPTO_DESTROY_TFM_PROBE 64
#define CRYPTO_SHASH_UPDATE_PROBE 65
#define CURRENT_TIME_PROBE 66
#define D_FIND_ANY_ALIAS_PROBE 67
#define D_INSTANTIATE_PROBE 68
#define D_INSTANTIATE_NEW_PROBE 69
#define D_MAKE_ROOT_PROBE 70
#define D_OBTAIN_ALIAS_PROBE 71
#define D_PATH_PROBE 72
#define D_SPLICE_ALIAS_PROBE 73
#define D_TMPFILE_PROBE 74
#define DAX_FINISH_SYNC_FAULT_PROBE 75
#define DAX_IOMAP_FAULT_PROBE 76
#define DAX_IOMAP_RW_PROBE 77
#define DAX_LAYOUT_BUSY_PAGE_PROBE 78
#define DAX_WRITEBACK_MAPPING_RANGE_PROBE 79
#define DEL_TIMER_SYNC_PROBE 80
#define DESTROY_WORKQUEUE_PROBE 81
#define DGET_PARENT_PROBE 82
#define DPUT_PROBE 83
#define DROP_NLINK_PROBE 84
#define DUMP_PAGE_PROBE 85
#define END_PAGE_WRITEBACK_PROBE 86
#define FIEMAP_FILL_NEXT_EXTENT_PROBE 87
#define FILE_CHECK_AND_ADVANCE_WB_ERR_PROBE 88
#define FILE_PATH_PROBE 89
#define FILE_REMOVE_PRIVS_PROBE 90
#define FILE_UPDATE_TIME_PROBE 91
#define FILE_WRITE_AND_WAIT_RANGE_PROBE 92
#define FILEMAP_FAULT_PROBE 93
#define FILEMAP_FLUSH_PROBE 94
#define FILEMAP_WRITE_AND_WAIT_RANGE_PROBE 95
#define FIND_INODE_NOWAIT_PROBE 96
#define FLUSH_WORKQUEUE_PROBE 97
#define FPUT_PROBE 98
#define FREEZE_BDEV_PROBE 99
#define FREEZING_SLOW_PATH_PROBE 100
#define FROM_KGID_PROBE 101
#define FROM_KGID_MUNGED_PROBE 102
#define FROM_KPROJID_PROBE 103
#define FS_DAX_GET_BY_BDEV_PROBE 104
#define GENERIC_BLOCK_BMAP_PROBE 105
#define GENERIC_BLOCK_FIEMAP_PROBE 106
#define GENERIC_CHECK_ADDRESSABLE_PROBE 107
#define GENERIC_FH_TO_DENTRY_PROBE 108
#define GENERIC_FH_TO_PARENT_PROBE 109
#define GENERIC_FILE_LLSEEK_SIZE_PROBE 110
#define GENERIC_FILE_READ_ITER_PROBE 111
#define GENERIC_FILLATTR_PROBE 112
#define GENERIC_WRITE_END_PROBE 113
#define GENERIC_WRITEPAGES_PROBE 114
#define GET_ACL_PROBE 115
#define GRAB_CACHE_PAGE_WRITE_BEGIN_PROBE 116
#define IGET_FAILED_PROBE 117
#define IGET_LOCKED_PROBE 118
#define IGRAB_PROBE 119
#define IHOLD_PROBE 120
#define IN_GROUP_P_PROBE 121
#define INC_NLINK_PROBE 122
#define INIT_SPECIAL_INODE_PROBE 123
#define INIT_TIMER_KEY_PROBE 124
#define INIT_WAIT_ENTRY_PROBE 125
#define INIT_WAIT_VAR_ENTRY_PROBE 126
#define INODE_DIO_WAIT_PROBE 127
#define INODE_INIT_ONCE_PROBE 128
#define INODE_INIT_OWNER_PROBE 129
#define INODE_NEEDS_SYNC_PROBE 130
#define INODE_NEWSIZE_OK_PROBE 131
#define INODE_NOHIGHMEM_PROBE 132
#define INODE_OWNER_OR_CAPABLE_PROBE 133
#define INODE_SET_FLAGS_PROBE 134
#define INSERT_INODE_LOCKED_PROBE 135
#define INVALIDATE_BDEV_PROBE 136
#define INVALIDATE_INODE_BUFFERS_PROBE 137
#define IOMAP_SEEK_DATA_PROBE 138
#define IOMAP_SEEK_HOLE_PROBE 139
#define IOMAP_ZERO_RANGE_PROBE 140
#define IPUT_PROBE 141
#define IS_BAD_INODE_PROBE 142
#define KERN_PATH_PROBE 143
#define KSTRDUP_PROBE 144
#define KSTRNDUP_PROBE 145
#define KTHREAD_CREATE_ON_NODE_PROBE 146
#define KTHREAD_SHOULD_STOP_PROBE 147
#define KTHREAD_STOP_PROBE 148
#define KTIME_GET_PROBE 149
#define KTIME_GET_REAL_SECONDS_PROBE 150
#define KTIME_GET_WITH_OFFSET_PROBE 151
#define LL_RW_BLOCK_PROBE 152
#define LOCK_TWO_NONDIRECTORIES_PROBE 153
#define MAKE_BAD_INODE_PROBE 154
#define MAKE_KGID_PROBE 155
#define MAKE_KPROJID_PROBE 156
#define MAKE_KUID_PROBE 157
#define MARK_BUFFER_DIRTY_PROBE 158
#define MARK_BUFFER_DIRTY_INODE_PROBE 159
#define MB_CACHE_CREATE_PROBE 160
#define MB_CACHE_DESTROY_PROBE 161
#define MB_CACHE_ENTRY_CREATE_PROBE 162
#define MB_CACHE_ENTRY_DELETE_PROBE 163
#define MB_CACHE_ENTRY_FIND_FIRST_PROBE 164
#define MB_CACHE_ENTRY_FIND_NEXT_PROBE 165
#define MB_CACHE_ENTRY_GET_PROBE 166
#define MB_CACHE_ENTRY_TOUCH_PROBE 167
#define MNT_DROP_WRITE_FILE_PROBE 168
#define MNT_WANT_WRITE_FILE_PROBE 169
#define MOD_TIMER_PROBE 170
#define MOUNT_BDEV_PROBE 171
#define NEW_INODE_PROBE 172
#define PAGE_MAPPED_PROBE 173
#define PAGE_ZERO_NEW_BUFFERS_PROBE 174
#define PAGECACHE_GET_PAGE_PROBE 175
#define PAGECACHE_ISIZE_EXTENDED_PROBE 176
#define PAGEVEC_LOOKUP_RANGE_PROBE 177
#define PARSE_OPTIONS_PROBE 178
#define PATH_PUT_PROBE 179
#define PERCPU_DOWN_WRITE_PROBE 180
#define PERCPU_FREE_RWSEM_PROBE 181
#define PERCPU_UP_WRITE_PROBE 182
#define POSIX_ACL_ALLOC_PROBE 183
#define POSIX_ACL_CHMOD_PROBE 184
#define POSIX_ACL_CREATE_PROBE 185
#define POSIX_ACL_UPDATE_MODE_PROBE 186
#define PREPARE_TO_WAIT_EVENT_PROBE 187
#define PRINTK_PROBE 188
#define PUT_DAX_PROBE 189
#define QUEUE_WORK_ON_PROBE 190
#define READ_CACHE_PAGES_PROBE 191
#define REDIRTY_PAGE_FOR_WRITEPAGE_PROBE 192
#define REGISTER_FILESYSTEM_PROBE 193
#define REGISTER_SHRINKER_PROBE 194
#define SB_MIN_BLOCKSIZE_PROBE 195
#define SB_SET_BLOCKSIZE_PROBE 196
#define SEQ_ESCAPE_PROBE 197
#define SEQ_PRINTF_PROBE 198
#define SEQ_PUTC_PROBE 199
#define SEQ_PUTS_PROBE 200
#define SET_BLOCKSIZE_PROBE 201
#define SET_CACHED_ACL_PROBE 202
#define SET_NLINK_PROBE 203
#define SET_TASK_IOPRIO_PROBE 204
#define SETATTR_COPY_PROBE 205
#define SETATTR_PREPARE_PROBE 206
#define SUBMIT_BH_PROBE 207
#define SUBMIT_BIO_PROBE 208
#define SUBMIT_BIO_WAIT_PROBE 209
#define SYNC_BLOCKDEV_PROBE 210
#define SYNC_DIRTY_BUFFER_PROBE 211
#define SYNC_FILESYSTEM_PROBE 212
#define SYNC_INODE_METADATA_PROBE 213
#define SYNC_MAPPING_BUFFERS_PROBE 214
#define TAG_PAGES_FOR_WRITEBACK_PROBE 215
#define THAW_BDEV_PROBE 216
#define TOUCH_ATIME_PROBE 217
#define TRUNCATE_INODE_PAGES_PROBE 218
#define TRUNCATE_INODE_PAGES_FINAL_PROBE 219
#define TRUNCATE_PAGECACHE_PROBE 220
#define TRUNCATE_PAGECACHE_RANGE_PROBE 221
#define TRY_TO_FREE_BUFFERS_PROBE 222
#define TRY_TO_WRITEBACK_INODES_SB_PROBE 223
#define UNLOCK_BUFFER_PROBE 224
#define UNLOCK_NEW_INODE_PROBE 225
#define UNLOCK_TWO_NONDIRECTORIES_PROBE 226
#define UNREGISTER_FILESYSTEM_PROBE 227
#define VFS_FSYNC_RANGE_PROBE 228
#define VFS_SETPOS_PROBE 229
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>
#include <linux/fs.h>
#include <linux/bio.h>

static int ext4_monitor(struct kprobe *p, struct pt_regs *regs);

bool is_called_by_ext4(void) {
    return false;
}

int I_BDEV_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __bdev_dax_supported_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __bforget_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __bio_add_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __blkdev_issue_discard_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __blkdev_issue_zeroout_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __block_write_begin_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __blockdev_direct_IO_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __bread_gfp_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __breadahead_gfp_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __brelse_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __cleancache_get_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __cleancache_init_fs_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __fdget_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __filemap_set_wb_err_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __find_get_block_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __generic_file_fsync_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __generic_file_write_iter_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __getblk_gfp_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __init_waitqueue_head_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __lock_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __mark_inode_dirty_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __mb_cache_entry_free_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __page_symlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __pagevec_release_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __percpu_down_read_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __percpu_init_rwsem_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __put_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __refrigerator_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __set_page_dirty_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __set_page_dirty_nobuffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __sync_dirty_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __test_set_page_writeback_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __var_waitqueue_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __wait_on_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __wake_up_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int __warn_printk_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int add_to_page_cache_lru_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int bdev_read_only_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int bdevname_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int bh_submit_read_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int bh_uptodate_or_lock_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int bio_alloc_bioset_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int bio_devname_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int bio_put_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int blk_finish_plug_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int blk_start_plug_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int blk_status_to_errno_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int blkdev_get_by_dev_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int blkdev_issue_discard_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int blkdev_issue_flush_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int blkdev_put_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int block_commit_write_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int block_invalidatepage_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int block_page_mkwrite_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int block_read_full_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int block_write_end_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int capable_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int clean_bdev_aliases_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int clear_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int clear_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int clear_page_dirty_for_io_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int create_empty_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int crypto_alloc_shash_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int crypto_destroy_tfm_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int crypto_shash_update_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int current_time_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_find_any_alias_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_instantiate_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_instantiate_new_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_make_root_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_obtain_alias_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_splice_alias_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int d_tmpfile_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dax_finish_sync_fault_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dax_iomap_fault_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dax_iomap_rw_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dax_layout_busy_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dax_writeback_mapping_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int del_timer_sync_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int destroy_workqueue_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dget_parent_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dput_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int drop_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int dump_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int end_page_writeback_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int fiemap_fill_next_extent_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int file_check_and_advance_wb_err_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int file_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int file_remove_privs_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int file_update_time_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int file_write_and_wait_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int filemap_fault_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int filemap_flush_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int filemap_write_and_wait_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int find_inode_nowait_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int flush_workqueue_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int fput_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int freeze_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int freezing_slow_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int from_kgid_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int from_kgid_munged_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int from_kprojid_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int fs_dax_get_by_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_block_bmap_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_block_fiemap_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_check_addressable_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_fh_to_dentry_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_fh_to_parent_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_file_llseek_size_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_file_read_iter_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_fillattr_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_write_end_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int generic_writepages_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int get_acl_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int grab_cache_page_write_begin_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int iget_failed_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int iget_locked_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int igrab_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int ihold_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int in_group_p_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inc_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int init_special_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int init_timer_key_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int init_wait_entry_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int init_wait_var_entry_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_dio_wait_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_init_once_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_init_owner_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_needs_sync_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_newsize_ok_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_nohighmem_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_owner_or_capable_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int inode_set_flags_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int insert_inode_locked_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int invalidate_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int invalidate_inode_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int iomap_seek_data_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int iomap_seek_hole_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int iomap_zero_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int iput_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int is_bad_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int kern_path_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int kstrdup_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int kstrndup_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int kthread_create_on_node_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int kthread_should_stop_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int kthread_stop_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int ktime_get_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int ktime_get_real_seconds_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int ktime_get_with_offset_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int ll_rw_block_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int lock_two_nondirectories_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int make_bad_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int make_kgid_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int make_kprojid_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int make_kuid_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mark_buffer_dirty_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mark_buffer_dirty_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_create_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_destroy_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_entry_create_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_entry_delete_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_entry_find_first_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_entry_find_next_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_entry_get_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mb_cache_entry_touch_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mnt_drop_write_file_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mnt_want_write_file_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mod_timer_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int mount_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int new_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int page_mapped_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int page_zero_new_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int pagecache_get_page_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int pagecache_isize_extended_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int pagevec_lookup_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int parse_options_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int path_put_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int percpu_down_write_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int percpu_free_rwsem_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int percpu_up_write_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int posix_acl_alloc_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int posix_acl_chmod_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int posix_acl_create_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int posix_acl_update_mode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int prepare_to_wait_event_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int printk_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int put_dax_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int queue_work_on_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int read_cache_pages_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int redirty_page_for_writepage_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int register_filesystem_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int register_shrinker_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int sb_min_blocksize_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int sb_set_blocksize_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int seq_escape_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int seq_printf_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int seq_putc_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int seq_puts_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int set_blocksize_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int set_cached_acl_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int set_nlink_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int set_task_ioprio_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int setattr_copy_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int setattr_prepare_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int submit_bh_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int submit_bio_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int submit_bio_wait_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int sync_blockdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int sync_dirty_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int sync_filesystem_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int sync_inode_metadata_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int sync_mapping_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int tag_pages_for_writeback_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int thaw_bdev_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int touch_atime_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int truncate_inode_pages_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int truncate_inode_pages_final_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int truncate_pagecache_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int truncate_pagecache_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int try_to_free_buffers_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int try_to_writeback_inodes_sb_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int unlock_buffer_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int unlock_new_inode_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int unlock_two_nondirectories_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int unregister_filesystem_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int vfs_fsync_range_ext4_monitor(struct kprobe *p, struct pt_regs *regs);

int vfs_setpos_ext4_monitor(struct kprobe *p, struct pt_regs *regs);




static struct kprobe I_BDEV_kp = {
    .symbol_name = "I_BDEV",
    .pre_handler = I_BDEV_ext4_monitor,
};

static struct kprobe __bdev_dax_supported_kp = {
    .symbol_name = "__bdev_dax_supported",
    .pre_handler = __bdev_dax_supported_ext4_monitor,
};

static struct kprobe __bforget_kp = {
    .symbol_name = "__bforget",
    .pre_handler = __bforget_ext4_monitor,
};

static struct kprobe __bio_add_page_kp = {
    .symbol_name = "__bio_add_page",
    .pre_handler = __bio_add_page_ext4_monitor,
};

static struct kprobe __blkdev_issue_discard_kp = {
    .symbol_name = "__blkdev_issue_discard",
    .pre_handler = __blkdev_issue_discard_ext4_monitor,
};

static struct kprobe __blkdev_issue_zeroout_kp = {
    .symbol_name = "__blkdev_issue_zeroout",
    .pre_handler = __blkdev_issue_zeroout_ext4_monitor,
};

static struct kprobe __block_write_begin_kp = {
    .symbol_name = "__block_write_begin",
    .pre_handler = __block_write_begin_ext4_monitor,
};

static struct kprobe __blockdev_direct_IO_kp = {
    .symbol_name = "__blockdev_direct_IO",
    .pre_handler = __blockdev_direct_IO_ext4_monitor,
};

static struct kprobe __bread_gfp_kp = {
    .symbol_name = "__bread_gfp",
    .pre_handler = __bread_gfp_ext4_monitor,
};

static struct kprobe __breadahead_gfp_kp = {
    .symbol_name = "__breadahead_gfp",
    .pre_handler = __breadahead_gfp_ext4_monitor,
};

static struct kprobe __brelse_kp = {
    .symbol_name = "__brelse",
    .pre_handler = __brelse_ext4_monitor,
};

static struct kprobe __cleancache_get_page_kp = {
    .symbol_name = "__cleancache_get_page",
    .pre_handler = __cleancache_get_page_ext4_monitor,
};

static struct kprobe __cleancache_init_fs_kp = {
    .symbol_name = "__cleancache_init_fs",
    .pre_handler = __cleancache_init_fs_ext4_monitor,
};

static struct kprobe __fdget_kp = {
    .symbol_name = "__fdget",
    .pre_handler = __fdget_ext4_monitor,
};

static struct kprobe __filemap_set_wb_err_kp = {
    .symbol_name = "__filemap_set_wb_err",
    .pre_handler = __filemap_set_wb_err_ext4_monitor,
};

static struct kprobe __find_get_block_kp = {
    .symbol_name = "__find_get_block",
    .pre_handler = __find_get_block_ext4_monitor,
};

static struct kprobe __generic_file_fsync_kp = {
    .symbol_name = "__generic_file_fsync",
    .pre_handler = __generic_file_fsync_ext4_monitor,
};

static struct kprobe __generic_file_write_iter_kp = {
    .symbol_name = "__generic_file_write_iter",
    .pre_handler = __generic_file_write_iter_ext4_monitor,
};

static struct kprobe __getblk_gfp_kp = {
    .symbol_name = "__getblk_gfp",
    .pre_handler = __getblk_gfp_ext4_monitor,
};

static struct kprobe __init_waitqueue_head_kp = {
    .symbol_name = "__init_waitqueue_head",
    .pre_handler = __init_waitqueue_head_ext4_monitor,
};

static struct kprobe __lock_buffer_kp = {
    .symbol_name = "__lock_buffer",
    .pre_handler = __lock_buffer_ext4_monitor,
};

static struct kprobe __mark_inode_dirty_kp = {
    .symbol_name = "__mark_inode_dirty",
    .pre_handler = __mark_inode_dirty_ext4_monitor,
};

static struct kprobe __mb_cache_entry_free_kp = {
    .symbol_name = "__mb_cache_entry_free",
    .pre_handler = __mb_cache_entry_free_ext4_monitor,
};

static struct kprobe __page_symlink_kp = {
    .symbol_name = "__page_symlink",
    .pre_handler = __page_symlink_ext4_monitor,
};

static struct kprobe __pagevec_release_kp = {
    .symbol_name = "__pagevec_release",
    .pre_handler = __pagevec_release_ext4_monitor,
};

static struct kprobe __percpu_down_read_kp = {
    .symbol_name = "__percpu_down_read",
    .pre_handler = __percpu_down_read_ext4_monitor,
};

static struct kprobe __percpu_init_rwsem_kp = {
    .symbol_name = "__percpu_init_rwsem",
    .pre_handler = __percpu_init_rwsem_ext4_monitor,
};

static struct kprobe __put_page_kp = {
    .symbol_name = "__put_page",
    .pre_handler = __put_page_ext4_monitor,
};

static struct kprobe __refrigerator_kp = {
    .symbol_name = "__refrigerator",
    .pre_handler = __refrigerator_ext4_monitor,
};

static struct kprobe __set_page_dirty_buffers_kp = {
    .symbol_name = "__set_page_dirty_buffers",
    .pre_handler = __set_page_dirty_buffers_ext4_monitor,
};

static struct kprobe __set_page_dirty_nobuffers_kp = {
    .symbol_name = "__set_page_dirty_nobuffers",
    .pre_handler = __set_page_dirty_nobuffers_ext4_monitor,
};

static struct kprobe __sync_dirty_buffer_kp = {
    .symbol_name = "__sync_dirty_buffer",
    .pre_handler = __sync_dirty_buffer_ext4_monitor,
};

static struct kprobe __test_set_page_writeback_kp = {
    .symbol_name = "__test_set_page_writeback",
    .pre_handler = __test_set_page_writeback_ext4_monitor,
};

static struct kprobe __var_waitqueue_kp = {
    .symbol_name = "__var_waitqueue",
    .pre_handler = __var_waitqueue_ext4_monitor,
};

static struct kprobe __wait_on_buffer_kp = {
    .symbol_name = "__wait_on_buffer",
    .pre_handler = __wait_on_buffer_ext4_monitor,
};

static struct kprobe __wake_up_kp = {
    .symbol_name = "__wake_up",
    .pre_handler = __wake_up_ext4_monitor,
};

static struct kprobe __warn_printk_kp = {
    .symbol_name = "__warn_printk",
    .pre_handler = __warn_printk_ext4_monitor,
};

static struct kprobe add_to_page_cache_lru_kp = {
    .symbol_name = "add_to_page_cache_lru",
    .pre_handler = add_to_page_cache_lru_ext4_monitor,
};

static struct kprobe bdev_read_only_kp = {
    .symbol_name = "bdev_read_only",
    .pre_handler = bdev_read_only_ext4_monitor,
};

static struct kprobe bdevname_kp = {
    .symbol_name = "bdevname",
    .pre_handler = bdevname_ext4_monitor,
};

static struct kprobe bh_submit_read_kp = {
    .symbol_name = "bh_submit_read",
    .pre_handler = bh_submit_read_ext4_monitor,
};

static struct kprobe bh_uptodate_or_lock_kp = {
    .symbol_name = "bh_uptodate_or_lock",
    .pre_handler = bh_uptodate_or_lock_ext4_monitor,
};

static struct kprobe bio_alloc_bioset_kp = {
    .symbol_name = "bio_alloc_bioset",
    .pre_handler = bio_alloc_bioset_ext4_monitor,
};

static struct kprobe bio_devname_kp = {
    .symbol_name = "bio_devname",
    .pre_handler = bio_devname_ext4_monitor,
};

static struct kprobe bio_put_kp = {
    .symbol_name = "bio_put",
    .pre_handler = bio_put_ext4_monitor,
};

static struct kprobe blk_finish_plug_kp = {
    .symbol_name = "blk_finish_plug",
    .pre_handler = blk_finish_plug_ext4_monitor,
};

static struct kprobe blk_start_plug_kp = {
    .symbol_name = "blk_start_plug",
    .pre_handler = blk_start_plug_ext4_monitor,
};

static struct kprobe blk_status_to_errno_kp = {
    .symbol_name = "blk_status_to_errno",
    .pre_handler = blk_status_to_errno_ext4_monitor,
};

static struct kprobe blkdev_get_by_dev_kp = {
    .symbol_name = "blkdev_get_by_dev",
    .pre_handler = blkdev_get_by_dev_ext4_monitor,
};

static struct kprobe blkdev_issue_discard_kp = {
    .symbol_name = "blkdev_issue_discard",
    .pre_handler = blkdev_issue_discard_ext4_monitor,
};

static struct kprobe blkdev_issue_flush_kp = {
    .symbol_name = "blkdev_issue_flush",
    .pre_handler = blkdev_issue_flush_ext4_monitor,
};

static struct kprobe blkdev_put_kp = {
    .symbol_name = "blkdev_put",
    .pre_handler = blkdev_put_ext4_monitor,
};

static struct kprobe block_commit_write_kp = {
    .symbol_name = "block_commit_write",
    .pre_handler = block_commit_write_ext4_monitor,
};

static struct kprobe block_invalidatepage_kp = {
    .symbol_name = "block_invalidatepage",
    .pre_handler = block_invalidatepage_ext4_monitor,
};

static struct kprobe block_page_mkwrite_kp = {
    .symbol_name = "block_page_mkwrite",
    .pre_handler = block_page_mkwrite_ext4_monitor,
};

static struct kprobe block_read_full_page_kp = {
    .symbol_name = "block_read_full_page",
    .pre_handler = block_read_full_page_ext4_monitor,
};

static struct kprobe block_write_end_kp = {
    .symbol_name = "block_write_end",
    .pre_handler = block_write_end_ext4_monitor,
};

static struct kprobe capable_kp = {
    .symbol_name = "capable",
    .pre_handler = capable_ext4_monitor,
};

static struct kprobe clean_bdev_aliases_kp = {
    .symbol_name = "clean_bdev_aliases",
    .pre_handler = clean_bdev_aliases_ext4_monitor,
};

static struct kprobe clear_inode_kp = {
    .symbol_name = "clear_inode",
    .pre_handler = clear_inode_ext4_monitor,
};

static struct kprobe clear_nlink_kp = {
    .symbol_name = "clear_nlink",
    .pre_handler = clear_nlink_ext4_monitor,
};

static struct kprobe clear_page_dirty_for_io_kp = {
    .symbol_name = "clear_page_dirty_for_io",
    .pre_handler = clear_page_dirty_for_io_ext4_monitor,
};

static struct kprobe create_empty_buffers_kp = {
    .symbol_name = "create_empty_buffers",
    .pre_handler = create_empty_buffers_ext4_monitor,
};

static struct kprobe crypto_alloc_shash_kp = {
    .symbol_name = "crypto_alloc_shash",
    .pre_handler = crypto_alloc_shash_ext4_monitor,
};

static struct kprobe crypto_destroy_tfm_kp = {
    .symbol_name = "crypto_destroy_tfm",
    .pre_handler = crypto_destroy_tfm_ext4_monitor,
};

static struct kprobe crypto_shash_update_kp = {
    .symbol_name = "crypto_shash_update",
    .pre_handler = crypto_shash_update_ext4_monitor,
};

static struct kprobe current_time_kp = {
    .symbol_name = "current_time",
    .pre_handler = current_time_ext4_monitor,
};

static struct kprobe d_find_any_alias_kp = {
    .symbol_name = "d_find_any_alias",
    .pre_handler = d_find_any_alias_ext4_monitor,
};

static struct kprobe d_instantiate_kp = {
    .symbol_name = "d_instantiate",
    .pre_handler = d_instantiate_ext4_monitor,
};

static struct kprobe d_instantiate_new_kp = {
    .symbol_name = "d_instantiate_new",
    .pre_handler = d_instantiate_new_ext4_monitor,
};

static struct kprobe d_make_root_kp = {
    .symbol_name = "d_make_root",
    .pre_handler = d_make_root_ext4_monitor,
};

static struct kprobe d_obtain_alias_kp = {
    .symbol_name = "d_obtain_alias",
    .pre_handler = d_obtain_alias_ext4_monitor,
};

static struct kprobe d_path_kp = {
    .symbol_name = "d_path",
    .pre_handler = d_path_ext4_monitor,
};

static struct kprobe d_splice_alias_kp = {
    .symbol_name = "d_splice_alias",
    .pre_handler = d_splice_alias_ext4_monitor,
};

static struct kprobe d_tmpfile_kp = {
    .symbol_name = "d_tmpfile",
    .pre_handler = d_tmpfile_ext4_monitor,
};

static struct kprobe dax_finish_sync_fault_kp = {
    .symbol_name = "dax_finish_sync_fault",
    .pre_handler = dax_finish_sync_fault_ext4_monitor,
};

static struct kprobe dax_iomap_fault_kp = {
    .symbol_name = "dax_iomap_fault",
    .pre_handler = dax_iomap_fault_ext4_monitor,
};

static struct kprobe dax_iomap_rw_kp = {
    .symbol_name = "dax_iomap_rw",
    .pre_handler = dax_iomap_rw_ext4_monitor,
};

static struct kprobe dax_layout_busy_page_kp = {
    .symbol_name = "dax_layout_busy_page",
    .pre_handler = dax_layout_busy_page_ext4_monitor,
};

static struct kprobe dax_writeback_mapping_range_kp = {
    .symbol_name = "dax_writeback_mapping_range",
    .pre_handler = dax_writeback_mapping_range_ext4_monitor,
};

static struct kprobe del_timer_sync_kp = {
    .symbol_name = "del_timer_sync",
    .pre_handler = del_timer_sync_ext4_monitor,
};

static struct kprobe destroy_workqueue_kp = {
    .symbol_name = "destroy_workqueue",
    .pre_handler = destroy_workqueue_ext4_monitor,
};

static struct kprobe dget_parent_kp = {
    .symbol_name = "dget_parent",
    .pre_handler = dget_parent_ext4_monitor,
};

static struct kprobe dput_kp = {
    .symbol_name = "dput",
    .pre_handler = dput_ext4_monitor,
};

static struct kprobe drop_nlink_kp = {
    .symbol_name = "drop_nlink",
    .pre_handler = drop_nlink_ext4_monitor,
};

static struct kprobe dump_page_kp = {
    .symbol_name = "dump_page",
    .pre_handler = dump_page_ext4_monitor,
};

static struct kprobe end_page_writeback_kp = {
    .symbol_name = "end_page_writeback",
    .pre_handler = end_page_writeback_ext4_monitor,
};

static struct kprobe fiemap_fill_next_extent_kp = {
    .symbol_name = "fiemap_fill_next_extent",
    .pre_handler = fiemap_fill_next_extent_ext4_monitor,
};

static struct kprobe file_check_and_advance_wb_err_kp = {
    .symbol_name = "file_check_and_advance_wb_err",
    .pre_handler = file_check_and_advance_wb_err_ext4_monitor,
};

static struct kprobe file_path_kp = {
    .symbol_name = "file_path",
    .pre_handler = file_path_ext4_monitor,
};

static struct kprobe file_remove_privs_kp = {
    .symbol_name = "file_remove_privs",
    .pre_handler = file_remove_privs_ext4_monitor,
};

static struct kprobe file_update_time_kp = {
    .symbol_name = "file_update_time",
    .pre_handler = file_update_time_ext4_monitor,
};

static struct kprobe file_write_and_wait_range_kp = {
    .symbol_name = "file_write_and_wait_range",
    .pre_handler = file_write_and_wait_range_ext4_monitor,
};

static struct kprobe filemap_fault_kp = {
    .symbol_name = "filemap_fault",
    .pre_handler = filemap_fault_ext4_monitor,
};

static struct kprobe filemap_flush_kp = {
    .symbol_name = "filemap_flush",
    .pre_handler = filemap_flush_ext4_monitor,
};

static struct kprobe filemap_write_and_wait_range_kp = {
    .symbol_name = "filemap_write_and_wait_range",
    .pre_handler = filemap_write_and_wait_range_ext4_monitor,
};

static struct kprobe find_inode_nowait_kp = {
    .symbol_name = "find_inode_nowait",
    .pre_handler = find_inode_nowait_ext4_monitor,
};

static struct kprobe flush_workqueue_kp = {
    .symbol_name = "flush_workqueue",
    .pre_handler = flush_workqueue_ext4_monitor,
};

static struct kprobe fput_kp = {
    .symbol_name = "fput",
    .pre_handler = fput_ext4_monitor,
};

static struct kprobe freeze_bdev_kp = {
    .symbol_name = "freeze_bdev",
    .pre_handler = freeze_bdev_ext4_monitor,
};

static struct kprobe freezing_slow_path_kp = {
    .symbol_name = "freezing_slow_path",
    .pre_handler = freezing_slow_path_ext4_monitor,
};

static struct kprobe from_kgid_kp = {
    .symbol_name = "from_kgid",
    .pre_handler = from_kgid_ext4_monitor,
};

static struct kprobe from_kgid_munged_kp = {
    .symbol_name = "from_kgid_munged",
    .pre_handler = from_kgid_munged_ext4_monitor,
};

static struct kprobe from_kprojid_kp = {
    .symbol_name = "from_kprojid",
    .pre_handler = from_kprojid_ext4_monitor,
};

static struct kprobe fs_dax_get_by_bdev_kp = {
    .symbol_name = "fs_dax_get_by_bdev",
    .pre_handler = fs_dax_get_by_bdev_ext4_monitor,
};

static struct kprobe generic_block_bmap_kp = {
    .symbol_name = "generic_block_bmap",
    .pre_handler = generic_block_bmap_ext4_monitor,
};

static struct kprobe generic_block_fiemap_kp = {
    .symbol_name = "generic_block_fiemap",
    .pre_handler = generic_block_fiemap_ext4_monitor,
};

static struct kprobe generic_check_addressable_kp = {
    .symbol_name = "generic_check_addressable",
    .pre_handler = generic_check_addressable_ext4_monitor,
};

static struct kprobe generic_fh_to_dentry_kp = {
    .symbol_name = "generic_fh_to_dentry",
    .pre_handler = generic_fh_to_dentry_ext4_monitor,
};

static struct kprobe generic_fh_to_parent_kp = {
    .symbol_name = "generic_fh_to_parent",
    .pre_handler = generic_fh_to_parent_ext4_monitor,
};

static struct kprobe generic_file_llseek_size_kp = {
    .symbol_name = "generic_file_llseek_size",
    .pre_handler = generic_file_llseek_size_ext4_monitor,
};

static struct kprobe generic_file_read_iter_kp = {
    .symbol_name = "generic_file_read_iter",
    .pre_handler = generic_file_read_iter_ext4_monitor,
};

static struct kprobe generic_fillattr_kp = {
    .symbol_name = "generic_fillattr",
    .pre_handler = generic_fillattr_ext4_monitor,
};

static struct kprobe generic_write_end_kp = {
    .symbol_name = "generic_write_end",
    .pre_handler = generic_write_end_ext4_monitor,
};

static struct kprobe generic_writepages_kp = {
    .symbol_name = "generic_writepages",
    .pre_handler = generic_writepages_ext4_monitor,
};

static struct kprobe get_acl_kp = {
    .symbol_name = "get_acl",
    .pre_handler = get_acl_ext4_monitor,
};

static struct kprobe grab_cache_page_write_begin_kp = {
    .symbol_name = "grab_cache_page_write_begin",
    .pre_handler = grab_cache_page_write_begin_ext4_monitor,
};

static struct kprobe iget_failed_kp = {
    .symbol_name = "iget_failed",
    .pre_handler = iget_failed_ext4_monitor,
};

static struct kprobe iget_locked_kp = {
    .symbol_name = "iget_locked",
    .pre_handler = iget_locked_ext4_monitor,
};

static struct kprobe igrab_kp = {
    .symbol_name = "igrab",
    .pre_handler = igrab_ext4_monitor,
};

static struct kprobe ihold_kp = {
    .symbol_name = "ihold",
    .pre_handler = ihold_ext4_monitor,
};

static struct kprobe in_group_p_kp = {
    .symbol_name = "in_group_p",
    .pre_handler = in_group_p_ext4_monitor,
};

static struct kprobe inc_nlink_kp = {
    .symbol_name = "inc_nlink",
    .pre_handler = inc_nlink_ext4_monitor,
};

static struct kprobe init_special_inode_kp = {
    .symbol_name = "init_special_inode",
    .pre_handler = init_special_inode_ext4_monitor,
};

static struct kprobe init_timer_key_kp = {
    .symbol_name = "init_timer_key",
    .pre_handler = init_timer_key_ext4_monitor,
};

static struct kprobe init_wait_entry_kp = {
    .symbol_name = "init_wait_entry",
    .pre_handler = init_wait_entry_ext4_monitor,
};

static struct kprobe init_wait_var_entry_kp = {
    .symbol_name = "init_wait_var_entry",
    .pre_handler = init_wait_var_entry_ext4_monitor,
};

static struct kprobe inode_dio_wait_kp = {
    .symbol_name = "inode_dio_wait",
    .pre_handler = inode_dio_wait_ext4_monitor,
};

static struct kprobe inode_init_once_kp = {
    .symbol_name = "inode_init_once",
    .pre_handler = inode_init_once_ext4_monitor,
};

static struct kprobe inode_init_owner_kp = {
    .symbol_name = "inode_init_owner",
    .pre_handler = inode_init_owner_ext4_monitor,
};

static struct kprobe inode_needs_sync_kp = {
    .symbol_name = "inode_needs_sync",
    .pre_handler = inode_needs_sync_ext4_monitor,
};

static struct kprobe inode_newsize_ok_kp = {
    .symbol_name = "inode_newsize_ok",
    .pre_handler = inode_newsize_ok_ext4_monitor,
};

static struct kprobe inode_nohighmem_kp = {
    .symbol_name = "inode_nohighmem",
    .pre_handler = inode_nohighmem_ext4_monitor,
};

static struct kprobe inode_owner_or_capable_kp = {
    .symbol_name = "inode_owner_or_capable",
    .pre_handler = inode_owner_or_capable_ext4_monitor,
};

static struct kprobe inode_set_flags_kp = {
    .symbol_name = "inode_set_flags",
    .pre_handler = inode_set_flags_ext4_monitor,
};

static struct kprobe insert_inode_locked_kp = {
    .symbol_name = "insert_inode_locked",
    .pre_handler = insert_inode_locked_ext4_monitor,
};

static struct kprobe invalidate_bdev_kp = {
    .symbol_name = "invalidate_bdev",
    .pre_handler = invalidate_bdev_ext4_monitor,
};

static struct kprobe invalidate_inode_buffers_kp = {
    .symbol_name = "invalidate_inode_buffers",
    .pre_handler = invalidate_inode_buffers_ext4_monitor,
};

static struct kprobe iomap_seek_data_kp = {
    .symbol_name = "iomap_seek_data",
    .pre_handler = iomap_seek_data_ext4_monitor,
};

static struct kprobe iomap_seek_hole_kp = {
    .symbol_name = "iomap_seek_hole",
    .pre_handler = iomap_seek_hole_ext4_monitor,
};

static struct kprobe iomap_zero_range_kp = {
    .symbol_name = "iomap_zero_range",
    .pre_handler = iomap_zero_range_ext4_monitor,
};

static struct kprobe iput_kp = {
    .symbol_name = "iput",
    .pre_handler = iput_ext4_monitor,
};

static struct kprobe is_bad_inode_kp = {
    .symbol_name = "is_bad_inode",
    .pre_handler = is_bad_inode_ext4_monitor,
};

static struct kprobe kern_path_kp = {
    .symbol_name = "kern_path",
    .pre_handler = kern_path_ext4_monitor,
};

static struct kprobe kstrdup_kp = {
    .symbol_name = "kstrdup",
    .pre_handler = kstrdup_ext4_monitor,
};

static struct kprobe kstrndup_kp = {
    .symbol_name = "kstrndup",
    .pre_handler = kstrndup_ext4_monitor,
};

static struct kprobe kthread_create_on_node_kp = {
    .symbol_name = "kthread_create_on_node",
    .pre_handler = kthread_create_on_node_ext4_monitor,
};

static struct kprobe kthread_should_stop_kp = {
    .symbol_name = "kthread_should_stop",
    .pre_handler = kthread_should_stop_ext4_monitor,
};

static struct kprobe kthread_stop_kp = {
    .symbol_name = "kthread_stop",
    .pre_handler = kthread_stop_ext4_monitor,
};

static struct kprobe ktime_get_kp = {
    .symbol_name = "ktime_get",
    .pre_handler = ktime_get_ext4_monitor,
};

static struct kprobe ktime_get_real_seconds_kp = {
    .symbol_name = "ktime_get_real_seconds",
    .pre_handler = ktime_get_real_seconds_ext4_monitor,
};

static struct kprobe ktime_get_with_offset_kp = {
    .symbol_name = "ktime_get_with_offset",
    .pre_handler = ktime_get_with_offset_ext4_monitor,
};

static struct kprobe ll_rw_block_kp = {
    .symbol_name = "ll_rw_block",
    .pre_handler = ll_rw_block_ext4_monitor,
};

static struct kprobe lock_two_nondirectories_kp = {
    .symbol_name = "lock_two_nondirectories",
    .pre_handler = lock_two_nondirectories_ext4_monitor,
};

static struct kprobe make_bad_inode_kp = {
    .symbol_name = "make_bad_inode",
    .pre_handler = make_bad_inode_ext4_monitor,
};

static struct kprobe make_kgid_kp = {
    .symbol_name = "make_kgid",
    .pre_handler = make_kgid_ext4_monitor,
};

static struct kprobe make_kprojid_kp = {
    .symbol_name = "make_kprojid",
    .pre_handler = make_kprojid_ext4_monitor,
};

static struct kprobe make_kuid_kp = {
    .symbol_name = "make_kuid",
    .pre_handler = make_kuid_ext4_monitor,
};

static struct kprobe mark_buffer_dirty_kp = {
    .symbol_name = "mark_buffer_dirty",
    .pre_handler = mark_buffer_dirty_ext4_monitor,
};

static struct kprobe mark_buffer_dirty_inode_kp = {
    .symbol_name = "mark_buffer_dirty_inode",
    .pre_handler = mark_buffer_dirty_inode_ext4_monitor,
};

static struct kprobe mb_cache_create_kp = {
    .symbol_name = "mb_cache_create",
    .pre_handler = mb_cache_create_ext4_monitor,
};

static struct kprobe mb_cache_destroy_kp = {
    .symbol_name = "mb_cache_destroy",
    .pre_handler = mb_cache_destroy_ext4_monitor,
};

static struct kprobe mb_cache_entry_create_kp = {
    .symbol_name = "mb_cache_entry_create",
    .pre_handler = mb_cache_entry_create_ext4_monitor,
};

static struct kprobe mb_cache_entry_delete_kp = {
    .symbol_name = "mb_cache_entry_delete",
    .pre_handler = mb_cache_entry_delete_ext4_monitor,
};

static struct kprobe mb_cache_entry_find_first_kp = {
    .symbol_name = "mb_cache_entry_find_first",
    .pre_handler = mb_cache_entry_find_first_ext4_monitor,
};

static struct kprobe mb_cache_entry_find_next_kp = {
    .symbol_name = "mb_cache_entry_find_next",
    .pre_handler = mb_cache_entry_find_next_ext4_monitor,
};

static struct kprobe mb_cache_entry_get_kp = {
    .symbol_name = "mb_cache_entry_get",
    .pre_handler = mb_cache_entry_get_ext4_monitor,
};

static struct kprobe mb_cache_entry_touch_kp = {
    .symbol_name = "mb_cache_entry_touch",
    .pre_handler = mb_cache_entry_touch_ext4_monitor,
};

static struct kprobe mnt_drop_write_file_kp = {
    .symbol_name = "mnt_drop_write_file",
    .pre_handler = mnt_drop_write_file_ext4_monitor,
};

static struct kprobe mnt_want_write_file_kp = {
    .symbol_name = "mnt_want_write_file",
    .pre_handler = mnt_want_write_file_ext4_monitor,
};

static struct kprobe mod_timer_kp = {
    .symbol_name = "mod_timer",
    .pre_handler = mod_timer_ext4_monitor,
};

static struct kprobe mount_bdev_kp = {
    .symbol_name = "mount_bdev",
    .pre_handler = mount_bdev_ext4_monitor,
};

static struct kprobe new_inode_kp = {
    .symbol_name = "new_inode",
    .pre_handler = new_inode_ext4_monitor,
};

static struct kprobe page_mapped_kp = {
    .symbol_name = "page_mapped",
    .pre_handler = page_mapped_ext4_monitor,
};

static struct kprobe page_zero_new_buffers_kp = {
    .symbol_name = "page_zero_new_buffers",
    .pre_handler = page_zero_new_buffers_ext4_monitor,
};

static struct kprobe pagecache_get_page_kp = {
    .symbol_name = "pagecache_get_page",
    .pre_handler = pagecache_get_page_ext4_monitor,
};

static struct kprobe pagecache_isize_extended_kp = {
    .symbol_name = "pagecache_isize_extended",
    .pre_handler = pagecache_isize_extended_ext4_monitor,
};

static struct kprobe pagevec_lookup_range_kp = {
    .symbol_name = "pagevec_lookup_range",
    .pre_handler = pagevec_lookup_range_ext4_monitor,
};

static struct kprobe parse_options_kp = {
    .symbol_name = "parse_options",
    .pre_handler = parse_options_ext4_monitor,
};

static struct kprobe path_put_kp = {
    .symbol_name = "path_put",
    .pre_handler = path_put_ext4_monitor,
};

static struct kprobe percpu_down_write_kp = {
    .symbol_name = "percpu_down_write",
    .pre_handler = percpu_down_write_ext4_monitor,
};

static struct kprobe percpu_free_rwsem_kp = {
    .symbol_name = "percpu_free_rwsem",
    .pre_handler = percpu_free_rwsem_ext4_monitor,
};

static struct kprobe percpu_up_write_kp = {
    .symbol_name = "percpu_up_write",
    .pre_handler = percpu_up_write_ext4_monitor,
};

static struct kprobe posix_acl_alloc_kp = {
    .symbol_name = "posix_acl_alloc",
    .pre_handler = posix_acl_alloc_ext4_monitor,
};

static struct kprobe posix_acl_chmod_kp = {
    .symbol_name = "posix_acl_chmod",
    .pre_handler = posix_acl_chmod_ext4_monitor,
};

static struct kprobe posix_acl_create_kp = {
    .symbol_name = "posix_acl_create",
    .pre_handler = posix_acl_create_ext4_monitor,
};

static struct kprobe posix_acl_update_mode_kp = {
    .symbol_name = "posix_acl_update_mode",
    .pre_handler = posix_acl_update_mode_ext4_monitor,
};

static struct kprobe prepare_to_wait_event_kp = {
    .symbol_name = "prepare_to_wait_event",
    .pre_handler = prepare_to_wait_event_ext4_monitor,
};

static struct kprobe printk_kp = {
    .symbol_name = "printk",
    .pre_handler = printk_ext4_monitor,
};

static struct kprobe put_dax_kp = {
    .symbol_name = "put_dax",
    .pre_handler = put_dax_ext4_monitor,
};

static struct kprobe queue_work_on_kp = {
    .symbol_name = "queue_work_on",
    .pre_handler = queue_work_on_ext4_monitor,
};

static struct kprobe read_cache_pages_kp = {
    .symbol_name = "read_cache_pages",
    .pre_handler = read_cache_pages_ext4_monitor,
};

static struct kprobe redirty_page_for_writepage_kp = {
    .symbol_name = "redirty_page_for_writepage",
    .pre_handler = redirty_page_for_writepage_ext4_monitor,
};

static struct kprobe register_filesystem_kp = {
    .symbol_name = "register_filesystem",
    .pre_handler = register_filesystem_ext4_monitor,
};

static struct kprobe register_shrinker_kp = {
    .symbol_name = "register_shrinker",
    .pre_handler = register_shrinker_ext4_monitor,
};

static struct kprobe sb_min_blocksize_kp = {
    .symbol_name = "sb_min_blocksize",
    .pre_handler = sb_min_blocksize_ext4_monitor,
};

static struct kprobe sb_set_blocksize_kp = {
    .symbol_name = "sb_set_blocksize",
    .pre_handler = sb_set_blocksize_ext4_monitor,
};

static struct kprobe seq_escape_kp = {
    .symbol_name = "seq_escape",
    .pre_handler = seq_escape_ext4_monitor,
};

static struct kprobe seq_printf_kp = {
    .symbol_name = "seq_printf",
    .pre_handler = seq_printf_ext4_monitor,
};

static struct kprobe seq_putc_kp = {
    .symbol_name = "seq_putc",
    .pre_handler = seq_putc_ext4_monitor,
};

static struct kprobe seq_puts_kp = {
    .symbol_name = "seq_puts",
    .pre_handler = seq_puts_ext4_monitor,
};

static struct kprobe set_blocksize_kp = {
    .symbol_name = "set_blocksize",
    .pre_handler = set_blocksize_ext4_monitor,
};

static struct kprobe set_cached_acl_kp = {
    .symbol_name = "set_cached_acl",
    .pre_handler = set_cached_acl_ext4_monitor,
};

static struct kprobe set_nlink_kp = {
    .symbol_name = "set_nlink",
    .pre_handler = set_nlink_ext4_monitor,
};

static struct kprobe set_task_ioprio_kp = {
    .symbol_name = "set_task_ioprio",
    .pre_handler = set_task_ioprio_ext4_monitor,
};

static struct kprobe setattr_copy_kp = {
    .symbol_name = "setattr_copy",
    .pre_handler = setattr_copy_ext4_monitor,
};

static struct kprobe setattr_prepare_kp = {
    .symbol_name = "setattr_prepare",
    .pre_handler = setattr_prepare_ext4_monitor,
};

static struct kprobe submit_bh_kp = {
    .symbol_name = "submit_bh",
    .pre_handler = submit_bh_ext4_monitor,
};

static struct kprobe submit_bio_kp = {
    .symbol_name = "submit_bio",
    .pre_handler = submit_bio_ext4_monitor,
};

static struct kprobe submit_bio_wait_kp = {
    .symbol_name = "submit_bio_wait",
    .pre_handler = submit_bio_wait_ext4_monitor,
};

static struct kprobe sync_blockdev_kp = {
    .symbol_name = "sync_blockdev",
    .pre_handler = sync_blockdev_ext4_monitor,
};

static struct kprobe sync_dirty_buffer_kp = {
    .symbol_name = "sync_dirty_buffer",
    .pre_handler = sync_dirty_buffer_ext4_monitor,
};

static struct kprobe sync_filesystem_kp = {
    .symbol_name = "sync_filesystem",
    .pre_handler = sync_filesystem_ext4_monitor,
};

static struct kprobe sync_inode_metadata_kp = {
    .symbol_name = "sync_inode_metadata",
    .pre_handler = sync_inode_metadata_ext4_monitor,
};

static struct kprobe sync_mapping_buffers_kp = {
    .symbol_name = "sync_mapping_buffers",
    .pre_handler = sync_mapping_buffers_ext4_monitor,
};

static struct kprobe tag_pages_for_writeback_kp = {
    .symbol_name = "tag_pages_for_writeback",
    .pre_handler = tag_pages_for_writeback_ext4_monitor,
};

static struct kprobe thaw_bdev_kp = {
    .symbol_name = "thaw_bdev",
    .pre_handler = thaw_bdev_ext4_monitor,
};

static struct kprobe touch_atime_kp = {
    .symbol_name = "touch_atime",
    .pre_handler = touch_atime_ext4_monitor,
};

static struct kprobe truncate_inode_pages_kp = {
    .symbol_name = "truncate_inode_pages",
    .pre_handler = truncate_inode_pages_ext4_monitor,
};

static struct kprobe truncate_inode_pages_final_kp = {
    .symbol_name = "truncate_inode_pages_final",
    .pre_handler = truncate_inode_pages_final_ext4_monitor,
};

static struct kprobe truncate_pagecache_kp = {
    .symbol_name = "truncate_pagecache",
    .pre_handler = truncate_pagecache_ext4_monitor,
};

static struct kprobe truncate_pagecache_range_kp = {
    .symbol_name = "truncate_pagecache_range",
    .pre_handler = truncate_pagecache_range_ext4_monitor,
};

static struct kprobe try_to_free_buffers_kp = {
    .symbol_name = "try_to_free_buffers",
    .pre_handler = try_to_free_buffers_ext4_monitor,
};

static struct kprobe try_to_writeback_inodes_sb_kp = {
    .symbol_name = "try_to_writeback_inodes_sb",
    .pre_handler = try_to_writeback_inodes_sb_ext4_monitor,
};

static struct kprobe unlock_buffer_kp = {
    .symbol_name = "unlock_buffer",
    .pre_handler = unlock_buffer_ext4_monitor,
};

static struct kprobe unlock_new_inode_kp = {
    .symbol_name = "unlock_new_inode",
    .pre_handler = unlock_new_inode_ext4_monitor,
};

static struct kprobe unlock_two_nondirectories_kp = {
    .symbol_name = "unlock_two_nondirectories",
    .pre_handler = unlock_two_nondirectories_ext4_monitor,
};

static struct kprobe unregister_filesystem_kp = {
    .symbol_name = "unregister_filesystem",
    .pre_handler = unregister_filesystem_ext4_monitor,
};

static struct kprobe vfs_fsync_range_kp = {
    .symbol_name = "vfs_fsync_range",
    .pre_handler = vfs_fsync_range_ext4_monitor,
};

static struct kprobe vfs_setpos_kp = {
    .symbol_name = "vfs_setpos",
    .pre_handler = vfs_setpos_ext4_monitor,
};


static struct kprobe *kps[240] = {
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
