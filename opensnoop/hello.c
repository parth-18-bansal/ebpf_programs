#include <vmlinux.h>
#include <bpf/bpf_helpers.h>

// here const means that value can not be change by the program itself like int x = 5 and later x = 6 
// is not allowed, or hardware can unexpectldly change value, volatile means
// always read the value from memory every time and do not assume that value will remain same due to const.
// some time compiler optimised the code if he/she see that variable is constant.

const volatile int pid_target = 0;

char __license[] SEC("license") = "GPL";

// SEC is a Macro, Macro are the key value pair. Preproccesor replace the key with value before compiler
// compiles the code. there can be variable type macro also fuction type macro, SEC is function macro.

// bpf_get_current_pid_tgid gives the pid and tgid of the current process, now in kernel, tgid equal to the 
// pid of the process 0(main process in the thread), now this main process can create worker threads
// those process ids is the pid(thread id), now this function returns a 64 bit value where upper32 bits
// are the tgid and lower32 bits are the pid. now id >> 32, here we are shifting the upper 32 bit to the right side
// and discarding the lower32 bits so pid variable = tgid.


// struct trace_event_raw_sys_enter* ctx, it is a struct, this struct contains the details of the
// event(here openat() sys call by a process), this struct is created by the kernel and then
// kernel passes it to the ebpf function, so that ebpf function has the information about the event.


// if(pid_target)  is equal to the if (pid_target != 0)

SEC("tracepoint/syscalls/sys_enter_opennat")
int tracepoint__syscalls__sys_enter_openat(struct trace_event_raw_sys_enter* ctx)
{
    u64 id = bpf_get_current_pid_tgid();
    u32 pid = id >> 32;

    if (pid_target && pid_target != pid)
        return false;

    bpf_printk("Process ID: %d enter sys openat\n", pid);

    return 0;
}
