#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

// inserting
void Insert(int data)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (!head)
    {
        head = new;
        return;
    }
    struct Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new;
}

// reverse linked list using recursion
void reverse(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }

    reverse(p->next); // reversed
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

// printing data
void print()
{
    struct Node *temp = head;
    printf("list are: \n");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        printf("\n");
    }
}

int main()
{
    head = NULL;
    Insert(5);
    Insert(8);
    Insert(3);
    print();
    reverse(head);
    print();
    return 0;
}