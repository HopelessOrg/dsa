#include <stdio.h>

typedef enum bool {false, true} bool;   // enums to use boolean in C

typedef struct Stack { 
    int size;
    int top;
    int stack[10];
} Stack;

bool isOverflow(Stack* stk)     // function to check overflow
{
    return stk->top >= stk->size;
}

bool isUnderFlow(Stack* stk)    // function to check underflow
{
    return stk->top <= -1;
}

void push(Stack* stk, int val)      // function to push a value in stack
{
    
}

int pop(Stack* stk)     // function to remove last value from stack
{

}

void show(Stack* stk)       // function to print entire stack
{

}

void interface()        // function to show user interface 
{
    printf("%-40s:%5s\n", "Insert an item in stack", "1");
    printf("%-40s:%5s\n", "Remove an item from stack", "2");
    printf("%-40s:%5s\n", "Print entire stack", "3");
    printf("%-40s:%5s\n", "Show last inserted item in stack", "4");

    char userInput[5];


}

int main()      // the beginning, the end, the main function
{
    interface();
    return 0;
}