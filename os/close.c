#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>   // <-- for O_RDONLY and open()

int main(){
    char *argv[2];

    argv[0] = "cat";
    argv[1] = 0;

    if(fork() == 0){
        close(0);
        open("input.txt", O_RDONLY);
        execvp("cat", argv);
    }
}

// exec is in the xv6 not ubuntu
// execv here we have to define the full path of the program
// but in execvp we can only define process name it will directory look into the PATH by default