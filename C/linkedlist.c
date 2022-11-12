#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * Documentation of this file
 * 
 * version: 1.0
 * created on: 12th nov, 2022
 * Author : Prerit Vishal
 * github: preritvishal
 * email: preritvishal3@gmail.com
 * 
 * This file can serve as a library or stand-alone program
 * To use as library, Donwload this file, put it in the current working folder and use #include "linkedlist.c"
 * 
 * Function documentation:
 * 
 * bool is an enum, created to simplify the readablity of true and false as literals instead of 1 and 0
 * 
 * Node is a struct which contains a integer and a pointer of it's own type
 * 
 * newNode() function, takes in the value you want to store in node, returns a pointer to the Node just created
 * 
 * print() function, takes in a pointer of Node type and prints the list, or Empty!! if it's empty, doesn't returns anything
 * 
 * delete() function, takes in a pointer of Node type and deletes the entire list, or prints Empty!! if empty, and it returns the head
 *      it is important to assign the return value of delete to the pointer provided to the function. Example: temp = delete(temp); else it
 *      will result in garbage output, if same pointer to Node is used in some other operations, such as print
 * 
 * newlist() function, will not take input and return a pointer of Node type, which is a list
 * 
 */
typedef enum bool
{
    false,
    true
} bool; // enum to represent boolean values
// can be reaplced by using <stdbool.h>
// but that will break backward compatibility

// Structure to be used as nodes or one 'element' of linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// function to get integer input
/*
int intInput(const char* msg, bool newLine)
{
    if (msg)
        printf("%s%s", msg, newLine ? "\n" : " : ");
    int temp;
    scanf("%d", &temp);
    return temp;
}
*/

// function to create a new node
Node *newNode(int val) // takes an integer input and puts the value in the data memeber of node
{
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to print all nodes
void print(Node *head)
{
    if (!head)
    {
        printf("Empty!!\n");
        return;
    }

    // starts from given node and prints the entire list
    for (Node *temp = head; temp; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL\n");
}

// function to delete the list
Node *delete (Node *head)
{
    if (!head)
    {
        printf("Empty!!\n");
        return head;
    }

    // it starts from given node and deletes entite list
    for (Node *temp = head; temp; temp = head)
    {
        head = head->next;
        free(temp);
    }

    return head;
}

// function to get a new linked list
Node *newList()
{
    char tempInput[10];
    Node *head = NULL;
    Node *current = head;

    while (true) // loops until return condition is encountered
    {
        printf("Enter an integer or \"exit\": ");
        scanf("%s", tempInput); // takes input in charater, to avoid errors or anticipate exit condition

        if (strcmp("exit", tempInput) == 0) // check if the input indicate exiting the input
            return head;

        if (head == NULL) // if head is empty, then add it as head, which is current
            current = head = newNode(atoi(tempInput));
        else // if head has some data, then append the new node to next pointer of the current node
        {
            current->next = newNode(atoi(tempInput));
            current = current->next;
        }
    }
}

int main(int argc, char *argv[])    // the origin, the end, the main function
{
    Node* temp = newList();
    print(temp);
    delete(temp);
    return 0;
}
