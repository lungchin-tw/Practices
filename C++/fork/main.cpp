
#include <iostream>
#include <unistd.h>

int main()
{
    if (fork() == 0) {
        std::cout << "I'm a child process, Hello World." << std::endl;
    } else {
        std::cout << "Hello World." << std::endl;
    }
    
    return 0;
}