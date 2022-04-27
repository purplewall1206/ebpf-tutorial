# # with open('ext4_kfunc1.txt', 'r') as f:
# #     for x in f.readlines():
# #         print('echo "===================================="') 
# #         print('echo ' + x[:-1])
# #         print('sudo bpftrace -l | grep ' + x[:-1])
# #         print('echo "===================================="') 

# # kprobe_code = '''
# # int kprobe__%s(struct pt_regs *ctx) 
# # {
# #     // if (!is_ext4(ctx)) {
# #     //     return 0;
# #     // } else {

# #     // }
# #     int key = stack_traces.get_stackid(ctx, 0);
# #     u64 zero = 0, *val;
# #     val = calls.lookup_or_try_init(&key, &zero);
# #     return 0;
# # }
# # '''

# kprobe_functions = []

# with open('kprobe_funcs.txt', 'r') as f:
#     for line in f.readlines():
#         kprobe_functions.append(line[:-1])
#     kprobe_functions.sort()

# # with open('kprobes_monitor.bpf.c', 'w') as f:
# #     f.write('''
# #     #include <linux/fs.h>

# # #include <uapi/linux/ptrace.h>
# # #include <linux/uaccess.h>
# # #include <bcc/proto.h>
# # BPF_STACK_TRACE(stack_traces, 128);
# # BPF_HASH(calls, int);
# #     ''')
# #     for kf in kprobe_functions:
# #         f.write(kprobe_code%kf)
# #         f.write('\n')



# # count = 0
# # kprobe_code_items = ""
# # defines = ""
# # for kf in kprobe_functions:
# #     defines = defines + '#define %s %d\n'%(kf.upper()+'_PROBE', count)
# #     s = '\t[%s] = {.symbol_name = "%s",\n\t\t\t.pre_handler = ext4_monitor},\n'%(kf.upper()+'_PROBE', kf)
# #     count = count + 1
# #     kprobe_code_items = kprobe_code_items + s

# # # print(defines)

# # print(kprobe_code%kprobe_code_items)


ext4_fps = []

with open('fp_list.txt', 'r') as f:
    for line in f.readlines():
        ext4_fps.append(line[:-1])

kprobe_code = '''
static struct kprobe *fp_kps[70] = {
    %s
};
'''

kprobe_code1 = '''
static struct kprobe *kps[70] = {
    %s
};
'''

kprobe_item_sample = '''
static struct kprobe %s_kp = {
    .symbol_name = "%s",
    .pre_handler = %s_pre_handler,
    .post_handler = %s_post_handler,
};
'''

ext4_monitor_dec_samle = '''
int %s_pre_handler(struct kprobe *p, struct pt_regs *regs);
int %s_post_handler(struct kprobe *p, struct pt_regs *regs);
'''


ext4_monitor_samle = '''
int %s_pre_handler(struct kprobe *p, struct pt_regs *regs) 
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
int %s_post_handler(struct kprobe *p, struct pt_regs *regs) 
{
    this_cpu_write(ext4_executing, false);
    return 0;
}
'''

kprobe_monitor_sample = '''
int %s_pre_handler(struct kprobe *p, struct pt_regs *regs) 
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
int %s_post_handler(struct kprobe *p, struct pt_regs *regs) 
{
    
    return 0;
}
'''

count = 0
kprobe_code_items = ""
kprobe_items = ""
ext4_m_items = ""
ext4_m_dec_items = ""
defines = ""
for kf in ext4_fps:
    defines = defines + '#define %s %d\n'%(kf.upper()+'_PROBE', count)
    count = count + 1
    s = '\t[%s] = &%s_kp,\n'%(kf.upper()+'_PROBE', kf)
    kprobe_items = kprobe_items + kprobe_item_sample%(kf, kf, kf, kf)
    kprobe_code_items = kprobe_code_items + s
    ext4_m_items = ext4_m_items + ext4_monitor_samle%(kf,kf)
    ext4_m_dec_items  = ext4_m_dec_items + ext4_monitor_dec_samle%(kf,kf)

print(defines)
print(ext4_m_dec_items)
print(kprobe_items)
print(kprobe_code%kprobe_code_items)

print(ext4_m_items)


kprobe_functions = []

with open('kprobe_funcs.txt', 'r') as f:
    for line in f.readlines():
        kprobe_functions.append(line[:-1])
    kprobe_functions.sort()

defines = ""
count = 0
kprobe_struct_items = ""
kprobe_handler_dec_items = ""
kprobe_handler_impl_items = ""
kprobe_struct_pointers = ""
for kf in kprobe_functions:
    defines = defines + '#define %s %d\n'%(kf.upper()+'_PROBE', count)
    count = count + 1
    s = '\t[%s] = &%s_kp,\n'%(kf.upper()+'_PROBE', kf)
    kprobe_struct_pointers = kprobe_struct_pointers + s
    kprobe_struct_items = kprobe_struct_items + kprobe_item_sample%(kf, kf, kf,kf)
    kprobe_handler_dec_items = kprobe_handler_dec_items + ext4_monitor_dec_samle%(kf, kf)
    kprobe_handler_impl_items = kprobe_handler_impl_items + kprobe_monitor_sample%(kf, kf)

print("-----------------------------------------------------\n\n\n")
print(defines)
print(kprobe_handler_dec_items)

print(kprobe_struct_items)
print(kprobe_code1%kprobe_struct_pointers)
print(kprobe_handler_impl_items)
