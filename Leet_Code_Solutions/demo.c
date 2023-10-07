#include <stdio.h>

int main(void)
{
    goto myLabel; // Jump to the label

myLabel: // Define the label
{
    printf("Hello ");
    printf("World");
    printf("!\n");
}

    return 0;
}