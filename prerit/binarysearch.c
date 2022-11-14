#include <stdio.h>

#define SIZE 100

// function to get int input
int intInput(const char *msg)
{
    int temp;

    if (msg) // if there is any message provided, it will print and then wait for input
        printf("%s : ", msg);

    // if not, it will simply wait for input
    scanf("%d", &temp);
    return temp;
}

int binarySearch(const int *array, int size, int key)
{
    int beg = 0; // initial values of beginning and end
    int end = size - 1;

    while (beg <= end)
    {
        int mid = (beg + end) / 2;

        if (array[mid] == key)
            return mid; // when the element is found
        else if (key < array[mid])  // when the key is less than mid, means we have to work with first half
            end = mid - 1;
        else    // when the key is greater than they value of mid, means we have to work in later half of array
            beg = mid + 1;
    }

    return -1; // in case element is not found
}

int main() // the origin, the end, the main function
{
    int array[SIZE];
    int size = intInput("Enter the size of array");

    for (int i = 0; i < size; ++i)
        array[i] = intInput("Enter a digit");

    int key = intInput("Enter the value to search");

    int foundIndex = binarySearch(array, size, key);

    if (foundIndex == -1)
        printf("Value not found !!\n");
    else
        printf("Value found at index : %d\n", foundIndex);

    return 0;
}