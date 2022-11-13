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
 *
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

Stack* pop(Stack* stk)  // fucntion to remove last element of stack
{
    if (!stk->head) // if stack head is empty
    {
        printf("Empty !!\n");
        return stk;
    }

    Node* temp = stk->head;
    stk->head = temp->prev;

    return stk;
}

Stack *print(Stack *stk) // function to print entire stack
{
    if (!stk->head) // check if the stack is empty
    {
        printf("Empty !!\n");
        return stk;
    }

    for (Node *temp = stk->head; temp; temp = temp->prev) // if stack has some element, print them
        printf("|%3d |\n|----|\n", temp->data);

    return stk;
}

int main() // the beginning, the end, the main function
{
    Stack *temp = newStack();
    push(temp, 10);
    print(temp);
    pop(temp);
    print(temp);
    // printf("length of stack : %d\n", temp->length);

    return 0;
}