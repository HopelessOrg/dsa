#include <stdio.h>

#define SIZE 100

// function to get int input
int intInput(const char* msg)
{
    int temp;

    if (msg)    // if there is any message provided, it will print and then wait for input
        printf("%s : ", msg);

    // if not, it will simply wait for input
    scanf("%d", &temp);
    return temp;
}

// function to perfrom linear search 
int linearSearch(const int* list, int size, int key)
{
    for (int i = 0; i < size; ++i)  // iterate from 0 to size - 1 to find the key
        if (key == list[i])
            return i;   // if found, it will return the index of they element
    return -1;  // if not found, it will return -1, indicating item not found
}

int main()  // the origin, the end, the main function
{
    int array[SIZE];
    int size = intInput("Enter the size of array");
    
    for (int i = 0; i < size; ++i)
        array[i] = intInput("Enter a digit");
    
    int key = intInput("Enter the value to search");
    
    int foundIndex = linearSearch(array, size, key);

    if (foundIndex == -1)
        printf("Value not found !!\n");
    else
        printf("Value found at index : %d\n", foundIndex);
    
    return 0;
}