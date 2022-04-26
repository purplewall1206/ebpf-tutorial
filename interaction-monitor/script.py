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

kprobe_code = '''
static struct kprobe *fp_kps[70] = {
    %s
};
'''

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

kprobe_item_sample = '''
static struct kprobe %s_kp = {
    .symbol_name = "%s",
    .pre_handler = %s_pre,
    .post_handler = %s_post,
};
'''

ext4_monitor_dec_samle = '''
int %s_pre(struct kprobe *p, struct pt_regs *regs);
int %s_post(struct kprobe *p, struct pt_regs *regs);
'''


ext4_monitor_samle = '''
int %s_pre(struct kprobe *p, struct pt_regs *regs) 
{
    return 0;
}
int %s_post(struct kprobe *p, struct pt_regs *regs) 
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

# fp_list = set()
# with open('fp_list.txt', 'r') as f:
#     for line in f.readlines():
#         line = line.strip()
#         if line.find('=') != -1:
#             fp_list.add(line[line.find('=') + 2:-1])
#         elif line.find(',') != -1:
#             fp_list.add(line[:-1])
#         else:
#             fp_list.add(line)

# fpl = list(fp_list)
# fpl.sort()

# for fp in fpl:
#     print(fp)