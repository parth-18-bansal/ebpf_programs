#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    char buf[512];

    int n;

    for(;;){
        n = read(0,buf,sizeof buf);

        if(n==0)
            break;

        if(n<0){
            write(2, "read error\n", 11);
            exit(1);
        }
        if(write(1,buf,n) != n){
            write(2, "write error\n", 12);
            exit(1);
        }
    }
}


