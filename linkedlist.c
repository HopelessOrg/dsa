#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int intInput(const char* msg, bool newLine)
{
    if (msg)
        printf("%s%s", msg, newLine ? "\n" : " : ");
    int temp;
    scanf("%d", &temp);
    return temp;
}

// function to create a new node
Node* newNode()
{
    Node* temp = malloc(sizeof(Node));
    temp->data = intInput("Enter an integer", false);
    temp->next = NULL;
    return temp;
}

// function to print all nodes
void print(Node* head)
{
    if (!head)
    {
        printf("Empty!!\n");
        return;
    }

    // starts from given node and prints the entire list
    for (Node* temp = head; temp; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL\n");
    
}

// function to delete the list
Node* delete(Node* head)
{
    if (!head)
    {
        printf("Empty!!\n");
        return head;
    }

    // it starts from given node and deletes entite list
    for (Node* temp = head; temp; temp = head)
    {
        head = head->next;
        free(temp);
    }
    
    return head;
}

int main(int argc, char *argv[])
{
    Node* temp = newNode();
    print(temp);
    temp = delete(temp);
    print(temp);
    return 0;
}