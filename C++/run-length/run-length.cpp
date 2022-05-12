
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
** try: g++ cin.cpp -o cin; then execute ./cin
*/

using namespace std;

int main(int argc, char *argv[])
{
    const int num_rows = 3;
    // const string data[num_rows] = { "AAABB", "BBBCCA", "AAA" };
    const string data[num_rows] = { "ABCDEF", "ABCDEF", "ABCDEF" };

    for(int i = 0; i < num_rows; i++) {
        printf("%d-Data: %s\n", i, data[i].c_str());
    }
    
    string result;
    int counter = 0;
    char pre_letter = 0;
    for(int i = 0; i < num_rows; i++) {
        string context = data[i].c_str();
        for(string::iterator it=context.begin(); it != context.end(); it++) {
            if (pre_letter == 0) {
                pre_letter = *it;
                counter = 1;
                continue;
            } else if (pre_letter == *it) {
                counter++;
                continue;
            } else if (pre_letter != *it) {
                if (counter > 1) {
                    result += to_string(counter);
                }
                
                result.push_back(pre_letter);
                counter = 1;
                pre_letter = *it;
            }
        }

        printf("%d-Result: %s\n", i, result.c_str());
    }

    if (counter > 1) {
        result += to_string(counter);
    }

    if (pre_letter != 0) {
        result.push_back(pre_letter);
    }

    printf("Final Result: %s\n", result.c_str());

    return 0;
}