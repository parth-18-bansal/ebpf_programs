#include <stdio.h>
#include <unistd.h>

int main(void){
    char *argv[] = {
        "echo",
        "hello",
        NULL
    };

    execv("/bin/echo", argv);
    printf("exec error\n");  

    perror("execv");

    return 1;
}



