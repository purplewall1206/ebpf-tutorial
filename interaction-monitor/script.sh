echo "===================================="
echo __alloc_percpu
sudo bpftrace -l | grep __alloc_percpu
echo "===================================="
echo "===================================="
echo __alloc_workqueue_key
sudo bpftrace -l | grep __alloc_workqueue_key
echo "===================================="
echo "===================================="
echo ___ratelimit
sudo bpftrace -l | grep ___ratelimit
echo "===================================="
echo "===================================="
echo __generic_file_write_iter
sudo bpftrace -l | grep __generic_file_write_iter
echo "===================================="
echo "===================================="
echo __init_rwsem
sudo bpftrace -l | grep __init_rwsem
echo "===================================="
echo "===================================="
echo __bdev_dax_supported
sudo bpftrace -l | grep __bdev_dax_supported
echo "===================================="
echo "===================================="
echo bdevname
sudo bpftrace -l | grep bdevname
echo "===================================="
echo "===================================="
echo blkdev_issue_discard
sudo bpftrace -l | grep blkdev_issue_discard
echo "===================================="
echo "===================================="
echo __cleancache_get_page
sudo bpftrace -l | grep __cleancache_get_page
echo "===================================="
echo "===================================="
echo __cleancache_init_fs
sudo bpftrace -l | grep __cleancache_init_fs
echo "===================================="
echo "===================================="
echo __filemap_set_wb_err
sudo bpftrace -l | grep __filemap_set_wb_err
echo "===================================="
echo "===================================="
echo __init_waitqueue_head
sudo bpftrace -l | grep __init_waitqueue_head
echo "===================================="
echo "===================================="
echo __lock_page
sudo bpftrace -l | grep __lock_page
echo "===================================="
echo "===================================="
echo __might_fault
sudo bpftrace -l | grep __might_fault
echo "===================================="
echo "===================================="
echo __might_sleep
sudo bpftrace -l | grep __might_sleep
echo "===================================="
echo "===================================="
echo __mutex_init
sudo bpftrace -l | grep __mutex_init
echo "===================================="
echo "===================================="
echo __page_ref_mod
sudo bpftrace -l | grep __page_ref_mod
echo "===================================="
echo "===================================="
echo __page_ref_mod_and_test
sudo bpftrace -l | grep __page_ref_mod_and_test
echo "===================================="
echo "===================================="
echo __pagevec_release
sudo bpftrace -l | grep __pagevec_release
echo "===================================="
echo "===================================="
echo __percpu_down_read
sudo bpftrace -l | grep __percpu_down_read
echo "===================================="
echo "===================================="
echo __percpu_init_rwsem
sudo bpftrace -l | grep __percpu_init_rwsem
echo "===================================="
echo "===================================="
echo __percpu_up_read
sudo bpftrace -l | grep __percpu_up_read
echo "===================================="
echo "===================================="
echo __put_devmap_managed_page
sudo bpftrace -l | grep __put_devmap_managed_page
echo "===================================="
echo "===================================="
echo __put_page
sudo bpftrace -l | grep __put_page
echo "===================================="
echo "===================================="
echo __raw_spin_lock_init
sudo bpftrace -l | grep __raw_spin_lock_init
echo "===================================="
echo "===================================="
echo __refrigerator
sudo bpftrace -l | grep __refrigerator
echo "===================================="
echo "===================================="
echo __rwlock_init
sudo bpftrace -l | grep __rwlock_init
echo "===================================="
echo "===================================="
echo __set_page_dirty_nobuffers
sudo bpftrace -l | grep __set_page_dirty_nobuffers
echo "===================================="
echo "===================================="
echo __test_set_page_writeback
sudo bpftrace -l | grep __test_set_page_writeback
echo "===================================="
echo "===================================="
echo __var_waitqueue
sudo bpftrace -l | grep __var_waitqueue
echo "===================================="
echo "===================================="
echo __wake_up
sudo bpftrace -l | grep __wake_up
echo "===================================="
echo "===================================="
echo __warn_printk
sudo bpftrace -l | grep __warn_printk
echo "===================================="
echo "===================================="
echo _cond_resched
sudo bpftrace -l | grep _cond_resched
echo "===================================="
echo "===================================="
echo _copy_from_user
sudo bpftrace -l | grep _copy_from_user
echo "===================================="
echo "===================================="
echo _copy_to_user
sudo bpftrace -l | grep _copy_to_user
echo "===================================="
echo "===================================="
echo _raw_read_lock
sudo bpftrace -l | grep _raw_read_lock
echo "===================================="
echo "===================================="
echo _raw_read_unlock
sudo bpftrace -l | grep _raw_read_unlock
echo "===================================="
echo "===================================="
echo _raw_spin_lock
sudo bpftrace -l | grep _raw_spin_lock
echo "===================================="
echo "===================================="
echo _raw_spin_lock_irqsave
sudo bpftrace -l | grep _raw_spin_lock_irqsave
echo "===================================="
echo "===================================="
echo _raw_spin_trylock
sudo bpftrace -l | grep _raw_spin_trylock
echo "===================================="
echo "===================================="
echo _raw_spin_unlock
sudo bpftrace -l | grep _raw_spin_unlock
echo "===================================="
echo "===================================="
echo _raw_spin_unlock_irqrestore
sudo bpftrace -l | grep _raw_spin_unlock_irqrestore
echo "===================================="
echo "===================================="
echo _raw_write_lock
sudo bpftrace -l | grep _raw_write_lock
echo "===================================="
echo "===================================="
echo _raw_write_trylock
sudo bpftrace -l | grep _raw_write_trylock
echo "===================================="
echo "===================================="
echo _raw_write_unlock
sudo bpftrace -l | grep _raw_write_unlock
echo "===================================="
echo "===================================="
echo add_to_page_cache_lru
sudo bpftrace -l | grep add_to_page_cache_lru
echo "===================================="
echo "===================================="
echo bcmp
sudo bpftrace -l | grep bcmp
echo "===================================="
echo "===================================="
echo bdev_read_only
sudo bpftrace -l | grep bdev_read_only
echo "===================================="
echo "===================================="
echo bdevname
sudo bpftrace -l | grep bdevname
echo "===================================="
echo "===================================="
echo bio_add_page
sudo bpftrace -l | grep bio_add_page
echo "===================================="
echo "===================================="
echo bio_alloc_bioset
sudo bpftrace -l | grep bio_alloc_bioset
echo "===================================="
echo "===================================="
echo bio_associate_blkcg
sudo bpftrace -l | grep bio_associate_blkcg
echo "===================================="
echo "===================================="
echo bio_devname
sudo bpftrace -l | grep bio_devname
echo "===================================="
echo "===================================="
echo bio_put
sudo bpftrace -l | grep bio_put
echo "===================================="
echo "===================================="
echo blk_finish_plug
sudo bpftrace -l | grep blk_finish_plug
echo "===================================="
echo "===================================="
echo blk_start_plug
sudo bpftrace -l | grep blk_start_plug
echo "===================================="
echo "===================================="
echo blk_status_to_errno
sudo bpftrace -l | grep blk_status_to_errno
echo "===================================="
echo "===================================="
echo blkdev_issue_discard
sudo bpftrace -l | grep blkdev_issue_discard
echo "===================================="
echo "===================================="
echo blkdev_issue_flush
sudo bpftrace -l | grep blkdev_issue_flush
echo "===================================="
echo "===================================="
echo blkdev_issue_zeroout
sudo bpftrace -l | grep blkdev_issue_zeroout
echo "===================================="
echo "===================================="
echo call_rcu_sched
sudo bpftrace -l | grep call_rcu_sched
echo "===================================="
echo "===================================="
echo capable
sudo bpftrace -l | grep capable
echo "===================================="
echo "===================================="
echo clear_page_dirty_for_io
sudo bpftrace -l | grep clear_page_dirty_for_io
echo "===================================="
echo "===================================="
echo complete
sudo bpftrace -l | grep complete
echo "===================================="
echo "===================================="
echo congestion_wait
sudo bpftrace -l | grep congestion_wait
echo "===================================="
echo "===================================="
echo crypto_alloc_shash
sudo bpftrace -l | grep crypto_alloc_shash
echo "===================================="
echo "===================================="
echo crypto_destroy_tfm
sudo bpftrace -l | grep crypto_destroy_tfm
echo "===================================="
echo "===================================="
echo crypto_shash_update
sudo bpftrace -l | grep crypto_shash_update
echo "===================================="
echo "===================================="
echo debug_check_no_locks_held
sudo bpftrace -l | grep debug_check_no_locks_held
echo "===================================="
echo "===================================="
echo debug_lockdep_rcu_enabled
sudo bpftrace -l | grep debug_lockdep_rcu_enabled
echo "===================================="
echo "===================================="
echo del_timer_sync
sudo bpftrace -l | grep del_timer_sync
echo "===================================="
echo "===================================="
echo destroy_workqueue
sudo bpftrace -l | grep destroy_workqueue
echo "===================================="
echo "===================================="
echo down_read
sudo bpftrace -l | grep down_read
echo "===================================="
echo "===================================="
echo down_read_trylock
sudo bpftrace -l | grep down_read_trylock
echo "===================================="
echo "===================================="
echo down_write
sudo bpftrace -l | grep down_write
echo "===================================="
echo "===================================="
echo down_write_nested
sudo bpftrace -l | grep down_write_nested
echo "===================================="
echo "===================================="
echo down_write_trylock
sudo bpftrace -l | grep down_write_trylock
echo "===================================="
echo "===================================="
echo dump_page
sudo bpftrace -l | grep dump_page
echo "===================================="
echo "===================================="
echo dump_stack
sudo bpftrace -l | grep dump_stack
echo "===================================="
echo "===================================="
echo end_page_writeback
sudo bpftrace -l | grep end_page_writeback
echo "===================================="
echo "===================================="
echo event_triggers_call
sudo bpftrace -l | grep event_triggers_call
echo "===================================="
echo "===================================="
echo file_check_and_advance_wb_err
sudo bpftrace -l | grep file_check_and_advance_wb_err
echo "===================================="
echo "===================================="
echo file_write_and_wait_range
sudo bpftrace -l | grep file_write_and_wait_range
echo "===================================="
echo "===================================="
echo filemap_fault
sudo bpftrace -l | grep filemap_fault
echo "===================================="
echo "===================================="
echo filemap_flush
sudo bpftrace -l | grep filemap_flush
echo "===================================="
echo "===================================="
echo filemap_write_and_wait
sudo bpftrace -l | grep filemap_write_and_wait
echo "===================================="
echo "===================================="
echo filemap_write_and_wait_range
sudo bpftrace -l | grep filemap_write_and_wait_range
echo "===================================="
echo "===================================="
echo finish_wait
sudo bpftrace -l | grep finish_wait
echo "===================================="
echo "===================================="
echo flush_workqueue
sudo bpftrace -l | grep flush_workqueue
echo "===================================="
echo "===================================="
echo freezing_slow_path
sudo bpftrace -l | grep freezing_slow_path
echo "===================================="
echo "===================================="
echo from_kgid
sudo bpftrace -l | grep from_kgid
echo "===================================="
echo "===================================="
echo from_kgid_munged
sudo bpftrace -l | grep from_kgid_munged
echo "===================================="
echo "===================================="
echo from_kprojid
sudo bpftrace -l | grep from_kprojid
echo "===================================="
echo "===================================="
echo from_kuid
sudo bpftrace -l | grep from_kuid
echo "===================================="
echo "===================================="
echo from_kuid_munged
sudo bpftrace -l | grep from_kuid_munged
echo "===================================="
echo "===================================="
echo fs_dax_get_by_bdev
sudo bpftrace -l | grep fs_dax_get_by_bdev
echo "===================================="
echo "===================================="
echo generate_random_uuid
sudo bpftrace -l | grep generate_random_uuid
echo "===================================="
echo "===================================="
echo generic_file_read_iter
sudo bpftrace -l | grep generic_file_read_iter
echo "===================================="
echo "===================================="
echo generic_write_checks
sudo bpftrace -l | grep generic_write_checks
echo "===================================="
echo "===================================="
echo generic_writepages
sudo bpftrace -l | grep generic_writepages
echo "===================================="
echo "===================================="
echo get_zeroed_page
sudo bpftrace -l | grep get_zeroed_page
echo "===================================="
echo "===================================="
echo grab_cache_page_write_begin
sudo bpftrace -l | grep grab_cache_page_write_begin
echo "===================================="
echo "===================================="
echo in_group_p
sudo bpftrace -l | grep in_group_p
echo "===================================="
echo "===================================="
echo init_inodecache
sudo bpftrace -l | grep init_inodecache
echo "===================================="
echo "===================================="
echo init_timer_key
sudo bpftrace -l | grep init_timer_key
echo "===================================="
echo "===================================="
echo init_wait_entry
sudo bpftrace -l | grep init_wait_entry
echo "===================================="
echo "===================================="
echo init_wait_var_entry
sudo bpftrace -l | grep init_wait_var_entry
echo "===================================="
echo "===================================="
echo kobject_create_and_add
sudo bpftrace -l | grep kobject_create_and_add
echo "===================================="
echo "===================================="
echo kobject_del
sudo bpftrace -l | grep kobject_del
echo "===================================="
echo "===================================="
echo kobject_init_and_add
sudo bpftrace -l | grep kobject_init_and_add
echo "===================================="
echo "===================================="
echo kobject_put
sudo bpftrace -l | grep kobject_put
echo "===================================="
echo "===================================="
echo kstrdup
sudo bpftrace -l | grep kstrdup
echo "===================================="
echo "===================================="
echo kstrndup
sudo bpftrace -l | grep kstrndup
echo "===================================="
echo "===================================="
echo kthread_create_on_node
sudo bpftrace -l | grep kthread_create_on_node
echo "===================================="
echo "===================================="
echo kthread_should_stop
sudo bpftrace -l | grep kthread_should_stop
echo "===================================="
echo "===================================="
echo kthread_stop
sudo bpftrace -l | grep kthread_stop
echo "===================================="
echo "===================================="
echo ktime_get
sudo bpftrace -l | grep ktime_get
echo "===================================="
echo "===================================="
echo ktime_get_real_seconds
sudo bpftrace -l | grep ktime_get_real_seconds
echo "===================================="
echo "===================================="
echo ktime_get_with_offset
sudo bpftrace -l | grep ktime_get_with_offset
echo "===================================="
echo "===================================="
echo lock_acquire
sudo bpftrace -l | grep lock_acquire
echo "===================================="
echo "===================================="
echo lock_is_held_type
sudo bpftrace -l | grep lock_is_held_type
echo "===================================="
echo "===================================="
echo lock_release
sudo bpftrace -l | grep lock_release
echo "===================================="
echo "===================================="
echo lockdep_init_map
sudo bpftrace -l | grep lockdep_init_map
echo "===================================="
echo "===================================="
echo lockdep_rcu_suspicious
sudo bpftrace -l | grep lockdep_rcu_suspicious
echo "===================================="
echo "===================================="
echo make_kgid
sudo bpftrace -l | grep make_kgid
echo "===================================="
echo "===================================="
echo make_kprojid
sudo bpftrace -l | grep make_kprojid
echo "===================================="
echo "===================================="
echo make_kuid
sudo bpftrace -l | grep make_kuid
echo "===================================="
echo "===================================="
echo mapping_tagged
sudo bpftrace -l | grep mapping_tagged
echo "===================================="
echo "===================================="
echo mod_timer
sudo bpftrace -l | grep mod_timer
echo "===================================="
echo "===================================="
echo mutex_lock_nested
sudo bpftrace -l | grep mutex_lock_nested
echo "===================================="
echo "===================================="
echo mutex_unlock
sudo bpftrace -l | grep mutex_unlock
echo "===================================="
echo "===================================="
echo nsecs_to_jiffies
sudo bpftrace -l | grep nsecs_to_jiffies
echo "===================================="
echo "===================================="
echo page_cache_sync_readahead
sudo bpftrace -l | grep page_cache_sync_readahead
echo "===================================="
echo "===================================="
echo page_mapped
sudo bpftrace -l | grep page_mapped
echo "===================================="
echo "===================================="
echo pagecache_get_page
sudo bpftrace -l | grep pagecache_get_page
echo "===================================="
echo "===================================="
echo pagecache_isize_extended
sudo bpftrace -l | grep pagecache_isize_extended
echo "===================================="
echo "===================================="
echo pagevec_lookup_range
sudo bpftrace -l | grep pagevec_lookup_range
echo "===================================="
echo "===================================="
echo pagevec_lookup_range_tag
sudo bpftrace -l | grep pagevec_lookup_range_tag
echo "===================================="
echo "===================================="
echo panic
sudo bpftrace -l | grep panic
echo "===================================="
echo "===================================="
echo parse_options
sudo bpftrace -l | grep parse_options
echo "===================================="
echo "===================================="
echo percpu_down_write
sudo bpftrace -l | grep percpu_down_write
echo "===================================="
echo "===================================="
echo percpu_free_rwsem
sudo bpftrace -l | grep percpu_free_rwsem
echo "===================================="
echo "===================================="
echo percpu_up_write
sudo bpftrace -l | grep percpu_up_write
echo "===================================="
echo "===================================="
echo perf_trace_buf_alloc
sudo bpftrace -l | grep perf_trace_buf_alloc
echo "===================================="
echo "===================================="
echo perf_trace_run_bpf_submit
sudo bpftrace -l | grep perf_trace_run_bpf_submit
echo "===================================="
echo "===================================="
echo prandom_u32
sudo bpftrace -l | grep prandom_u32
echo "===================================="
echo "===================================="
echo prepare_to_wait_event
sudo bpftrace -l | grep prepare_to_wait_event
echo "===================================="
echo "===================================="
echo print_hex_dump
sudo bpftrace -l | grep print_hex_dump
echo "===================================="
echo "===================================="
echo printk
sudo bpftrace -l | grep printk
echo "===================================="
echo "===================================="
echo put_dax
sudo bpftrace -l | grep put_dax
echo "===================================="
echo "===================================="
echo queue_work_on
sudo bpftrace -l | grep queue_work_on
echo "===================================="
echo "===================================="
echo rcu_barrier
sudo bpftrace -l | grep rcu_barrier
echo "===================================="
echo "===================================="
echo rcu_is_watching
sudo bpftrace -l | grep rcu_is_watching
echo "===================================="
echo "===================================="
echo rcu_lock_acquire
sudo bpftrace -l | grep rcu_lock_acquire
echo "===================================="
echo "===================================="
echo rcu_lock_release
sudo bpftrace -l | grep rcu_lock_release
echo "===================================="
echo "===================================="
echo rcu_read_lock_held
sudo bpftrace -l | grep rcu_read_lock_held
echo "===================================="
echo "===================================="
echo rcu_read_lock_sched_held
sudo bpftrace -l | grep rcu_read_lock_sched_held
echo "===================================="
echo "===================================="
echo rcu_sync_lockdep_assert
sudo bpftrace -l | grep rcu_sync_lockdep_assert
echo "===================================="
echo "===================================="
echo read_cache_page
sudo bpftrace -l | grep read_cache_page
echo "===================================="
echo "===================================="
echo redirty_page_for_writepage
sudo bpftrace -l | grep redirty_page_for_writepage
echo "===================================="
echo "===================================="
echo register_shrinker
sudo bpftrace -l | grep register_shrinker
echo "===================================="
echo "===================================="
echo schedule
sudo bpftrace -l | grep schedule
echo "===================================="
echo "===================================="
echo schedule_timeout_interruptible
sudo bpftrace -l | grep schedule_timeout_interruptible
echo "===================================="
echo "===================================="
echo schedule_timeout_uninterruptible
sudo bpftrace -l | grep schedule_timeout_uninterruptible
echo "===================================="
echo "===================================="
echo security_inode_init_security
sudo bpftrace -l | grep security_inode_init_security
echo "===================================="
echo "===================================="
echo set_task_ioprio
sudo bpftrace -l | grep set_task_ioprio
echo "===================================="
echo "===================================="
echo snprintf
sudo bpftrace -l | grep snprintf
echo "===================================="
echo "===================================="
echo submit_bio
sudo bpftrace -l | grep submit_bio
echo "===================================="
echo "===================================="
echo submit_bio_wait
sudo bpftrace -l | grep submit_bio_wait
echo "===================================="
echo "===================================="
echo synchronize_sched
sudo bpftrace -l | grep synchronize_sched
echo "===================================="
echo "===================================="
echo tag_pages_for_writeback
sudo bpftrace -l | grep tag_pages_for_writeback
echo "===================================="
echo "===================================="
echo truncate_inode_pages
sudo bpftrace -l | grep truncate_inode_pages
echo "===================================="
echo "===================================="
echo truncate_inode_pages_final
sudo bpftrace -l | grep truncate_inode_pages_final
echo "===================================="
echo "===================================="
echo truncate_pagecache
sudo bpftrace -l | grep truncate_pagecache
echo "===================================="
echo "===================================="
echo truncate_pagecache_range
sudo bpftrace -l | grep truncate_pagecache_range
echo "===================================="
echo "===================================="
echo try_to_release_page
sudo bpftrace -l | grep try_to_release_page
echo "===================================="
echo "===================================="
echo unlock_page
sudo bpftrace -l | grep unlock_page
echo "===================================="
echo "===================================="
echo unregister_shrinker
sudo bpftrace -l | grep unregister_shrinker
echo "===================================="
echo "===================================="
echo up_read
sudo bpftrace -l | grep up_read
echo "===================================="
echo "===================================="
echo up_write
sudo bpftrace -l | grep up_write
echo "===================================="
echo "===================================="
echo wait_for_completion
sudo bpftrace -l | grep wait_for_completion
echo "===================================="
echo "===================================="
echo wait_for_stable_page
sudo bpftrace -l | grep wait_for_stable_page
echo "===================================="
echo "===================================="
echo wait_on_page_bit
sudo bpftrace -l | grep wait_on_page_bit
echo "===================================="
echo "===================================="
echo wake_up_bit
sudo bpftrace -l | grep wake_up_bit
echo "===================================="
echo "===================================="
echo wake_up_process
sudo bpftrace -l | grep wake_up_process
echo "===================================="
