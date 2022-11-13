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
typedef enum bool {false, true} bool;

// inner struct to create stack
typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

// Actual Stack 
typedef struct Stack {
    Node* head;
    int length;
} Stack;

 
// fucntion to get a new node for stack
Node* newNode(int value)
{
    Node* temp = malloc(sizeof(Node));
    temp->data = value;
    temp->prev = temp->next = NULL;
    return temp;
}

// fcuntion to create a new stack
Stack* newStack()
{
    Stack* temp = malloc(sizeof(Stack));
    temp->head = NULL;
    temp->length = 0;
}

// add an element to stack
Stack* push(Stack* stk, int value)
{

}


// function to check for underflow conditon
bool isUnderflow(Stack* stk)
{
    return true;
} 

int main()  // the beginning, the end, the main function
{
    return 0;
}