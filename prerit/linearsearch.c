#include <stdio.h>

#define SIZE 100

// function to get int input
int intInput(const char* msg)
{
    int temp;

    if (msg)
        printf("%s : ", msg);
    
    scanf("%d", &temp);
    return temp;
}

// function to perfrom linear search 
int linearSearch(const int* list, int size, int key)
{
    for (int i = 0; i < size; ++i)
        if (key == list[i])
            return i;
    return -1;
}

int main()
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