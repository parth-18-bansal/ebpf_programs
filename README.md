# ebpf_programs

## install required tools:
# Update apt first
sudo apt update

# Install Go
sudo apt install golang-go

# Install clang and llvm (to compile eBPF C code)
sudo apt install clang llvm

# Install libbpf development files
sudo apt install libbpf-dev

# Install linux headers (needed for vmlinux.h)
sudo apt install linux-headers-$(uname -r)

# Install bpftool (to generate vmlinux.h and Go bindings)
sudo apt install linux-tools-$(uname -r)


# generate the vmlinux.h
bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h

# compile the c program to the elf object file
clang -O2 -target bpf -c hello.c -o hello.bpf.o
#          ^^^^^^^^^^
#          compile for BPF architecture, not your CPU

# Install bpf2go tool
go install github.com/cilium/ebpf/cmd/bpf2go@latest

# Generate Go bindings from your .bpf.o file
bpf2go -go-package main hello hello.c

# setup go module
go mod init hello-ebpf

# Install cilium ebpf dependency
go get github.com/cilium/ebpf


sudo go run .


