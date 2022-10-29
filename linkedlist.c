#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool; // enum to represent boolean values
// can be reaplced by using <stdbool.h>
// but that will break backward compatibility

int intInput(const char *message, bool newline) // function to take user input
{   
    // message will be printed, if any
    // newline will determine will the input be taken on new line or not
    // this function will keep asking for valid int input or until "exit" is input
    // returns a valid int or 0 if "exit"

    char temp[10]; // int limit is 64k (unsigned) so 9 + \0 are more than enough storage

    // if (message && newline)
    //     printf("%s\n",  message);
    // else if (message && !newline)
    //     printf("%s : ",  message);

    while (true)    // infinite loop
    {
        // above 4 lines of codes can be condensed into these two lines
        if (message)
            printf("%s%s", message, newline ? "\n" : " : ");

        scanf("%s", temp);

        if (!strcmp("exit", temp))  // inputting "exit" will quit the function with return value 0
            return 0;

        if (temp[0] == 48)  // inputting 0 will result in returning 0, as atoi works with 0 as invalid input
            return 0;
        else if (atoi(temp))    // inputting any valid (string)int will result in returning the int
            return atoi(temp);

    }
}

int main(int argc, char *argv[])
{
    
    return 0;
}