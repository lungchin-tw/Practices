
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
** Try: man fork
** Try: man getpid
** Try: man 3 printf
*/

void child_routines() {
    pid_t my_pid = getpid();
    printf("[%d]: I'm a child process.\n", my_pid);
    printf("[%d]: I'm a child process, Start Sleeping.\n", my_pid);

    const int NUM = 3;
    for (int i = 0; i < NUM; i++) {
        printf("[%d]: I'm a child process, sleeping(%d)\n", my_pid, i);
        sleep(1);
    }

    printf("[%d]: I'm a child process, End Sleeping.\n", my_pid);
}

int main()
{
    pid_t my_pid = getpid();
    printf("Started: My PID is %d.\n", my_pid);

    pid_t child_pid = fork();
    if (child_pid  == 0) {
        child_routines();
        exit(45);
    } else if (child_pid < 0 ) {
        perror("Fork failed.");
    } else {
        printf("[%d]: Hello World, fork() return %d.\n", my_pid, child_pid);
    }

    printf("Start Waiting: My PID is %d.\n", my_pid);

    int child_status = 0;
    printf("Finished Waiting for Child %d, Child's Status is %d.\n", wait(&child_status), WEXITSTATUS(child_status));
    printf("Finished: My PID is %d.\n", my_pid);

    
    return 0;
}