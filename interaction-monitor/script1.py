# kprobe_fn_reg = '''
# static struct kprobe *fn_kps[70] = {
#     %s
# };
# '''

# kprobe_fp_reg = '''
# static struct kprobe *fp_kps[240] = {
#     %s
# };
# '''

defines_item = "#define %s %d\n"

kretprobe_fn_reg = '''
static struct kretprobe *fn_kps[240] = {
    %s
};
'''

kretprobe_fp_reg = '''
static struct kretprobe *fp_kps[70] = {
    %s
};
'''

kretprobe_fp_reg_item = '\t[%s] = &%s_kp,\n'

# kprobe_reg_item = '''
# static struct kprobe %s_kp = {
#     .symbol_name = "%s",
#     .pre_handler = %s_pre_handler,
# };
# '''

kretprobe_reg_struct = '''
static struct kretprobe %s_kp = {
    .kp.symbol_name = "%s",
    .entry_handler = %s_entry_handler,
    .handler = %s_ret_handler,
};
'''

handler_fn_dec = '''
static int %s_fn_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
static int %s_fn_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
'''

handler_fn_impl = '''
static int %s_fn_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
static int %s_fn_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    if (this_cpu_read(ext4_executing)) {

    }
    return 0;
}
'''

handler_fp_dec = '''
static int %s_fp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
static int %s_fp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs);
'''

handler_fp_impl = '''
static int %s_fp_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, true);
    return 0;
}
static int %s_fp_ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    this_cpu_write(ext4_executing, false);
    return 0;
}
'''


fps = []
fns = []

fp_defines = ""
fn_defines = ""

fn_handler_decs = ""
fn_handler_impls = ""

fp_handler_decs = ""
fp_handler_impls = ""

fn_kretprobe_reg_structs = ""
fp_kretprobe_reg_structs = ""

fn_kretprobe_fp_reg_items = ""
fp_kretprobe_fp_reg_items = ""


with open('kprobe_funcs.txt', 'r') as f:
    for line in f.readlines():
        fns.append(line[:-1])
    fns.sort()

with open('fp_list.txt', 'r') as f:
    for line in f.readlines():
        fps.append(line[:-1])
    fps.sort()

count = 0
for fn in fns:
    fn_defines = fn_defines + defines_item%(fn.upper()+'_PROBE', count)
    count = count + 1
    fn_handler_decs = fn_handler_decs + handler_fn_dec%(fn, fn)
    fn_handler_impls = fn_handler_impls + handler_fn_impl%(fn, fn)
    fn_kretprobe_reg_structs = fn_kretprobe_reg_structs + kretprobe_reg_struct%(fn, fn, fn, fn)
    fn_kretprobe_fp_reg_items = fn_kretprobe_fp_reg_items + kretprobe_fp_reg_item%(fn.upper(), fn)

print(fn_defines)
print(fn_handler_decs)
print(fn_kretprobe_reg_structs)
print(kretprobe_fn_reg%(fn_kretprobe_fp_reg_items))
print(fn_handler_impls)


count = 0
for fp in fps:
    fp_defines = fp_defines + defines_item%(fp.upper()+'_PROBE', count)
    count = count + 1
    fp_handler_decs = fp_handler_decs + handler_fp_dec%(fp, fp)
    fp_handler_impls = fp_handler_impls + handler_fp_impl%(fp, fp)
    fp_kretprobe_reg_structs = fp_kretprobe_reg_structs + kretprobe_reg_struct%(fp, fp, fp, fp)
    fp_kretprobe_fp_reg_items = fp_kretprobe_fp_reg_items + kretprobe_fp_reg_item%(fp.upper(), fp)

print(fp_defines)
print(fp_handler_decs)
print(fp_kretprobe_reg_structs)
print(kretprobe_fp_reg%(fp_kretprobe_fp_reg_items))
print(fp_handler_impls)