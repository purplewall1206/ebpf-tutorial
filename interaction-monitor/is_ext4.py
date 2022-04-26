from __future__ import print_function
from bcc import BPF
from bcc.utils import printb
from time import sleep
import sys

# b = BPF(text='''
# #include <linux/fs.h>

# #include <uapi/linux/ptrace.h>
# #include <linux/uaccess.h>
# #include <bcc/proto.h>
# BPF_STACK_TRACE(stack_traces, 128);
# KFUNC_PROBE(_copy_from_user, void *a, void *b, void *c)
# {   
#     char comm[200];
#     bpf_get_current_comm(&comm, sizeof(comm));
#     int key = stack_traces.get_stackid(ctx, 0);
#     bpf_trace_printk("\%s  key:\%d\\n", comm, key);
#     return 0;
# }
# ''').trace_print()

b = BPF(src_file='is_ext4.bpf.c')

try:
    sleep(99999999)
except KeyboardInterrupt:
    pass

pid = 0
calls = b.get_table("calls")
stack_traces = b.get_table("stack_traces")
for k, v in reversed(sorted(calls.items(), key=lambda c: c[1].value)):
    print("%d bytes allocated at:" % v.value)
    if k.value > 0 :
        for addr in stack_traces.walk(k.value):
            printb(b"\t%s" % b.ksym(addr, pid, show_offset=True))