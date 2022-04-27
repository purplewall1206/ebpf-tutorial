#ifndef MONITOR_H
#define MONITOR_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>
#include <linux/fs.h>
#include <linux/bio.h>
#include <linux/percpu-defs.h>
MODULE_LICENSE("GPL");

#define EXT4_ALLOC_INODE_PROBE 0
#define EXT4_BMAP_PROBE 1
#define EXT4_DA_INVALIDATEPAGE_PROBE 2
#define EXT4_DA_WRITE_BEGIN_PROBE 3
#define EXT4_DA_WRITE_END_PROBE 4
#define EXT4_DAX_WRITEPAGES_PROBE 5
#define EXT4_DESTROY_INODE_PROBE 6
#define EXT4_DIR_LLSEEK_PROBE 7
#define EXT4_DIR_OPEN_PROBE 8
#define EXT4_DIRECT_IO_PROBE 9
#define EXT4_DIRTY_INODE_PROBE 10
#define EXT4_DROP_INODE_PROBE 11
#define EXT4_EVICT_INODE_PROBE 12
#define EXT4_FALLOCATE_PROBE 13
#define EXT4_FH_TO_DENTRY_PROBE 14
#define EXT4_FH_TO_PARENT_PROBE 15
#define EXT4_FIEMAP_PROBE 16
#define EXT4_FILE_GETATTR_PROBE 17
#define EXT4_FILE_MMAP_PROBE 18
#define EXT4_FILE_OPEN_PROBE 19
#define EXT4_FILE_READ_ITER_PROBE 20
#define EXT4_FILE_WRITE_ITER_PROBE 21
#define EXT4_FILEMAP_FAULT_PROBE 22
#define EXT4_FREEZE_PROBE 23
#define EXT4_GET_ACL_PROBE 24
#define EXT4_GET_PARENT_PROBE 25
#define EXT4_INVALIDATEPAGE_PROBE 26
#define EXT4_IOCTL_PROBE 27
#define EXT4_IOMAP_BEGIN_PROBE 28
#define EXT4_IOMAP_END_PROBE 29
#define EXT4_LISTXATTR_PROBE 30
#define EXT4_LLSEEK_PROBE 31
#define EXT4_MB_SEQ_GROUPS_NEXT_PROBE 32
#define EXT4_MB_SEQ_GROUPS_SHOW_PROBE 33
#define EXT4_MB_SEQ_GROUPS_START_PROBE 34
#define EXT4_MB_SEQ_GROUPS_STOP_PROBE 35
#define EXT4_MOUNT_PROBE 36
#define EXT4_NFS_COMMIT_METADATA_PROBE 37
#define EXT4_PAGE_MKWRITE_PROBE 38
#define EXT4_PUT_SUPER_PROBE 39
#define EXT4_READDIR_PROBE 40
#define EXT4_READPAGE_PROBE 41
#define EXT4_READPAGES_PROBE 42
#define EXT4_RELEASE_DIR_PROBE 43
#define EXT4_RELEASE_FILE_PROBE 44
#define EXT4_RELEASEPAGE_PROBE 45
#define EXT4_REMOUNT_PROBE 46
#define EXT4_SET_ACL_PROBE 47
#define EXT4_SET_PAGE_DIRTY_PROBE 48
#define EXT4_SETATTR_PROBE 49
#define EXT4_SHOW_OPTIONS_PROBE 50
#define EXT4_STATFS_PROBE 51
#define EXT4_SYNC_FILE_PROBE 52
#define EXT4_SYNC_FS_PROBE 53
#define EXT4_UNFREEZE_PROBE 54
#define EXT4_WRITE_BEGIN_PROBE 55
#define EXT4_WRITE_END_PROBE 56
#define EXT4_WRITE_INODE_PROBE 57
#define EXT4_WRITEPAGE_PROBE 58
#define EXT4_WRITEPAGES_PROBE 59

int ext4_alloc_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_alloc_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_bmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_bmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_da_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_da_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_da_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_da_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_da_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_da_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_dax_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_dax_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_destroy_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_destroy_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_dir_llseek_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_dir_llseek_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_dir_open_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_dir_open_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_direct_IO_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_direct_IO_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_dirty_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_dirty_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_drop_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_drop_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_evict_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_evict_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_fallocate_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_fallocate_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_fh_to_dentry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_fh_to_dentry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_fh_to_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_fh_to_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_fiemap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_fiemap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_file_getattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_file_getattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_file_mmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_file_mmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_file_open_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_file_open_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_file_read_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_file_read_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_file_write_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_file_write_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_filemap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_filemap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_freeze_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_freeze_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_get_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_get_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_get_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_get_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_ioctl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_ioctl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_iomap_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_iomap_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_iomap_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_iomap_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_listxattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_listxattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_llseek_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_llseek_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_mb_seq_groups_next_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_mb_seq_groups_next_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_mb_seq_groups_show_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_mb_seq_groups_show_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_mb_seq_groups_start_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_mb_seq_groups_start_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_mb_seq_groups_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_mb_seq_groups_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_mount_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_mount_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_nfs_commit_metadata_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_nfs_commit_metadata_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_page_mkwrite_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_page_mkwrite_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_put_super_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_put_super_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_readdir_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_readdir_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_readpage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_readpage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_readpages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_readpages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_release_dir_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_release_dir_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_release_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_release_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_releasepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_releasepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_remount_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_remount_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_set_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_set_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_set_page_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_set_page_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_setattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_setattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_show_options_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_show_options_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_statfs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_statfs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_sync_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_sync_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_sync_fs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_sync_fs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_unfreeze_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_unfreeze_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_write_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_write_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_writepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_writepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ext4_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ext4_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);


static struct kretprobe ext4_alloc_inode_kp = {
    .kp.symbol_name = "ext4_alloc_inode",
    .entry_handler = ext4_alloc_inode_entry_handler,
    .handler = ext4_alloc_inode_ret_handler,
};

static struct kretprobe ext4_bmap_kp = {
    .kp.symbol_name = "ext4_bmap",
    .entry_handler = ext4_bmap_entry_handler,
    .handler = ext4_bmap_ret_handler,
};

static struct kretprobe ext4_da_invalidatepage_kp = {
    .kp.symbol_name = "ext4_da_invalidatepage",
    .entry_handler = ext4_da_invalidatepage_entry_handler,
    .handler = ext4_da_invalidatepage_ret_handler,
};

static struct kretprobe ext4_da_write_begin_kp = {
    .kp.symbol_name = "ext4_da_write_begin",
    .entry_handler = ext4_da_write_begin_entry_handler,
    .handler = ext4_da_write_begin_ret_handler,
};

static struct kretprobe ext4_da_write_end_kp = {
    .kp.symbol_name = "ext4_da_write_end",
    .entry_handler = ext4_da_write_end_entry_handler,
    .handler = ext4_da_write_end_ret_handler,
};

static struct kretprobe ext4_dax_writepages_kp = {
    .kp.symbol_name = "ext4_dax_writepages",
    .entry_handler = ext4_dax_writepages_entry_handler,
    .handler = ext4_dax_writepages_ret_handler,
};

static struct kretprobe ext4_destroy_inode_kp = {
    .kp.symbol_name = "ext4_destroy_inode",
    .entry_handler = ext4_destroy_inode_entry_handler,
    .handler = ext4_destroy_inode_ret_handler,
};

static struct kretprobe ext4_dir_llseek_kp = {
    .kp.symbol_name = "ext4_dir_llseek",
    .entry_handler = ext4_dir_llseek_entry_handler,
    .handler = ext4_dir_llseek_ret_handler,
};

static struct kretprobe ext4_dir_open_kp = {
    .kp.symbol_name = "ext4_dir_open",
    .entry_handler = ext4_dir_open_entry_handler,
    .handler = ext4_dir_open_ret_handler,
};

static struct kretprobe ext4_direct_IO_kp = {
    .kp.symbol_name = "ext4_direct_IO",
    .entry_handler = ext4_direct_IO_entry_handler,
    .handler = ext4_direct_IO_ret_handler,
};

static struct kretprobe ext4_dirty_inode_kp = {
    .kp.symbol_name = "ext4_dirty_inode",
    .entry_handler = ext4_dirty_inode_entry_handler,
    .handler = ext4_dirty_inode_ret_handler,
};

static struct kretprobe ext4_drop_inode_kp = {
    .kp.symbol_name = "ext4_drop_inode",
    .entry_handler = ext4_drop_inode_entry_handler,
    .handler = ext4_drop_inode_ret_handler,
};

static struct kretprobe ext4_evict_inode_kp = {
    .kp.symbol_name = "ext4_evict_inode",
    .entry_handler = ext4_evict_inode_entry_handler,
    .handler = ext4_evict_inode_ret_handler,
};

static struct kretprobe ext4_fallocate_kp = {
    .kp.symbol_name = "ext4_fallocate",
    .entry_handler = ext4_fallocate_entry_handler,
    .handler = ext4_fallocate_ret_handler,
};

static struct kretprobe ext4_fh_to_dentry_kp = {
    .kp.symbol_name = "ext4_fh_to_dentry",
    .entry_handler = ext4_fh_to_dentry_entry_handler,
    .handler = ext4_fh_to_dentry_ret_handler,
};

static struct kretprobe ext4_fh_to_parent_kp = {
    .kp.symbol_name = "ext4_fh_to_parent",
    .entry_handler = ext4_fh_to_parent_entry_handler,
    .handler = ext4_fh_to_parent_ret_handler,
};

static struct kretprobe ext4_fiemap_kp = {
    .kp.symbol_name = "ext4_fiemap",
    .entry_handler = ext4_fiemap_entry_handler,
    .handler = ext4_fiemap_ret_handler,
};

static struct kretprobe ext4_file_getattr_kp = {
    .kp.symbol_name = "ext4_file_getattr",
    .entry_handler = ext4_file_getattr_entry_handler,
    .handler = ext4_file_getattr_ret_handler,
};

static struct kretprobe ext4_file_mmap_kp = {
    .kp.symbol_name = "ext4_file_mmap",
    .entry_handler = ext4_file_mmap_entry_handler,
    .handler = ext4_file_mmap_ret_handler,
};

static struct kretprobe ext4_file_open_kp = {
    .kp.symbol_name = "ext4_file_open",
    .entry_handler = ext4_file_open_entry_handler,
    .handler = ext4_file_open_ret_handler,
};

static struct kretprobe ext4_file_read_iter_kp = {
    .kp.symbol_name = "ext4_file_read_iter",
    .entry_handler = ext4_file_read_iter_entry_handler,
    .handler = ext4_file_read_iter_ret_handler,
};

static struct kretprobe ext4_file_write_iter_kp = {
    .kp.symbol_name = "ext4_file_write_iter",
    .entry_handler = ext4_file_write_iter_entry_handler,
    .handler = ext4_file_write_iter_ret_handler,
};

static struct kretprobe ext4_filemap_fault_kp = {
    .kp.symbol_name = "ext4_filemap_fault",
    .entry_handler = ext4_filemap_fault_entry_handler,
    .handler = ext4_filemap_fault_ret_handler,
};

static struct kretprobe ext4_freeze_kp = {
    .kp.symbol_name = "ext4_freeze",
    .entry_handler = ext4_freeze_entry_handler,
    .handler = ext4_freeze_ret_handler,
};

static struct kretprobe ext4_get_acl_kp = {
    .kp.symbol_name = "ext4_get_acl",
    .entry_handler = ext4_get_acl_entry_handler,
    .handler = ext4_get_acl_ret_handler,
};

static struct kretprobe ext4_get_parent_kp = {
    .kp.symbol_name = "ext4_get_parent",
    .entry_handler = ext4_get_parent_entry_handler,
    .handler = ext4_get_parent_ret_handler,
};

static struct kretprobe ext4_invalidatepage_kp = {
    .kp.symbol_name = "ext4_invalidatepage",
    .entry_handler = ext4_invalidatepage_entry_handler,
    .handler = ext4_invalidatepage_ret_handler,
};

static struct kretprobe ext4_ioctl_kp = {
    .kp.symbol_name = "ext4_ioctl",
    .entry_handler = ext4_ioctl_entry_handler,
    .handler = ext4_ioctl_ret_handler,
};

static struct kretprobe ext4_iomap_begin_kp = {
    .kp.symbol_name = "ext4_iomap_begin",
    .entry_handler = ext4_iomap_begin_entry_handler,
    .handler = ext4_iomap_begin_ret_handler,
};

static struct kretprobe ext4_iomap_end_kp = {
    .kp.symbol_name = "ext4_iomap_end",
    .entry_handler = ext4_iomap_end_entry_handler,
    .handler = ext4_iomap_end_ret_handler,
};

static struct kretprobe ext4_listxattr_kp = {
    .kp.symbol_name = "ext4_listxattr",
    .entry_handler = ext4_listxattr_entry_handler,
    .handler = ext4_listxattr_ret_handler,
};

static struct kretprobe ext4_llseek_kp = {
    .kp.symbol_name = "ext4_llseek",
    .entry_handler = ext4_llseek_entry_handler,
    .handler = ext4_llseek_ret_handler,
};

static struct kretprobe ext4_mb_seq_groups_next_kp = {
    .kp.symbol_name = "ext4_mb_seq_groups_next",
    .entry_handler = ext4_mb_seq_groups_next_entry_handler,
    .handler = ext4_mb_seq_groups_next_ret_handler,
};

static struct kretprobe ext4_mb_seq_groups_show_kp = {
    .kp.symbol_name = "ext4_mb_seq_groups_show",
    .entry_handler = ext4_mb_seq_groups_show_entry_handler,
    .handler = ext4_mb_seq_groups_show_ret_handler,
};

static struct kretprobe ext4_mb_seq_groups_start_kp = {
    .kp.symbol_name = "ext4_mb_seq_groups_start",
    .entry_handler = ext4_mb_seq_groups_start_entry_handler,
    .handler = ext4_mb_seq_groups_start_ret_handler,
};

static struct kretprobe ext4_mb_seq_groups_stop_kp = {
    .kp.symbol_name = "ext4_mb_seq_groups_stop",
    .entry_handler = ext4_mb_seq_groups_stop_entry_handler,
    .handler = ext4_mb_seq_groups_stop_ret_handler,
};

static struct kretprobe ext4_mount_kp = {
    .kp.symbol_name = "ext4_mount",
    .entry_handler = ext4_mount_entry_handler,
    .handler = ext4_mount_ret_handler,
};

static struct kretprobe ext4_nfs_commit_metadata_kp = {
    .kp.symbol_name = "ext4_nfs_commit_metadata",
    .entry_handler = ext4_nfs_commit_metadata_entry_handler,
    .handler = ext4_nfs_commit_metadata_ret_handler,
};

static struct kretprobe ext4_page_mkwrite_kp = {
    .kp.symbol_name = "ext4_page_mkwrite",
    .entry_handler = ext4_page_mkwrite_entry_handler,
    .handler = ext4_page_mkwrite_ret_handler,
};

static struct kretprobe ext4_put_super_kp = {
    .kp.symbol_name = "ext4_put_super",
    .entry_handler = ext4_put_super_entry_handler,
    .handler = ext4_put_super_ret_handler,
};

static struct kretprobe ext4_readdir_kp = {
    .kp.symbol_name = "ext4_readdir",
    .entry_handler = ext4_readdir_entry_handler,
    .handler = ext4_readdir_ret_handler,
};

static struct kretprobe ext4_readpage_kp = {
    .kp.symbol_name = "ext4_readpage",
    .entry_handler = ext4_readpage_entry_handler,
    .handler = ext4_readpage_ret_handler,
};

static struct kretprobe ext4_readpages_kp = {
    .kp.symbol_name = "ext4_readpages",
    .entry_handler = ext4_readpages_entry_handler,
    .handler = ext4_readpages_ret_handler,
};

static struct kretprobe ext4_release_dir_kp = {
    .kp.symbol_name = "ext4_release_dir",
    .entry_handler = ext4_release_dir_entry_handler,
    .handler = ext4_release_dir_ret_handler,
};

static struct kretprobe ext4_release_file_kp = {
    .kp.symbol_name = "ext4_release_file",
    .entry_handler = ext4_release_file_entry_handler,
    .handler = ext4_release_file_ret_handler,
};

static struct kretprobe ext4_releasepage_kp = {
    .kp.symbol_name = "ext4_releasepage",
    .entry_handler = ext4_releasepage_entry_handler,
    .handler = ext4_releasepage_ret_handler,
};

static struct kretprobe ext4_remount_kp = {
    .kp.symbol_name = "ext4_remount",
    .entry_handler = ext4_remount_entry_handler,
    .handler = ext4_remount_ret_handler,
};

static struct kretprobe ext4_set_acl_kp = {
    .kp.symbol_name = "ext4_set_acl",
    .entry_handler = ext4_set_acl_entry_handler,
    .handler = ext4_set_acl_ret_handler,
};

static struct kretprobe ext4_set_page_dirty_kp = {
    .kp.symbol_name = "ext4_set_page_dirty",
    .entry_handler = ext4_set_page_dirty_entry_handler,
    .handler = ext4_set_page_dirty_ret_handler,
};

static struct kretprobe ext4_setattr_kp = {
    .kp.symbol_name = "ext4_setattr",
    .entry_handler = ext4_setattr_entry_handler,
    .handler = ext4_setattr_ret_handler,
};

static struct kretprobe ext4_show_options_kp = {
    .kp.symbol_name = "ext4_show_options",
    .entry_handler = ext4_show_options_entry_handler,
    .handler = ext4_show_options_ret_handler,
};

static struct kretprobe ext4_statfs_kp = {
    .kp.symbol_name = "ext4_statfs",
    .entry_handler = ext4_statfs_entry_handler,
    .handler = ext4_statfs_ret_handler,
};

static struct kretprobe ext4_sync_file_kp = {
    .kp.symbol_name = "ext4_sync_file",
    .entry_handler = ext4_sync_file_entry_handler,
    .handler = ext4_sync_file_ret_handler,
};

static struct kretprobe ext4_sync_fs_kp = {
    .kp.symbol_name = "ext4_sync_fs",
    .entry_handler = ext4_sync_fs_entry_handler,
    .handler = ext4_sync_fs_ret_handler,
};

static struct kretprobe ext4_unfreeze_kp = {
    .kp.symbol_name = "ext4_unfreeze",
    .entry_handler = ext4_unfreeze_entry_handler,
    .handler = ext4_unfreeze_ret_handler,
};

static struct kretprobe ext4_write_begin_kp = {
    .kp.symbol_name = "ext4_write_begin",
    .entry_handler = ext4_write_begin_entry_handler,
    .handler = ext4_write_begin_ret_handler,
};

static struct kretprobe ext4_write_end_kp = {
    .kp.symbol_name = "ext4_write_end",
    .entry_handler = ext4_write_end_entry_handler,
    .handler = ext4_write_end_ret_handler,
};

static struct kretprobe ext4_write_inode_kp = {
    .kp.symbol_name = "ext4_write_inode",
    .entry_handler = ext4_write_inode_entry_handler,
    .handler = ext4_write_inode_ret_handler,
};

static struct kretprobe ext4_writepage_kp = {
    .kp.symbol_name = "ext4_writepage",
    .entry_handler = ext4_writepage_entry_handler,
    .handler = ext4_writepage_ret_handler,
};

static struct kretprobe ext4_writepages_kp = {
    .kp.symbol_name = "ext4_writepages",
    .entry_handler = ext4_writepages_entry_handler,
    .handler = ext4_writepages_ret_handler,
};


// -----------------------------------------------------------------------------------------


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


int I_BDEV_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int I_BDEV_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __bdev_dax_supported_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __bdev_dax_supported_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __bforget_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __bforget_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __bio_add_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __bio_add_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __blkdev_issue_discard_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __blkdev_issue_discard_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __blkdev_issue_zeroout_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __blkdev_issue_zeroout_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __block_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __block_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __blockdev_direct_IO_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __blockdev_direct_IO_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __bread_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __bread_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __breadahead_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __breadahead_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __brelse_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __brelse_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __cleancache_get_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __cleancache_get_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __cleancache_init_fs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __cleancache_init_fs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __fdget_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __fdget_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __filemap_set_wb_err_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __filemap_set_wb_err_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __find_get_block_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __find_get_block_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __generic_file_fsync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __generic_file_fsync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __generic_file_write_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __generic_file_write_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __getblk_gfp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __getblk_gfp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __init_waitqueue_head_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __init_waitqueue_head_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __lock_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __lock_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __mark_inode_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __mark_inode_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __mb_cache_entry_free_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __mb_cache_entry_free_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __page_symlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __page_symlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __pagevec_release_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __pagevec_release_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __percpu_down_read_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __percpu_down_read_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __percpu_init_rwsem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __percpu_init_rwsem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __put_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __put_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __refrigerator_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __refrigerator_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __set_page_dirty_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __set_page_dirty_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __set_page_dirty_nobuffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __set_page_dirty_nobuffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __sync_dirty_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __sync_dirty_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __test_set_page_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __test_set_page_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __var_waitqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __var_waitqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __wait_on_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __wait_on_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __wake_up_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __wake_up_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int __warn_printk_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int __warn_printk_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int add_to_page_cache_lru_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int add_to_page_cache_lru_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int bdev_read_only_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int bdev_read_only_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int bdevname_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int bdevname_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int bh_submit_read_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int bh_submit_read_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int bh_uptodate_or_lock_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int bh_uptodate_or_lock_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int bio_alloc_bioset_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int bio_alloc_bioset_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int bio_devname_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int bio_devname_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int bio_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int bio_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int blk_finish_plug_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int blk_finish_plug_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int blk_start_plug_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int blk_start_plug_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int blk_status_to_errno_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int blk_status_to_errno_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int blkdev_get_by_dev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int blkdev_get_by_dev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int blkdev_issue_discard_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int blkdev_issue_discard_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int blkdev_issue_flush_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int blkdev_issue_flush_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int blkdev_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int blkdev_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int block_commit_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int block_commit_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int block_invalidatepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int block_invalidatepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int block_page_mkwrite_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int block_page_mkwrite_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int block_read_full_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int block_read_full_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int block_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int block_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int capable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int capable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int clean_bdev_aliases_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int clean_bdev_aliases_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int clear_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int clear_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int clear_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int clear_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int clear_page_dirty_for_io_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int clear_page_dirty_for_io_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int create_empty_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int create_empty_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int crypto_alloc_shash_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int crypto_alloc_shash_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int crypto_destroy_tfm_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int crypto_destroy_tfm_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int crypto_shash_update_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int crypto_shash_update_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int current_time_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int current_time_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_find_any_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_find_any_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_instantiate_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_instantiate_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_instantiate_new_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_instantiate_new_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_make_root_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_make_root_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_obtain_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_obtain_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_splice_alias_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_splice_alias_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int d_tmpfile_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int d_tmpfile_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dax_finish_sync_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dax_finish_sync_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dax_iomap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dax_iomap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dax_iomap_rw_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dax_iomap_rw_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dax_layout_busy_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dax_layout_busy_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dax_writeback_mapping_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dax_writeback_mapping_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int del_timer_sync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int del_timer_sync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int destroy_workqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int destroy_workqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dget_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dget_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int drop_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int drop_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int dump_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int dump_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int end_page_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int end_page_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int fiemap_fill_next_extent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int fiemap_fill_next_extent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int file_check_and_advance_wb_err_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int file_check_and_advance_wb_err_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int file_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int file_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int file_remove_privs_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int file_remove_privs_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int file_update_time_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int file_update_time_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int file_write_and_wait_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int file_write_and_wait_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int filemap_fault_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int filemap_fault_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int filemap_flush_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int filemap_flush_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int filemap_write_and_wait_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int filemap_write_and_wait_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int find_inode_nowait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int find_inode_nowait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int flush_workqueue_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int flush_workqueue_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int fput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int fput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int freeze_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int freeze_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int freezing_slow_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int freezing_slow_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int from_kgid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int from_kgid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int from_kgid_munged_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int from_kgid_munged_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int from_kprojid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int from_kprojid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int fs_dax_get_by_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int fs_dax_get_by_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_block_bmap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_block_bmap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_block_fiemap_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_block_fiemap_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_check_addressable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_check_addressable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_fh_to_dentry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_fh_to_dentry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_fh_to_parent_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_fh_to_parent_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_file_llseek_size_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_file_llseek_size_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_file_read_iter_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_file_read_iter_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_fillattr_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_fillattr_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_write_end_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_write_end_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int generic_writepages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int generic_writepages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int get_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int get_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int grab_cache_page_write_begin_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int grab_cache_page_write_begin_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int iget_failed_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int iget_failed_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int iget_locked_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int iget_locked_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int igrab_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int igrab_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ihold_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ihold_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int in_group_p_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int in_group_p_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inc_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inc_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int init_special_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int init_special_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int init_timer_key_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int init_timer_key_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int init_wait_entry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int init_wait_entry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int init_wait_var_entry_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int init_wait_var_entry_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_dio_wait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_dio_wait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_init_once_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_init_once_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_init_owner_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_init_owner_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_needs_sync_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_needs_sync_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_newsize_ok_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_newsize_ok_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_nohighmem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_nohighmem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_owner_or_capable_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_owner_or_capable_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int inode_set_flags_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int inode_set_flags_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int insert_inode_locked_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int insert_inode_locked_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int invalidate_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int invalidate_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int invalidate_inode_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int invalidate_inode_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int iomap_seek_data_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int iomap_seek_data_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int iomap_seek_hole_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int iomap_seek_hole_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int iomap_zero_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int iomap_zero_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int iput_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int iput_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int is_bad_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int is_bad_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int kern_path_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int kern_path_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int kstrdup_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int kstrdup_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int kstrndup_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int kstrndup_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int kthread_create_on_node_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int kthread_create_on_node_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int kthread_should_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int kthread_should_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int kthread_stop_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int kthread_stop_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ktime_get_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ktime_get_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ktime_get_real_seconds_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ktime_get_real_seconds_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ktime_get_with_offset_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ktime_get_with_offset_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int ll_rw_block_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int ll_rw_block_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int lock_two_nondirectories_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int lock_two_nondirectories_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int make_bad_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int make_bad_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int make_kgid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int make_kgid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int make_kprojid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int make_kprojid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int make_kuid_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int make_kuid_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mark_buffer_dirty_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mark_buffer_dirty_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mark_buffer_dirty_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mark_buffer_dirty_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_destroy_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_destroy_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_entry_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_entry_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_entry_delete_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_entry_delete_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_entry_find_first_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_entry_find_first_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_entry_find_next_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_entry_find_next_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_entry_get_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_entry_get_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mb_cache_entry_touch_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mb_cache_entry_touch_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mnt_drop_write_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mnt_drop_write_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mnt_want_write_file_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mnt_want_write_file_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mod_timer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mod_timer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int mount_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int mount_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int new_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int new_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int page_mapped_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int page_mapped_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int page_zero_new_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int page_zero_new_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int pagecache_get_page_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int pagecache_get_page_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int pagecache_isize_extended_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int pagecache_isize_extended_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int pagevec_lookup_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int pagevec_lookup_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int parse_options_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int parse_options_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int path_put_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int path_put_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int percpu_down_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int percpu_down_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int percpu_free_rwsem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int percpu_free_rwsem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int percpu_up_write_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int percpu_up_write_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int posix_acl_alloc_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int posix_acl_alloc_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int posix_acl_chmod_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int posix_acl_chmod_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int posix_acl_create_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int posix_acl_create_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int posix_acl_update_mode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int posix_acl_update_mode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int prepare_to_wait_event_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int prepare_to_wait_event_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int printk_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int printk_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int put_dax_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int put_dax_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int queue_work_on_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int queue_work_on_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int read_cache_pages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int read_cache_pages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int redirty_page_for_writepage_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int redirty_page_for_writepage_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int register_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int register_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int register_shrinker_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int register_shrinker_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int sb_min_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int sb_min_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int sb_set_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int sb_set_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int seq_escape_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int seq_escape_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int seq_printf_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int seq_printf_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int seq_putc_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int seq_putc_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int seq_puts_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int seq_puts_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int set_blocksize_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int set_blocksize_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int set_cached_acl_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int set_cached_acl_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int set_nlink_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int set_nlink_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int set_task_ioprio_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int set_task_ioprio_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int setattr_copy_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int setattr_copy_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int setattr_prepare_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int setattr_prepare_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int submit_bh_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int submit_bh_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int submit_bio_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int submit_bio_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int submit_bio_wait_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int submit_bio_wait_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int sync_blockdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int sync_blockdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int sync_dirty_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int sync_dirty_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int sync_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int sync_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int sync_inode_metadata_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int sync_inode_metadata_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int sync_mapping_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int sync_mapping_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int tag_pages_for_writeback_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int tag_pages_for_writeback_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int thaw_bdev_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int thaw_bdev_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int touch_atime_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int touch_atime_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int truncate_inode_pages_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int truncate_inode_pages_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int truncate_inode_pages_final_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int truncate_inode_pages_final_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int truncate_pagecache_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int truncate_pagecache_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int truncate_pagecache_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int truncate_pagecache_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int try_to_free_buffers_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int try_to_free_buffers_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int try_to_writeback_inodes_sb_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int try_to_writeback_inodes_sb_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int unlock_buffer_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int unlock_buffer_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int unlock_new_inode_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int unlock_new_inode_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int unlock_two_nondirectories_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int unlock_two_nondirectories_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int unregister_filesystem_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int unregister_filesystem_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int vfs_fsync_range_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int vfs_fsync_range_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);

int vfs_setpos_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
int vfs_setpos_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);


static struct kretprobe I_BDEV_kp = {
    .kp.symbol_name = "I_BDEV",
    .entry_handler = I_BDEV_entry_handler,
    .handler = I_BDEV_ret_handler,
};

static struct kretprobe __bdev_dax_supported_kp = {
    .kp.symbol_name = "__bdev_dax_supported",
    .entry_handler = __bdev_dax_supported_entry_handler,
    .handler = __bdev_dax_supported_ret_handler,
};

static struct kretprobe __bforget_kp = {
    .kp.symbol_name = "__bforget",
    .entry_handler = __bforget_entry_handler,
    .handler = __bforget_ret_handler,
};

static struct kretprobe __bio_add_page_kp = {
    .kp.symbol_name = "__bio_add_page",
    .entry_handler = __bio_add_page_entry_handler,
    .handler = __bio_add_page_ret_handler,
};

static struct kretprobe __blkdev_issue_discard_kp = {
    .kp.symbol_name = "__blkdev_issue_discard",
    .entry_handler = __blkdev_issue_discard_entry_handler,
    .handler = __blkdev_issue_discard_ret_handler,
};

static struct kretprobe __blkdev_issue_zeroout_kp = {
    .kp.symbol_name = "__blkdev_issue_zeroout",
    .entry_handler = __blkdev_issue_zeroout_entry_handler,
    .handler = __blkdev_issue_zeroout_ret_handler,
};

static struct kretprobe __block_write_begin_kp = {
    .kp.symbol_name = "__block_write_begin",
    .entry_handler = __block_write_begin_entry_handler,
    .handler = __block_write_begin_ret_handler,
};

static struct kretprobe __blockdev_direct_IO_kp = {
    .kp.symbol_name = "__blockdev_direct_IO",
    .entry_handler = __blockdev_direct_IO_entry_handler,
    .handler = __blockdev_direct_IO_ret_handler,
};

static struct kretprobe __bread_gfp_kp = {
    .kp.symbol_name = "__bread_gfp",
    .entry_handler = __bread_gfp_entry_handler,
    .handler = __bread_gfp_ret_handler,
};

static struct kretprobe __breadahead_gfp_kp = {
    .kp.symbol_name = "__breadahead_gfp",
    .entry_handler = __breadahead_gfp_entry_handler,
    .handler = __breadahead_gfp_ret_handler,
};

static struct kretprobe __brelse_kp = {
    .kp.symbol_name = "__brelse",
    .entry_handler = __brelse_entry_handler,
    .handler = __brelse_ret_handler,
};

static struct kretprobe __cleancache_get_page_kp = {
    .kp.symbol_name = "__cleancache_get_page",
    .entry_handler = __cleancache_get_page_entry_handler,
    .handler = __cleancache_get_page_ret_handler,
};

static struct kretprobe __cleancache_init_fs_kp = {
    .kp.symbol_name = "__cleancache_init_fs",
    .entry_handler = __cleancache_init_fs_entry_handler,
    .handler = __cleancache_init_fs_ret_handler,
};

static struct kretprobe __fdget_kp = {
    .kp.symbol_name = "__fdget",
    .entry_handler = __fdget_entry_handler,
    .handler = __fdget_ret_handler,
};

static struct kretprobe __filemap_set_wb_err_kp = {
    .kp.symbol_name = "__filemap_set_wb_err",
    .entry_handler = __filemap_set_wb_err_entry_handler,
    .handler = __filemap_set_wb_err_ret_handler,
};

static struct kretprobe __find_get_block_kp = {
    .kp.symbol_name = "__find_get_block",
    .entry_handler = __find_get_block_entry_handler,
    .handler = __find_get_block_ret_handler,
};

static struct kretprobe __generic_file_fsync_kp = {
    .kp.symbol_name = "__generic_file_fsync",
    .entry_handler = __generic_file_fsync_entry_handler,
    .handler = __generic_file_fsync_ret_handler,
};

static struct kretprobe __generic_file_write_iter_kp = {
    .kp.symbol_name = "__generic_file_write_iter",
    .entry_handler = __generic_file_write_iter_entry_handler,
    .handler = __generic_file_write_iter_ret_handler,
};

static struct kretprobe __getblk_gfp_kp = {
    .kp.symbol_name = "__getblk_gfp",
    .entry_handler = __getblk_gfp_entry_handler,
    .handler = __getblk_gfp_ret_handler,
};

static struct kretprobe __init_waitqueue_head_kp = {
    .kp.symbol_name = "__init_waitqueue_head",
    .entry_handler = __init_waitqueue_head_entry_handler,
    .handler = __init_waitqueue_head_ret_handler,
};

static struct kretprobe __lock_buffer_kp = {
    .kp.symbol_name = "__lock_buffer",
    .entry_handler = __lock_buffer_entry_handler,
    .handler = __lock_buffer_ret_handler,
};

static struct kretprobe __mark_inode_dirty_kp = {
    .kp.symbol_name = "__mark_inode_dirty",
    .entry_handler = __mark_inode_dirty_entry_handler,
    .handler = __mark_inode_dirty_ret_handler,
};

static struct kretprobe __mb_cache_entry_free_kp = {
    .kp.symbol_name = "__mb_cache_entry_free",
    .entry_handler = __mb_cache_entry_free_entry_handler,
    .handler = __mb_cache_entry_free_ret_handler,
};

static struct kretprobe __page_symlink_kp = {
    .kp.symbol_name = "__page_symlink",
    .entry_handler = __page_symlink_entry_handler,
    .handler = __page_symlink_ret_handler,
};

static struct kretprobe __pagevec_release_kp = {
    .kp.symbol_name = "__pagevec_release",
    .entry_handler = __pagevec_release_entry_handler,
    .handler = __pagevec_release_ret_handler,
};

static struct kretprobe __percpu_down_read_kp = {
    .kp.symbol_name = "__percpu_down_read",
    .entry_handler = __percpu_down_read_entry_handler,
    .handler = __percpu_down_read_ret_handler,
};

static struct kretprobe __percpu_init_rwsem_kp = {
    .kp.symbol_name = "__percpu_init_rwsem",
    .entry_handler = __percpu_init_rwsem_entry_handler,
    .handler = __percpu_init_rwsem_ret_handler,
};

static struct kretprobe __put_page_kp = {
    .kp.symbol_name = "__put_page",
    .entry_handler = __put_page_entry_handler,
    .handler = __put_page_ret_handler,
};

static struct kretprobe __refrigerator_kp = {
    .kp.symbol_name = "__refrigerator",
    .entry_handler = __refrigerator_entry_handler,
    .handler = __refrigerator_ret_handler,
};

static struct kretprobe __set_page_dirty_buffers_kp = {
    .kp.symbol_name = "__set_page_dirty_buffers",
    .entry_handler = __set_page_dirty_buffers_entry_handler,
    .handler = __set_page_dirty_buffers_ret_handler,
};

static struct kretprobe __set_page_dirty_nobuffers_kp = {
    .kp.symbol_name = "__set_page_dirty_nobuffers",
    .entry_handler = __set_page_dirty_nobuffers_entry_handler,
    .handler = __set_page_dirty_nobuffers_ret_handler,
};

static struct kretprobe __sync_dirty_buffer_kp = {
    .kp.symbol_name = "__sync_dirty_buffer",
    .entry_handler = __sync_dirty_buffer_entry_handler,
    .handler = __sync_dirty_buffer_ret_handler,
};

static struct kretprobe __test_set_page_writeback_kp = {
    .kp.symbol_name = "__test_set_page_writeback",
    .entry_handler = __test_set_page_writeback_entry_handler,
    .handler = __test_set_page_writeback_ret_handler,
};

static struct kretprobe __var_waitqueue_kp = {
    .kp.symbol_name = "__var_waitqueue",
    .entry_handler = __var_waitqueue_entry_handler,
    .handler = __var_waitqueue_ret_handler,
};

static struct kretprobe __wait_on_buffer_kp = {
    .kp.symbol_name = "__wait_on_buffer",
    .entry_handler = __wait_on_buffer_entry_handler,
    .handler = __wait_on_buffer_ret_handler,
};

static struct kretprobe __wake_up_kp = {
    .kp.symbol_name = "__wake_up",
    .entry_handler = __wake_up_entry_handler,
    .handler = __wake_up_ret_handler,
};

static struct kretprobe __warn_printk_kp = {
    .kp.symbol_name = "__warn_printk",
    .entry_handler = __warn_printk_entry_handler,
    .handler = __warn_printk_ret_handler,
};

static struct kretprobe add_to_page_cache_lru_kp = {
    .kp.symbol_name = "add_to_page_cache_lru",
    .entry_handler = add_to_page_cache_lru_entry_handler,
    .handler = add_to_page_cache_lru_ret_handler,
};

static struct kretprobe bdev_read_only_kp = {
    .kp.symbol_name = "bdev_read_only",
    .entry_handler = bdev_read_only_entry_handler,
    .handler = bdev_read_only_ret_handler,
};

static struct kretprobe bdevname_kp = {
    .kp.symbol_name = "bdevname",
    .entry_handler = bdevname_entry_handler,
    .handler = bdevname_ret_handler,
};

static struct kretprobe bh_submit_read_kp = {
    .kp.symbol_name = "bh_submit_read",
    .entry_handler = bh_submit_read_entry_handler,
    .handler = bh_submit_read_ret_handler,
};

static struct kretprobe bh_uptodate_or_lock_kp = {
    .kp.symbol_name = "bh_uptodate_or_lock",
    .entry_handler = bh_uptodate_or_lock_entry_handler,
    .handler = bh_uptodate_or_lock_ret_handler,
};

static struct kretprobe bio_alloc_bioset_kp = {
    .kp.symbol_name = "bio_alloc_bioset",
    .entry_handler = bio_alloc_bioset_entry_handler,
    .handler = bio_alloc_bioset_ret_handler,
};

static struct kretprobe bio_devname_kp = {
    .kp.symbol_name = "bio_devname",
    .entry_handler = bio_devname_entry_handler,
    .handler = bio_devname_ret_handler,
};

static struct kretprobe bio_put_kp = {
    .kp.symbol_name = "bio_put",
    .entry_handler = bio_put_entry_handler,
    .handler = bio_put_ret_handler,
};

static struct kretprobe blk_finish_plug_kp = {
    .kp.symbol_name = "blk_finish_plug",
    .entry_handler = blk_finish_plug_entry_handler,
    .handler = blk_finish_plug_ret_handler,
};

static struct kretprobe blk_start_plug_kp = {
    .kp.symbol_name = "blk_start_plug",
    .entry_handler = blk_start_plug_entry_handler,
    .handler = blk_start_plug_ret_handler,
};

static struct kretprobe blk_status_to_errno_kp = {
    .kp.symbol_name = "blk_status_to_errno",
    .entry_handler = blk_status_to_errno_entry_handler,
    .handler = blk_status_to_errno_ret_handler,
};

static struct kretprobe blkdev_get_by_dev_kp = {
    .kp.symbol_name = "blkdev_get_by_dev",
    .entry_handler = blkdev_get_by_dev_entry_handler,
    .handler = blkdev_get_by_dev_ret_handler,
};

static struct kretprobe blkdev_issue_discard_kp = {
    .kp.symbol_name = "blkdev_issue_discard",
    .entry_handler = blkdev_issue_discard_entry_handler,
    .handler = blkdev_issue_discard_ret_handler,
};

static struct kretprobe blkdev_issue_flush_kp = {
    .kp.symbol_name = "blkdev_issue_flush",
    .entry_handler = blkdev_issue_flush_entry_handler,
    .handler = blkdev_issue_flush_ret_handler,
};

static struct kretprobe blkdev_put_kp = {
    .kp.symbol_name = "blkdev_put",
    .entry_handler = blkdev_put_entry_handler,
    .handler = blkdev_put_ret_handler,
};

static struct kretprobe block_commit_write_kp = {
    .kp.symbol_name = "block_commit_write",
    .entry_handler = block_commit_write_entry_handler,
    .handler = block_commit_write_ret_handler,
};

static struct kretprobe block_invalidatepage_kp = {
    .kp.symbol_name = "block_invalidatepage",
    .entry_handler = block_invalidatepage_entry_handler,
    .handler = block_invalidatepage_ret_handler,
};

static struct kretprobe block_page_mkwrite_kp = {
    .kp.symbol_name = "block_page_mkwrite",
    .entry_handler = block_page_mkwrite_entry_handler,
    .handler = block_page_mkwrite_ret_handler,
};

static struct kretprobe block_read_full_page_kp = {
    .kp.symbol_name = "block_read_full_page",
    .entry_handler = block_read_full_page_entry_handler,
    .handler = block_read_full_page_ret_handler,
};

static struct kretprobe block_write_end_kp = {
    .kp.symbol_name = "block_write_end",
    .entry_handler = block_write_end_entry_handler,
    .handler = block_write_end_ret_handler,
};

static struct kretprobe capable_kp = {
    .kp.symbol_name = "capable",
    .entry_handler = capable_entry_handler,
    .handler = capable_ret_handler,
};

static struct kretprobe clean_bdev_aliases_kp = {
    .kp.symbol_name = "clean_bdev_aliases",
    .entry_handler = clean_bdev_aliases_entry_handler,
    .handler = clean_bdev_aliases_ret_handler,
};

static struct kretprobe clear_inode_kp = {
    .kp.symbol_name = "clear_inode",
    .entry_handler = clear_inode_entry_handler,
    .handler = clear_inode_ret_handler,
};

static struct kretprobe clear_nlink_kp = {
    .kp.symbol_name = "clear_nlink",
    .entry_handler = clear_nlink_entry_handler,
    .handler = clear_nlink_ret_handler,
};

static struct kretprobe clear_page_dirty_for_io_kp = {
    .kp.symbol_name = "clear_page_dirty_for_io",
    .entry_handler = clear_page_dirty_for_io_entry_handler,
    .handler = clear_page_dirty_for_io_ret_handler,
};

static struct kretprobe create_empty_buffers_kp = {
    .kp.symbol_name = "create_empty_buffers",
    .entry_handler = create_empty_buffers_entry_handler,
    .handler = create_empty_buffers_ret_handler,
};

static struct kretprobe crypto_alloc_shash_kp = {
    .kp.symbol_name = "crypto_alloc_shash",
    .entry_handler = crypto_alloc_shash_entry_handler,
    .handler = crypto_alloc_shash_ret_handler,
};

static struct kretprobe crypto_destroy_tfm_kp = {
    .kp.symbol_name = "crypto_destroy_tfm",
    .entry_handler = crypto_destroy_tfm_entry_handler,
    .handler = crypto_destroy_tfm_ret_handler,
};

static struct kretprobe crypto_shash_update_kp = {
    .kp.symbol_name = "crypto_shash_update",
    .entry_handler = crypto_shash_update_entry_handler,
    .handler = crypto_shash_update_ret_handler,
};

static struct kretprobe current_time_kp = {
    .kp.symbol_name = "current_time",
    .entry_handler = current_time_entry_handler,
    .handler = current_time_ret_handler,
};

static struct kretprobe d_find_any_alias_kp = {
    .kp.symbol_name = "d_find_any_alias",
    .entry_handler = d_find_any_alias_entry_handler,
    .handler = d_find_any_alias_ret_handler,
};

static struct kretprobe d_instantiate_kp = {
    .kp.symbol_name = "d_instantiate",
    .entry_handler = d_instantiate_entry_handler,
    .handler = d_instantiate_ret_handler,
};

static struct kretprobe d_instantiate_new_kp = {
    .kp.symbol_name = "d_instantiate_new",
    .entry_handler = d_instantiate_new_entry_handler,
    .handler = d_instantiate_new_ret_handler,
};

static struct kretprobe d_make_root_kp = {
    .kp.symbol_name = "d_make_root",
    .entry_handler = d_make_root_entry_handler,
    .handler = d_make_root_ret_handler,
};

static struct kretprobe d_obtain_alias_kp = {
    .kp.symbol_name = "d_obtain_alias",
    .entry_handler = d_obtain_alias_entry_handler,
    .handler = d_obtain_alias_ret_handler,
};

static struct kretprobe d_path_kp = {
    .kp.symbol_name = "d_path",
    .entry_handler = d_path_entry_handler,
    .handler = d_path_ret_handler,
};

static struct kretprobe d_splice_alias_kp = {
    .kp.symbol_name = "d_splice_alias",
    .entry_handler = d_splice_alias_entry_handler,
    .handler = d_splice_alias_ret_handler,
};

static struct kretprobe d_tmpfile_kp = {
    .kp.symbol_name = "d_tmpfile",
    .entry_handler = d_tmpfile_entry_handler,
    .handler = d_tmpfile_ret_handler,
};

static struct kretprobe dax_finish_sync_fault_kp = {
    .kp.symbol_name = "dax_finish_sync_fault",
    .entry_handler = dax_finish_sync_fault_entry_handler,
    .handler = dax_finish_sync_fault_ret_handler,
};

static struct kretprobe dax_iomap_fault_kp = {
    .kp.symbol_name = "dax_iomap_fault",
    .entry_handler = dax_iomap_fault_entry_handler,
    .handler = dax_iomap_fault_ret_handler,
};

static struct kretprobe dax_iomap_rw_kp = {
    .kp.symbol_name = "dax_iomap_rw",
    .entry_handler = dax_iomap_rw_entry_handler,
    .handler = dax_iomap_rw_ret_handler,
};

static struct kretprobe dax_layout_busy_page_kp = {
    .kp.symbol_name = "dax_layout_busy_page",
    .entry_handler = dax_layout_busy_page_entry_handler,
    .handler = dax_layout_busy_page_ret_handler,
};

static struct kretprobe dax_writeback_mapping_range_kp = {
    .kp.symbol_name = "dax_writeback_mapping_range",
    .entry_handler = dax_writeback_mapping_range_entry_handler,
    .handler = dax_writeback_mapping_range_ret_handler,
};

static struct kretprobe del_timer_sync_kp = {
    .kp.symbol_name = "del_timer_sync",
    .entry_handler = del_timer_sync_entry_handler,
    .handler = del_timer_sync_ret_handler,
};

static struct kretprobe destroy_workqueue_kp = {
    .kp.symbol_name = "destroy_workqueue",
    .entry_handler = destroy_workqueue_entry_handler,
    .handler = destroy_workqueue_ret_handler,
};

static struct kretprobe dget_parent_kp = {
    .kp.symbol_name = "dget_parent",
    .entry_handler = dget_parent_entry_handler,
    .handler = dget_parent_ret_handler,
};

static struct kretprobe dput_kp = {
    .kp.symbol_name = "dput",
    .entry_handler = dput_entry_handler,
    .handler = dput_ret_handler,
};

static struct kretprobe drop_nlink_kp = {
    .kp.symbol_name = "drop_nlink",
    .entry_handler = drop_nlink_entry_handler,
    .handler = drop_nlink_ret_handler,
};

static struct kretprobe dump_page_kp = {
    .kp.symbol_name = "dump_page",
    .entry_handler = dump_page_entry_handler,
    .handler = dump_page_ret_handler,
};

static struct kretprobe end_page_writeback_kp = {
    .kp.symbol_name = "end_page_writeback",
    .entry_handler = end_page_writeback_entry_handler,
    .handler = end_page_writeback_ret_handler,
};

static struct kretprobe fiemap_fill_next_extent_kp = {
    .kp.symbol_name = "fiemap_fill_next_extent",
    .entry_handler = fiemap_fill_next_extent_entry_handler,
    .handler = fiemap_fill_next_extent_ret_handler,
};

static struct kretprobe file_check_and_advance_wb_err_kp = {
    .kp.symbol_name = "file_check_and_advance_wb_err",
    .entry_handler = file_check_and_advance_wb_err_entry_handler,
    .handler = file_check_and_advance_wb_err_ret_handler,
};

static struct kretprobe file_path_kp = {
    .kp.symbol_name = "file_path",
    .entry_handler = file_path_entry_handler,
    .handler = file_path_ret_handler,
};

static struct kretprobe file_remove_privs_kp = {
    .kp.symbol_name = "file_remove_privs",
    .entry_handler = file_remove_privs_entry_handler,
    .handler = file_remove_privs_ret_handler,
};

static struct kretprobe file_update_time_kp = {
    .kp.symbol_name = "file_update_time",
    .entry_handler = file_update_time_entry_handler,
    .handler = file_update_time_ret_handler,
};

static struct kretprobe file_write_and_wait_range_kp = {
    .kp.symbol_name = "file_write_and_wait_range",
    .entry_handler = file_write_and_wait_range_entry_handler,
    .handler = file_write_and_wait_range_ret_handler,
};

static struct kretprobe filemap_fault_kp = {
    .kp.symbol_name = "filemap_fault",
    .entry_handler = filemap_fault_entry_handler,
    .handler = filemap_fault_ret_handler,
};

static struct kretprobe filemap_flush_kp = {
    .kp.symbol_name = "filemap_flush",
    .entry_handler = filemap_flush_entry_handler,
    .handler = filemap_flush_ret_handler,
};

static struct kretprobe filemap_write_and_wait_range_kp = {
    .kp.symbol_name = "filemap_write_and_wait_range",
    .entry_handler = filemap_write_and_wait_range_entry_handler,
    .handler = filemap_write_and_wait_range_ret_handler,
};

static struct kretprobe find_inode_nowait_kp = {
    .kp.symbol_name = "find_inode_nowait",
    .entry_handler = find_inode_nowait_entry_handler,
    .handler = find_inode_nowait_ret_handler,
};

static struct kretprobe flush_workqueue_kp = {
    .kp.symbol_name = "flush_workqueue",
    .entry_handler = flush_workqueue_entry_handler,
    .handler = flush_workqueue_ret_handler,
};

static struct kretprobe fput_kp = {
    .kp.symbol_name = "fput",
    .entry_handler = fput_entry_handler,
    .handler = fput_ret_handler,
};

static struct kretprobe freeze_bdev_kp = {
    .kp.symbol_name = "freeze_bdev",
    .entry_handler = freeze_bdev_entry_handler,
    .handler = freeze_bdev_ret_handler,
};

static struct kretprobe freezing_slow_path_kp = {
    .kp.symbol_name = "freezing_slow_path",
    .entry_handler = freezing_slow_path_entry_handler,
    .handler = freezing_slow_path_ret_handler,
};

static struct kretprobe from_kgid_kp = {
    .kp.symbol_name = "from_kgid",
    .entry_handler = from_kgid_entry_handler,
    .handler = from_kgid_ret_handler,
};

static struct kretprobe from_kgid_munged_kp = {
    .kp.symbol_name = "from_kgid_munged",
    .entry_handler = from_kgid_munged_entry_handler,
    .handler = from_kgid_munged_ret_handler,
};

static struct kretprobe from_kprojid_kp = {
    .kp.symbol_name = "from_kprojid",
    .entry_handler = from_kprojid_entry_handler,
    .handler = from_kprojid_ret_handler,
};

static struct kretprobe fs_dax_get_by_bdev_kp = {
    .kp.symbol_name = "fs_dax_get_by_bdev",
    .entry_handler = fs_dax_get_by_bdev_entry_handler,
    .handler = fs_dax_get_by_bdev_ret_handler,
};

static struct kretprobe generic_block_bmap_kp = {
    .kp.symbol_name = "generic_block_bmap",
    .entry_handler = generic_block_bmap_entry_handler,
    .handler = generic_block_bmap_ret_handler,
};

static struct kretprobe generic_block_fiemap_kp = {
    .kp.symbol_name = "generic_block_fiemap",
    .entry_handler = generic_block_fiemap_entry_handler,
    .handler = generic_block_fiemap_ret_handler,
};

static struct kretprobe generic_check_addressable_kp = {
    .kp.symbol_name = "generic_check_addressable",
    .entry_handler = generic_check_addressable_entry_handler,
    .handler = generic_check_addressable_ret_handler,
};

static struct kretprobe generic_fh_to_dentry_kp = {
    .kp.symbol_name = "generic_fh_to_dentry",
    .entry_handler = generic_fh_to_dentry_entry_handler,
    .handler = generic_fh_to_dentry_ret_handler,
};

static struct kretprobe generic_fh_to_parent_kp = {
    .kp.symbol_name = "generic_fh_to_parent",
    .entry_handler = generic_fh_to_parent_entry_handler,
    .handler = generic_fh_to_parent_ret_handler,
};

static struct kretprobe generic_file_llseek_size_kp = {
    .kp.symbol_name = "generic_file_llseek_size",
    .entry_handler = generic_file_llseek_size_entry_handler,
    .handler = generic_file_llseek_size_ret_handler,
};

static struct kretprobe generic_file_read_iter_kp = {
    .kp.symbol_name = "generic_file_read_iter",
    .entry_handler = generic_file_read_iter_entry_handler,
    .handler = generic_file_read_iter_ret_handler,
};

static struct kretprobe generic_fillattr_kp = {
    .kp.symbol_name = "generic_fillattr",
    .entry_handler = generic_fillattr_entry_handler,
    .handler = generic_fillattr_ret_handler,
};

static struct kretprobe generic_write_end_kp = {
    .kp.symbol_name = "generic_write_end",
    .entry_handler = generic_write_end_entry_handler,
    .handler = generic_write_end_ret_handler,
};

static struct kretprobe generic_writepages_kp = {
    .kp.symbol_name = "generic_writepages",
    .entry_handler = generic_writepages_entry_handler,
    .handler = generic_writepages_ret_handler,
};

static struct kretprobe get_acl_kp = {
    .kp.symbol_name = "get_acl",
    .entry_handler = get_acl_entry_handler,
    .handler = get_acl_ret_handler,
};

static struct kretprobe grab_cache_page_write_begin_kp = {
    .kp.symbol_name = "grab_cache_page_write_begin",
    .entry_handler = grab_cache_page_write_begin_entry_handler,
    .handler = grab_cache_page_write_begin_ret_handler,
};

static struct kretprobe iget_failed_kp = {
    .kp.symbol_name = "iget_failed",
    .entry_handler = iget_failed_entry_handler,
    .handler = iget_failed_ret_handler,
};

static struct kretprobe iget_locked_kp = {
    .kp.symbol_name = "iget_locked",
    .entry_handler = iget_locked_entry_handler,
    .handler = iget_locked_ret_handler,
};

static struct kretprobe igrab_kp = {
    .kp.symbol_name = "igrab",
    .entry_handler = igrab_entry_handler,
    .handler = igrab_ret_handler,
};

static struct kretprobe ihold_kp = {
    .kp.symbol_name = "ihold",
    .entry_handler = ihold_entry_handler,
    .handler = ihold_ret_handler,
};

static struct kretprobe in_group_p_kp = {
    .kp.symbol_name = "in_group_p",
    .entry_handler = in_group_p_entry_handler,
    .handler = in_group_p_ret_handler,
};

static struct kretprobe inc_nlink_kp = {
    .kp.symbol_name = "inc_nlink",
    .entry_handler = inc_nlink_entry_handler,
    .handler = inc_nlink_ret_handler,
};

static struct kretprobe init_special_inode_kp = {
    .kp.symbol_name = "init_special_inode",
    .entry_handler = init_special_inode_entry_handler,
    .handler = init_special_inode_ret_handler,
};

static struct kretprobe init_timer_key_kp = {
    .kp.symbol_name = "init_timer_key",
    .entry_handler = init_timer_key_entry_handler,
    .handler = init_timer_key_ret_handler,
};

static struct kretprobe init_wait_entry_kp = {
    .kp.symbol_name = "init_wait_entry",
    .entry_handler = init_wait_entry_entry_handler,
    .handler = init_wait_entry_ret_handler,
};

static struct kretprobe init_wait_var_entry_kp = {
    .kp.symbol_name = "init_wait_var_entry",
    .entry_handler = init_wait_var_entry_entry_handler,
    .handler = init_wait_var_entry_ret_handler,
};

static struct kretprobe inode_dio_wait_kp = {
    .kp.symbol_name = "inode_dio_wait",
    .entry_handler = inode_dio_wait_entry_handler,
    .handler = inode_dio_wait_ret_handler,
};

static struct kretprobe inode_init_once_kp = {
    .kp.symbol_name = "inode_init_once",
    .entry_handler = inode_init_once_entry_handler,
    .handler = inode_init_once_ret_handler,
};

static struct kretprobe inode_init_owner_kp = {
    .kp.symbol_name = "inode_init_owner",
    .entry_handler = inode_init_owner_entry_handler,
    .handler = inode_init_owner_ret_handler,
};

static struct kretprobe inode_needs_sync_kp = {
    .kp.symbol_name = "inode_needs_sync",
    .entry_handler = inode_needs_sync_entry_handler,
    .handler = inode_needs_sync_ret_handler,
};

static struct kretprobe inode_newsize_ok_kp = {
    .kp.symbol_name = "inode_newsize_ok",
    .entry_handler = inode_newsize_ok_entry_handler,
    .handler = inode_newsize_ok_ret_handler,
};

static struct kretprobe inode_nohighmem_kp = {
    .kp.symbol_name = "inode_nohighmem",
    .entry_handler = inode_nohighmem_entry_handler,
    .handler = inode_nohighmem_ret_handler,
};

static struct kretprobe inode_owner_or_capable_kp = {
    .kp.symbol_name = "inode_owner_or_capable",
    .entry_handler = inode_owner_or_capable_entry_handler,
    .handler = inode_owner_or_capable_ret_handler,
};

static struct kretprobe inode_set_flags_kp = {
    .kp.symbol_name = "inode_set_flags",
    .entry_handler = inode_set_flags_entry_handler,
    .handler = inode_set_flags_ret_handler,
};

static struct kretprobe insert_inode_locked_kp = {
    .kp.symbol_name = "insert_inode_locked",
    .entry_handler = insert_inode_locked_entry_handler,
    .handler = insert_inode_locked_ret_handler,
};

static struct kretprobe invalidate_bdev_kp = {
    .kp.symbol_name = "invalidate_bdev",
    .entry_handler = invalidate_bdev_entry_handler,
    .handler = invalidate_bdev_ret_handler,
};

static struct kretprobe invalidate_inode_buffers_kp = {
    .kp.symbol_name = "invalidate_inode_buffers",
    .entry_handler = invalidate_inode_buffers_entry_handler,
    .handler = invalidate_inode_buffers_ret_handler,
};

static struct kretprobe iomap_seek_data_kp = {
    .kp.symbol_name = "iomap_seek_data",
    .entry_handler = iomap_seek_data_entry_handler,
    .handler = iomap_seek_data_ret_handler,
};

static struct kretprobe iomap_seek_hole_kp = {
    .kp.symbol_name = "iomap_seek_hole",
    .entry_handler = iomap_seek_hole_entry_handler,
    .handler = iomap_seek_hole_ret_handler,
};

static struct kretprobe iomap_zero_range_kp = {
    .kp.symbol_name = "iomap_zero_range",
    .entry_handler = iomap_zero_range_entry_handler,
    .handler = iomap_zero_range_ret_handler,
};

static struct kretprobe iput_kp = {
    .kp.symbol_name = "iput",
    .entry_handler = iput_entry_handler,
    .handler = iput_ret_handler,
};

static struct kretprobe is_bad_inode_kp = {
    .kp.symbol_name = "is_bad_inode",
    .entry_handler = is_bad_inode_entry_handler,
    .handler = is_bad_inode_ret_handler,
};

static struct kretprobe kern_path_kp = {
    .kp.symbol_name = "kern_path",
    .entry_handler = kern_path_entry_handler,
    .handler = kern_path_ret_handler,
};

static struct kretprobe kstrdup_kp = {
    .kp.symbol_name = "kstrdup",
    .entry_handler = kstrdup_entry_handler,
    .handler = kstrdup_ret_handler,
};

static struct kretprobe kstrndup_kp = {
    .kp.symbol_name = "kstrndup",
    .entry_handler = kstrndup_entry_handler,
    .handler = kstrndup_ret_handler,
};

static struct kretprobe kthread_create_on_node_kp = {
    .kp.symbol_name = "kthread_create_on_node",
    .entry_handler = kthread_create_on_node_entry_handler,
    .handler = kthread_create_on_node_ret_handler,
};

static struct kretprobe kthread_should_stop_kp = {
    .kp.symbol_name = "kthread_should_stop",
    .entry_handler = kthread_should_stop_entry_handler,
    .handler = kthread_should_stop_ret_handler,
};

static struct kretprobe kthread_stop_kp = {
    .kp.symbol_name = "kthread_stop",
    .entry_handler = kthread_stop_entry_handler,
    .handler = kthread_stop_ret_handler,
};

static struct kretprobe ktime_get_kp = {
    .kp.symbol_name = "ktime_get",
    .entry_handler = ktime_get_entry_handler,
    .handler = ktime_get_ret_handler,
};

static struct kretprobe ktime_get_real_seconds_kp = {
    .kp.symbol_name = "ktime_get_real_seconds",
    .entry_handler = ktime_get_real_seconds_entry_handler,
    .handler = ktime_get_real_seconds_ret_handler,
};

static struct kretprobe ktime_get_with_offset_kp = {
    .kp.symbol_name = "ktime_get_with_offset",
    .entry_handler = ktime_get_with_offset_entry_handler,
    .handler = ktime_get_with_offset_ret_handler,
};

static struct kretprobe ll_rw_block_kp = {
    .kp.symbol_name = "ll_rw_block",
    .entry_handler = ll_rw_block_entry_handler,
    .handler = ll_rw_block_ret_handler,
};

static struct kretprobe lock_two_nondirectories_kp = {
    .kp.symbol_name = "lock_two_nondirectories",
    .entry_handler = lock_two_nondirectories_entry_handler,
    .handler = lock_two_nondirectories_ret_handler,
};

static struct kretprobe make_bad_inode_kp = {
    .kp.symbol_name = "make_bad_inode",
    .entry_handler = make_bad_inode_entry_handler,
    .handler = make_bad_inode_ret_handler,
};

static struct kretprobe make_kgid_kp = {
    .kp.symbol_name = "make_kgid",
    .entry_handler = make_kgid_entry_handler,
    .handler = make_kgid_ret_handler,
};

static struct kretprobe make_kprojid_kp = {
    .kp.symbol_name = "make_kprojid",
    .entry_handler = make_kprojid_entry_handler,
    .handler = make_kprojid_ret_handler,
};

static struct kretprobe make_kuid_kp = {
    .kp.symbol_name = "make_kuid",
    .entry_handler = make_kuid_entry_handler,
    .handler = make_kuid_ret_handler,
};

static struct kretprobe mark_buffer_dirty_kp = {
    .kp.symbol_name = "mark_buffer_dirty",
    .entry_handler = mark_buffer_dirty_entry_handler,
    .handler = mark_buffer_dirty_ret_handler,
};

static struct kretprobe mark_buffer_dirty_inode_kp = {
    .kp.symbol_name = "mark_buffer_dirty_inode",
    .entry_handler = mark_buffer_dirty_inode_entry_handler,
    .handler = mark_buffer_dirty_inode_ret_handler,
};

static struct kretprobe mb_cache_create_kp = {
    .kp.symbol_name = "mb_cache_create",
    .entry_handler = mb_cache_create_entry_handler,
    .handler = mb_cache_create_ret_handler,
};

static struct kretprobe mb_cache_destroy_kp = {
    .kp.symbol_name = "mb_cache_destroy",
    .entry_handler = mb_cache_destroy_entry_handler,
    .handler = mb_cache_destroy_ret_handler,
};

static struct kretprobe mb_cache_entry_create_kp = {
    .kp.symbol_name = "mb_cache_entry_create",
    .entry_handler = mb_cache_entry_create_entry_handler,
    .handler = mb_cache_entry_create_ret_handler,
};

static struct kretprobe mb_cache_entry_delete_kp = {
    .kp.symbol_name = "mb_cache_entry_delete",
    .entry_handler = mb_cache_entry_delete_entry_handler,
    .handler = mb_cache_entry_delete_ret_handler,
};

static struct kretprobe mb_cache_entry_find_first_kp = {
    .kp.symbol_name = "mb_cache_entry_find_first",
    .entry_handler = mb_cache_entry_find_first_entry_handler,
    .handler = mb_cache_entry_find_first_ret_handler,
};

static struct kretprobe mb_cache_entry_find_next_kp = {
    .kp.symbol_name = "mb_cache_entry_find_next",
    .entry_handler = mb_cache_entry_find_next_entry_handler,
    .handler = mb_cache_entry_find_next_ret_handler,
};

static struct kretprobe mb_cache_entry_get_kp = {
    .kp.symbol_name = "mb_cache_entry_get",
    .entry_handler = mb_cache_entry_get_entry_handler,
    .handler = mb_cache_entry_get_ret_handler,
};

static struct kretprobe mb_cache_entry_touch_kp = {
    .kp.symbol_name = "mb_cache_entry_touch",
    .entry_handler = mb_cache_entry_touch_entry_handler,
    .handler = mb_cache_entry_touch_ret_handler,
};

static struct kretprobe mnt_drop_write_file_kp = {
    .kp.symbol_name = "mnt_drop_write_file",
    .entry_handler = mnt_drop_write_file_entry_handler,
    .handler = mnt_drop_write_file_ret_handler,
};

static struct kretprobe mnt_want_write_file_kp = {
    .kp.symbol_name = "mnt_want_write_file",
    .entry_handler = mnt_want_write_file_entry_handler,
    .handler = mnt_want_write_file_ret_handler,
};

static struct kretprobe mod_timer_kp = {
    .kp.symbol_name = "mod_timer",
    .entry_handler = mod_timer_entry_handler,
    .handler = mod_timer_ret_handler,
};

static struct kretprobe mount_bdev_kp = {
    .kp.symbol_name = "mount_bdev",
    .entry_handler = mount_bdev_entry_handler,
    .handler = mount_bdev_ret_handler,
};

static struct kretprobe new_inode_kp = {
    .kp.symbol_name = "new_inode",
    .entry_handler = new_inode_entry_handler,
    .handler = new_inode_ret_handler,
};

static struct kretprobe page_mapped_kp = {
    .kp.symbol_name = "page_mapped",
    .entry_handler = page_mapped_entry_handler,
    .handler = page_mapped_ret_handler,
};

static struct kretprobe page_zero_new_buffers_kp = {
    .kp.symbol_name = "page_zero_new_buffers",
    .entry_handler = page_zero_new_buffers_entry_handler,
    .handler = page_zero_new_buffers_ret_handler,
};

static struct kretprobe pagecache_get_page_kp = {
    .kp.symbol_name = "pagecache_get_page",
    .entry_handler = pagecache_get_page_entry_handler,
    .handler = pagecache_get_page_ret_handler,
};

static struct kretprobe pagecache_isize_extended_kp = {
    .kp.symbol_name = "pagecache_isize_extended",
    .entry_handler = pagecache_isize_extended_entry_handler,
    .handler = pagecache_isize_extended_ret_handler,
};

static struct kretprobe pagevec_lookup_range_kp = {
    .kp.symbol_name = "pagevec_lookup_range",
    .entry_handler = pagevec_lookup_range_entry_handler,
    .handler = pagevec_lookup_range_ret_handler,
};

static struct kretprobe parse_options_kp = {
    .kp.symbol_name = "parse_options",
    .entry_handler = parse_options_entry_handler,
    .handler = parse_options_ret_handler,
};

static struct kretprobe path_put_kp = {
    .kp.symbol_name = "path_put",
    .entry_handler = path_put_entry_handler,
    .handler = path_put_ret_handler,
};

static struct kretprobe percpu_down_write_kp = {
    .kp.symbol_name = "percpu_down_write",
    .entry_handler = percpu_down_write_entry_handler,
    .handler = percpu_down_write_ret_handler,
};

static struct kretprobe percpu_free_rwsem_kp = {
    .kp.symbol_name = "percpu_free_rwsem",
    .entry_handler = percpu_free_rwsem_entry_handler,
    .handler = percpu_free_rwsem_ret_handler,
};

static struct kretprobe percpu_up_write_kp = {
    .kp.symbol_name = "percpu_up_write",
    .entry_handler = percpu_up_write_entry_handler,
    .handler = percpu_up_write_ret_handler,
};

static struct kretprobe posix_acl_alloc_kp = {
    .kp.symbol_name = "posix_acl_alloc",
    .entry_handler = posix_acl_alloc_entry_handler,
    .handler = posix_acl_alloc_ret_handler,
};

static struct kretprobe posix_acl_chmod_kp = {
    .kp.symbol_name = "posix_acl_chmod",
    .entry_handler = posix_acl_chmod_entry_handler,
    .handler = posix_acl_chmod_ret_handler,
};

static struct kretprobe posix_acl_create_kp = {
    .kp.symbol_name = "posix_acl_create",
    .entry_handler = posix_acl_create_entry_handler,
    .handler = posix_acl_create_ret_handler,
};

static struct kretprobe posix_acl_update_mode_kp = {
    .kp.symbol_name = "posix_acl_update_mode",
    .entry_handler = posix_acl_update_mode_entry_handler,
    .handler = posix_acl_update_mode_ret_handler,
};

static struct kretprobe prepare_to_wait_event_kp = {
    .kp.symbol_name = "prepare_to_wait_event",
    .entry_handler = prepare_to_wait_event_entry_handler,
    .handler = prepare_to_wait_event_ret_handler,
};

static struct kretprobe printk_kp = {
    .kp.symbol_name = "printk",
    .entry_handler = printk_entry_handler,
    .handler = printk_ret_handler,
};

static struct kretprobe put_dax_kp = {
    .kp.symbol_name = "put_dax",
    .entry_handler = put_dax_entry_handler,
    .handler = put_dax_ret_handler,
};

static struct kretprobe queue_work_on_kp = {
    .kp.symbol_name = "queue_work_on",
    .entry_handler = queue_work_on_entry_handler,
    .handler = queue_work_on_ret_handler,
};

static struct kretprobe read_cache_pages_kp = {
    .kp.symbol_name = "read_cache_pages",
    .entry_handler = read_cache_pages_entry_handler,
    .handler = read_cache_pages_ret_handler,
};

static struct kretprobe redirty_page_for_writepage_kp = {
    .kp.symbol_name = "redirty_page_for_writepage",
    .entry_handler = redirty_page_for_writepage_entry_handler,
    .handler = redirty_page_for_writepage_ret_handler,
};

static struct kretprobe register_filesystem_kp = {
    .kp.symbol_name = "register_filesystem",
    .entry_handler = register_filesystem_entry_handler,
    .handler = register_filesystem_ret_handler,
};

static struct kretprobe register_shrinker_kp = {
    .kp.symbol_name = "register_shrinker",
    .entry_handler = register_shrinker_entry_handler,
    .handler = register_shrinker_ret_handler,
};

static struct kretprobe sb_min_blocksize_kp = {
    .kp.symbol_name = "sb_min_blocksize",
    .entry_handler = sb_min_blocksize_entry_handler,
    .handler = sb_min_blocksize_ret_handler,
};

static struct kretprobe sb_set_blocksize_kp = {
    .kp.symbol_name = "sb_set_blocksize",
    .entry_handler = sb_set_blocksize_entry_handler,
    .handler = sb_set_blocksize_ret_handler,
};

static struct kretprobe seq_escape_kp = {
    .kp.symbol_name = "seq_escape",
    .entry_handler = seq_escape_entry_handler,
    .handler = seq_escape_ret_handler,
};

static struct kretprobe seq_printf_kp = {
    .kp.symbol_name = "seq_printf",
    .entry_handler = seq_printf_entry_handler,
    .handler = seq_printf_ret_handler,
};

static struct kretprobe seq_putc_kp = {
    .kp.symbol_name = "seq_putc",
    .entry_handler = seq_putc_entry_handler,
    .handler = seq_putc_ret_handler,
};

static struct kretprobe seq_puts_kp = {
    .kp.symbol_name = "seq_puts",
    .entry_handler = seq_puts_entry_handler,
    .handler = seq_puts_ret_handler,
};

static struct kretprobe set_blocksize_kp = {
    .kp.symbol_name = "set_blocksize",
    .entry_handler = set_blocksize_entry_handler,
    .handler = set_blocksize_ret_handler,
};

static struct kretprobe set_cached_acl_kp = {
    .kp.symbol_name = "set_cached_acl",
    .entry_handler = set_cached_acl_entry_handler,
    .handler = set_cached_acl_ret_handler,
};

static struct kretprobe set_nlink_kp = {
    .kp.symbol_name = "set_nlink",
    .entry_handler = set_nlink_entry_handler,
    .handler = set_nlink_ret_handler,
};

static struct kretprobe set_task_ioprio_kp = {
    .kp.symbol_name = "set_task_ioprio",
    .entry_handler = set_task_ioprio_entry_handler,
    .handler = set_task_ioprio_ret_handler,
};

static struct kretprobe setattr_copy_kp = {
    .kp.symbol_name = "setattr_copy",
    .entry_handler = setattr_copy_entry_handler,
    .handler = setattr_copy_ret_handler,
};

static struct kretprobe setattr_prepare_kp = {
    .kp.symbol_name = "setattr_prepare",
    .entry_handler = setattr_prepare_entry_handler,
    .handler = setattr_prepare_ret_handler,
};

static struct kretprobe submit_bh_kp = {
    .kp.symbol_name = "submit_bh",
    .entry_handler = submit_bh_entry_handler,
    .handler = submit_bh_ret_handler,
};

static struct kretprobe submit_bio_kp = {
    .kp.symbol_name = "submit_bio",
    .entry_handler = submit_bio_entry_handler,
    .handler = submit_bio_ret_handler,
};

static struct kretprobe submit_bio_wait_kp = {
    .kp.symbol_name = "submit_bio_wait",
    .entry_handler = submit_bio_wait_entry_handler,
    .handler = submit_bio_wait_ret_handler,
};

static struct kretprobe sync_blockdev_kp = {
    .kp.symbol_name = "sync_blockdev",
    .entry_handler = sync_blockdev_entry_handler,
    .handler = sync_blockdev_ret_handler,
};

static struct kretprobe sync_dirty_buffer_kp = {
    .kp.symbol_name = "sync_dirty_buffer",
    .entry_handler = sync_dirty_buffer_entry_handler,
    .handler = sync_dirty_buffer_ret_handler,
};

static struct kretprobe sync_filesystem_kp = {
    .kp.symbol_name = "sync_filesystem",
    .entry_handler = sync_filesystem_entry_handler,
    .handler = sync_filesystem_ret_handler,
};

static struct kretprobe sync_inode_metadata_kp = {
    .kp.symbol_name = "sync_inode_metadata",
    .entry_handler = sync_inode_metadata_entry_handler,
    .handler = sync_inode_metadata_ret_handler,
};

static struct kretprobe sync_mapping_buffers_kp = {
    .kp.symbol_name = "sync_mapping_buffers",
    .entry_handler = sync_mapping_buffers_entry_handler,
    .handler = sync_mapping_buffers_ret_handler,
};

static struct kretprobe tag_pages_for_writeback_kp = {
    .kp.symbol_name = "tag_pages_for_writeback",
    .entry_handler = tag_pages_for_writeback_entry_handler,
    .handler = tag_pages_for_writeback_ret_handler,
};

static struct kretprobe thaw_bdev_kp = {
    .kp.symbol_name = "thaw_bdev",
    .entry_handler = thaw_bdev_entry_handler,
    .handler = thaw_bdev_ret_handler,
};

static struct kretprobe touch_atime_kp = {
    .kp.symbol_name = "touch_atime",
    .entry_handler = touch_atime_entry_handler,
    .handler = touch_atime_ret_handler,
};

static struct kretprobe truncate_inode_pages_kp = {
    .kp.symbol_name = "truncate_inode_pages",
    .entry_handler = truncate_inode_pages_entry_handler,
    .handler = truncate_inode_pages_ret_handler,
};

static struct kretprobe truncate_inode_pages_final_kp = {
    .kp.symbol_name = "truncate_inode_pages_final",
    .entry_handler = truncate_inode_pages_final_entry_handler,
    .handler = truncate_inode_pages_final_ret_handler,
};

static struct kretprobe truncate_pagecache_kp = {
    .kp.symbol_name = "truncate_pagecache",
    .entry_handler = truncate_pagecache_entry_handler,
    .handler = truncate_pagecache_ret_handler,
};

static struct kretprobe truncate_pagecache_range_kp = {
    .kp.symbol_name = "truncate_pagecache_range",
    .entry_handler = truncate_pagecache_range_entry_handler,
    .handler = truncate_pagecache_range_ret_handler,
};

static struct kretprobe try_to_free_buffers_kp = {
    .kp.symbol_name = "try_to_free_buffers",
    .entry_handler = try_to_free_buffers_entry_handler,
    .handler = try_to_free_buffers_ret_handler,
};

static struct kretprobe try_to_writeback_inodes_sb_kp = {
    .kp.symbol_name = "try_to_writeback_inodes_sb",
    .entry_handler = try_to_writeback_inodes_sb_entry_handler,
    .handler = try_to_writeback_inodes_sb_ret_handler,
};

static struct kretprobe unlock_buffer_kp = {
    .kp.symbol_name = "unlock_buffer",
    .entry_handler = unlock_buffer_entry_handler,
    .handler = unlock_buffer_ret_handler,
};

static struct kretprobe unlock_new_inode_kp = {
    .kp.symbol_name = "unlock_new_inode",
    .entry_handler = unlock_new_inode_entry_handler,
    .handler = unlock_new_inode_ret_handler,
};

static struct kretprobe unlock_two_nondirectories_kp = {
    .kp.symbol_name = "unlock_two_nondirectories",
    .entry_handler = unlock_two_nondirectories_entry_handler,
    .handler = unlock_two_nondirectories_ret_handler,
};

static struct kretprobe unregister_filesystem_kp = {
    .kp.symbol_name = "unregister_filesystem",
    .entry_handler = unregister_filesystem_entry_handler,
    .handler = unregister_filesystem_ret_handler,
};

static struct kretprobe vfs_fsync_range_kp = {
    .kp.symbol_name = "vfs_fsync_range",
    .entry_handler = vfs_fsync_range_entry_handler,
    .handler = vfs_fsync_range_ret_handler,
};

static struct kretprobe vfs_setpos_kp = {
    .kp.symbol_name = "vfs_setpos",
    .entry_handler = vfs_setpos_entry_handler,
    .handler = vfs_setpos_ret_handler,
};




#endif // MONITOR_H


