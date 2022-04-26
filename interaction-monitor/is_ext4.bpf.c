#include <linux/fs.h>

#include <uapi/linux/ptrace.h>
#include <linux/uaccess.h>
#include <bcc/proto.h>
BPF_STACK_TRACE(stack_traces, 128);
BPF_HASH(calls, int);

// bool is_ext4(struct pt_regs *ctx)
// {
//     bpf_printstack_traces.get_stackid(&ctx->regs, 0);
// }



int kprobe__generic_file_read_iter(struct pt_regs *ctx) 
// KFUNC_PROBE(_copy_from_user, void *a, void *b, void *c)
{   
    // if (!is_ext4(ctx)) {
    //     return 0;
    // } else {

    // }
    char comm[200];
    bpf_get_current_comm(&comm, sizeof(comm));
    int key = stack_traces.get_stackid(ctx, 0);
    u64 zero = 0, *val;
    val = calls.lookup_or_try_init(&key, &zero);
    bpf_trace_printk("%s  key:%d\n", comm, stack_traces.flags);
    // for (int i = 0;i < 5;i++) {
    //     bpf_trace_printk("\t\t%lx\n", ip[i]);
    // }
    // bpf_trace_printk("%s  key:%d\n", comm, key);
    return 0;
}


// struct stack_trace_table_t
// {

// };

// #define BPF_STACK_TRACE(_name, _max_entries) \
//   BPF_TABLE("stacktrace", int, struct bpf_stacktrace, _name, roundup_pow_of_two(_max_entries))

// #define BPF_TABLE(_table_type, _key_type, _leaf_type, _name, _max_entries) \
// BPF_F_TABLE(_table_type, _key_type, _leaf_type, _name, _max_entries, 0)

// // Changes to the macro require changes in BFrontendAction classes
// #define BPF_F_TABLE(_table_type, _key_type, _leaf_type, _name, _max_entries, _flags) \
// struct _name##_table_t { \
//   _key_type key; \
//   _leaf_type leaf; \
//   _leaf_type * (*lookup) (_key_type *); \
//   _leaf_type * (*lookup_or_init) (_key_type *, _leaf_type *); \
//   _leaf_type * (*lookup_or_try_init) (_key_type *, _leaf_type *); \
//   int (*update) (_key_type *, _leaf_type *); \
//   int (*insert) (_key_type *, _leaf_type *); \
//   int (*delete) (_key_type *); \
//   void (*call) (void *, int index); \
//   void (*increment) (_key_type, ...); \
//   int (*get_stackid) (void *, u64); \
//   u32 max_entries; \
//   int flags; \
// }; \
// __attribute__((section("maps/" _table_type))) \
// struct _name##_table_t _name = { .flags = (_flags), .max_entries = (_max_entries) }; \
// BPF_ANNOTATE_KV_PAIR(_name, _key_type, _leaf_type)