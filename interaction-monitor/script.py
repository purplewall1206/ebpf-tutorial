with open('ext4_kfunc.txt', 'r') as f:
    for x in f.readlines():
        print('echo "===================================="') 
        print('echo ' + x[:-1])
        print('sudo bpftrace -l | grep ' + x[:-1])
        print('echo "===================================="') 