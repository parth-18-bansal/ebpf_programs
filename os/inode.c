#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = open("abc.txt",O_RDONLY);

    struct stat st;

    fstat(fd,&st);

    printf("Size : %ld\n", st.st_size);
    printf("Inode: %lu\n", st.st_ino);
    printf("Links: %lu\n", st.st_nlink);

    close(fd);
}