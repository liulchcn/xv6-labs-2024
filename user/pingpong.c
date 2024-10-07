//
// Created by L1835 on 2024/10/7.
//
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
    int p[2];
    char buf[12];
    printf("%d ",getpid());
    pipe(p);

    if(fork()==0){
        close(p[0]);
        close(p[1]);
        read(p[0],buf,12);
        printf("<%d>: received %s",getpid(),buf);
    }else{
        close(p[0]);
        write(p[1], "ping", 12);
        close(p[1]);
    }
}