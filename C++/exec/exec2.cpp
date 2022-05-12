
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
** try: gcc main.cpp, then execute ./a.out
*/

int main(int argc, char *argv[])
{
    pid_t my_pid = getpid();
    printf("Started: PID of exec2 = %d\n", my_pid);
    return 0;
}