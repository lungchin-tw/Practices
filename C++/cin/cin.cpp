
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
** try: g++ cin.cpp -o cin; then execute ./cin
*/

using namespace std;

int main(int argc, char *argv[])
{
    int x; 
    char str[80];
    printf("Enter a number & a string:\n");
    cin >> x;
    printf("numeric_limits<streamsize>::max(): %ld\n", numeric_limits<streamsize>::max());
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    // cin.ignore(); // <- This works as well.
    cin.getline(str, 80);

    printf("Entered: %d & %s\n", x, str);
    
    return 0;
}