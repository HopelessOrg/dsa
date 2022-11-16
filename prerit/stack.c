#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 *  Documentation
 *
 *  Current Version: 1.0
 *  Created on: 13th Nov, 2022
 *  Author: Prerit Vishal
 *  github: preritvishal
 *  email: preritvishal3@gmail.com
 *
 *  bool is an enum, used to add and simplify the boolean in C
 * 
 *  Node is a structure which is used as each stack frame that contains data, and two pointers of Node type
 * 
 *  Stack is a wrapper based on Node, which keep the top of stack and it's length
 * 
 *  newNode function takes in int value and returns a Node type pointer to newly created and initilialzed node
 *      default value of both Node pointers is NULL
 *      default value of int is provided value
 * 
 *  newStack function takes no input and return a pointer of Stack type 
 *      default value of head pointer of Node type is NULL
 *      default value of length is 0
 * 
 *  push function takes in a pointer of Stack type and a value, adds the value in stack and returns a pointer 
 *      of Stack type with updated values
 * 
 *  pop function takes in a pointer of Stack type, removes the latest entry in stack and retuns the updated Stack pointer
 * 
 *  print function takes in a pointer of Stack type, prints the entire stack and returns a pointer of Stack type of same 
 *      Stack, it is nostly useful in chaining it with other functionalities
 */

// enum to use boolean values, instead of 0 amd 1
typedef enum bool
{
    false,
    true
} bool;

// inner struct to create stack
typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

// Actual Stack
typedef struct Stack
{
    Node *head;
    int length;
} Stack;

// fucntion to get a new node for stack
Node *newNode(int value)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = value;
    temp->prev = temp->next = NULL;
    return temp;
}

// fcuntion to create a new stack
Stack *newStack()
{
    Stack *temp = malloc(sizeof(Stack));
    temp->head = NULL;
    temp->length = 0;
}

// add an element to stack
Stack *push(Stack *stk, int value)
{
    if (!stk->head && !stk->length) // if stack head is NULL and length of stack is 0
    {
        stk->head = newNode(value); // assign the new node to head, done !!!
    }
    else // in case there are some element in stack
    {
        Node *temp = newNode(value); // create and store a node

        stk->head->next = temp; // link the current head to new node

        temp->prev = stk->head; // link the current prev node to current head
        stk->head = temp;       // shift the current head to new node
    }

    ++stk->length; // increase the length
    return stk;    // most important step, return the stack
}

Stack *pop(Stack *stk) // fucntion to remove last element of stack
{
    if (!stk->head) // if stack head is empty
    {
        printf("Empty !!\n");
        return stk;
    }

    //  10<->20<->30
    Node *temp = stk->head; // 30

    stk->head = temp->prev; // 20
    --stk->length;

    free(temp);

    if (stk->head == NULL)
    {
        free(stk);
        stk->length = 0;
    }

    return stk;
}

Stack *print(Stack *stk) // function to print entire stack
{
    if (!stk->head || stk->length == 0) // check if the stack is empty
    {
        printf("Empty !!\n");
        return stk;
    }

    for (Node *temp = stk->head; temp; temp = temp->prev) // if stack has some element, print them
        printf("|%3d |\n|----|\n", temp->data);
    printf("\n");

    return stk;
}

int main() // the beginning, the end, the main function
{
    // Stack *temp = newStack();
    // temp = push(temp, 10);
    // temp = push(temp, 20);
    // temp = print(temp);

    // temp = pop(temp);
    // temp = print(temp);
    // temp = pop(temp);
    // temp = print(temp);
    // printf("length of stack : %d\n", temp->length);

    return 0;
}