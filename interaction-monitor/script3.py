inode_text = '''
i_mode
i_opflags
i_uid
i_gid
i_flags
i_op
i_sb
i_mapping
i_rdev
i_size
i_atime
i_mtime
i_ctime
i_bytes
i_blkbits
i_write_hint
i_blocks
i_state
i_fop
i_flctx
i_generation
i_private
'''

	# unsigned long		dirtied_when
	# unsigned long		dirtied_time_when

inode_fields = []
inode_fields = inode_text.split('\n')

for item in inode_fields:
    print('\tif (shadow->%s != origin->%s) {\n\t\tpr_err("alter at inode %u\\n", origin->i_ino);\n\t}')
    print('\tshadow->%s = origin->%s;' % (item, item))

for item in inode_fields:
    print('\tshadow->%s = origin->%s;' % (item, item))
# for item in inode_fields:
#     print('\torigin->%s = shadow->%s;' % (item, item))