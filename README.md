# ebpf-tutorial

主要任务

1. 已经基本确定了有哪些交互事件
2. 编写bpfbcc，或者libbpf，截获这些事件，同时必须识别是ext4的


很简单，设置percpu变量，进入ext4设置1，退出设置0

只需要判断0，1，即可确定到底是不是ext4在运行