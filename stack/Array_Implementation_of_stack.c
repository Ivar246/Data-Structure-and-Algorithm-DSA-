#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// inserting data in stack
void Push(int x)
{
    if (top == (MAX_SIZE - 1))
    {
        printf("Error: Stack OverFlow.");
        return;
    }
    top++;
    stack[top] = x;
}

// deleting data from stack => pop
void Pop()
{
    if (top == -1)
    {
        printf("Error: Empty Stack.");
        return;
    }
    top--;
}

// return top element
int Top()
{
    if (top == -1)
    {
        printf("Error: Empty Stack.");
        return -1;
    }
    printf("%d", stack[top]);
}

// check empty
int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

// print element in the stack
void print()
{
    if (top == -1)
    {
        printf("Error: empty stack.");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main()
{

    Push(5);  // insert 5
    Push(3);  // insert 3
    Push(12); // insert 12
    Pop();    // delete top => 12
    printf("Element in top of stack: \t");
    Top();
    printf("\nElement in the stack are: \n");
    print();
    return 0;
}