#include <stdint.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

// function to insert data in list
void Insert(int d, int n)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = d;
    temp1->next = NULL;

    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

// print data in linked list
void Print();
int main()
{
    head = NULL; // empty list
    Insert(2, 1);
    Insert(5, 2);
    Insert(41, 1);
}