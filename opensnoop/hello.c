#include <vmlinux.h>
#include <bpf/bpf_helpers.h>

// here const means that value can not be change, but hardware can unexpectldly change value, volatile means
// always read the value from memory every time and do not assume that value will remain same due to const.
// some time compiler optimised the code if he/she see that variable is constant.

const volatile int pid_target = 0;

// SEC is a Macro, Macro are the key value pair. Preproccesor replace the key with value before compiler
// compiles the code. there can be variable type macro also fuction type macro, SEC is function macro.

SEC("tracepoint/syscalls/sys_enter_opennat")
int tracepoint__syscalls__sys_enter_openat(struct trace_event_raw_sys_enter* ctx)
{

}
