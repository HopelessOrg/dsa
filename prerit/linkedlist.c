#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * Documentation of this file
 *
 * Current version: 1.2
 * created on: 12th nov, 2022
 * updated on: 27th nov, 2022
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
 *
 * Version 1.1
 *  print() now returns pointer to Node type for easy chaining of newlist() then print() then delete() functions
 * 
 * version 1.2
 *  updated isEmpty() second argument from true -> warn, false -> nowarn, for better readability
 *  addNode() can be used to add a node at given location (start, next, end) of the given list
 *  both warning and position are enums for their saparate usecase, bool is now only for boolean use
 */
typedef enum bool
{
    false,
    true
} bool; // enum to represent boolean values
// can be reaplced by using <stdbool.h>
// but that will break backward compatibility

typedef enum position
{
    start,
    next,
    end
} position; // enum to represent the postion of adding/deleting node

typedef enum warning
{
    nowarn,
    warn
} warning;
// enum to show warning user by a console message

// Structure to be used as nodes or one 'element' of linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// function to get integer input

int intInput(const char* msg, bool newLine)
{
    if (msg)
        printf("%s%s", msg, newLine ? "\n" : " : ");
    int temp;
    scanf("%d", &temp);
    return temp;
}

// function to create a new node
Node *newNode(int val) // takes an integer input and puts the value in the data memeber of node
{
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to check see if list is empty
bool isEmpty(Node *head, warning printTxt)
{
    if (printTxt && head == NULL)
        printf("Empty!!\n");
    return head == NULL;
}

// function to print all nodes
Node *print(Node *head)
{
    if (isEmpty(head, warn))
        return head;

    // starts from given node and prints the entire list
    for (Node *temp = head; temp; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL\n");

    return head;
}

// function to delete the list
Node *delete(Node *head)
{
    if (isEmpty(head, warn))
        return head;

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

// function to seacch a node in list
Node *search(Node *head, int value)
{
    if (isEmpty(head, warn)) // if head is empty, print empty and return the head
        return head;

    for (Node *temp = head; temp; temp = temp->next) // if not, search for the value, and if found, return the Node containing the value
        if (temp->data == value)
            return temp;

    printf("Value not found !!\n"); // if not found, print and return the head of the list
    return head;
}

// function to add a node at previous, current or next postion of head
Node *addNode(Node *head, position pos)
{
    if (isEmpty(head, warn))
        return head;

    if (pos == start)
    {
        Node* temp = newNode(intInput("Enter an integer", false));
        temp->next = head;
        head = temp;
    }
    else if (pos == next) // postition at next
    {
        Node* temp = head->next;
        head->next = newNode(intInput("Enter an integer", false));
        head->next->next = temp;
    }
    else 
    {  // insert at end
        Node* temp;
        
        for (temp = head; temp->next; temp = temp->next);   // traverse to the end - 1 node
        
        temp->next = newNode(intInput("Enter an integer", false));
    }

    return head;
}

int main(int argc, char *argv[]) // the origin, the end, the main function
{
    Node *temp = newNode(intInput("Enter a number", false));
    print(temp);

    delete(print(addNode(addNode(temp, start), end)));
    return 0;
}