#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t child_pid = fork();

    if (child_pid < 0){
        printf("Fork Failed\n");
        exit(1);
    }else if(child_pid == 0){
        printf("Child process executing\n");
        sleep(5);
        printf("Child process complete\n");
    }else{
        printf("Parent process complete\n");
        exit(0);
    }
    return 0;
}