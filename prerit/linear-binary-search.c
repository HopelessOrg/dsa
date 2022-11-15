#include <stdio.h>

// size of array
// SIZE must be written in all caps to comply with standard convention of c and cpp
#define SIZE 100

// enum to use boolean values
typedef enum bool {false, true} bool;
// it can be replaced by 
// #define FALSE 0
// #define TRUE 1
// but using enum gives us advantage of using it as return type

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

// function to perform binary search
int binarySearch(const int *array, int size, int key)
{
    int beg = 0; // initial values of beginning and end
    int end = size - 1;

    while (beg <= end)
    {
        int mid = (beg + end) / 2;

        if (array[mid] == key)
            return mid;            // when the element is found
        else if (key < array[mid]) // when the key is less than mid, means we have to work with first half
            end = mid - 1;
        else // when the key is greater than they value of mid, means we have to work in later half of array
            beg = mid + 1;
    }

    return -1; // in case element is not found
}

// function to perfrom linear search
int linearSearch(const int *list, int size, int key)
{
    for (int i = 0; i < size; ++i) // iterate from 0 to size - 1 to find the key
        if (key == list[i])
            return i; // if found, it will return the index of they element
    return -1;        // if not found, it will return -1, indicating item not found
}

// user interface
void usreInterface()
{
    int array[SIZE] = {0};    // declaration of array with predefined size

    do  // it will ensure that in any condition, the loop will run at least one time
    {
        int size = intInput("Enter the size of array");

        if (size < 2)   // if entered length is negative or 0 or 1, it will prompt user to use a bigger array
        {
            printf("Please enter a valid size\n");
            continue;
        }

        for (int i = 0; i < size; ++i)  // taking input in the array
            array[i] = intInput("Enter a digit");

        int key = intInput("Enter the value to search");    // taking input the value we want to search

        printf("%-40s : %5s\n", "Perform Linear search", "1");
        printf("%-40s : %5s\n", "Perform Binray search", "2");
        printf("%-40s : %5s\n", "Exit", "3");

        int output = -1;    // var to store the output value, index of searched key
        
        switch(intInput("Your choice"))
        {
            case 1: output = linearSearch(array, size, key); break;
            case 2: output = binarySearch(array, size, key); break;
            case 3: return;
            default: printf("Invalid choice\n");
        }

        if (output < 0)
            printf("Not found\n");
        else
            printf("%d found at index %d\n", key, output);
        
        printf("Do you want to continue another time [y/n]: ");   // try again ?
        
        char decision[5] = "";  // var to store the user input
        // space allocated is big enough that even someone types "yes"
        // it won't overflow and cause issues
        
        scanf("%s", decision);

        if (decision[0] == 'y' || decision[0] == 'Y')
            continue;
        else break;
    
    } while (true);
}

int main() // the origin, the end, the main function
{
    usreInterface();    // function to interact with user
    return 0;
}