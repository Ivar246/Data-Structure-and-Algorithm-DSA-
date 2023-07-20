#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top;

// check empty
int IsEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

// inserting data in stack
void Push(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
};

// deleting data from stack => pop
void Pop()
{
    if (top == NULL)
    {
        printf("Error: Empty stack");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

// return top element
int Top()
{
    if (top == NULL)
    {
        printf("Error: Empty Stack.");
        return -1;
    }
    return top->data;
}

// print element in the stack
void print()
{
    if (top == NULL)
    {
        printf("Error: Empty Stack.");
        return;
    }
    struct Node *temp = top;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    top = NULL;

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