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

// Structure to be used as nodes or one 'element' of linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function to get a new node
// takes a string input of what to print and returns a pointer to node
Node* newNode(const char* message)  
{
    Node* temp = malloc(sizeof(Node));
 
    temp->data = intInput(message, false);
    temp->next = NULL;

    return temp;
}

// function to print the given node, or list
void print(Node* head)
{
    for (Node* temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL\n");
}

int main(int argc, char *argv[])
{

    print(newNode("Enter a integer"));
    
    return 0;
}