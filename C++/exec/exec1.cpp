
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
** try: gcc exec1.cpp -o exec1; gcc exec2.cpp -o exec2, then execute ./exec1
*/

int main(int argc, char *argv[])
{
    pid_t my_pid = getpid();
    printf("Started: PID of exec1 = %d\n", my_pid);

    char *args[] = {(char*)"Hello", (char*)"World", NULL}; // NULL is a must need
    printf("execv(\"./exec2\", args) = %d\n", execv("./exec2", args));
    printf("Back to exec1.\n");
    
    return 0;
}