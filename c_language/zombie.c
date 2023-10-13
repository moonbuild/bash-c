#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t child_pid = fork();

    if (child_pid<0){
        printf("Fork Failed\n");
        exit(1);
    }
    else if(child_pid==0){
        printf("Child process executing\n");
        exit(0);
    } else{
        sleep(2);

        int status;
        wait(&status);
        printf("Parent Process\n");
        printf("Child process exited with status %d\n", status);

    }
    return 0;
}