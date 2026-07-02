#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    close(1);

    open("input.txt", O_RDWR | O_CREAT);

    if(fork() == 0){
        write(1, "hello ",6);
        exit(0);
    }
    else{
        wait((int *)0);
        write(1, "world",6);
    }
}