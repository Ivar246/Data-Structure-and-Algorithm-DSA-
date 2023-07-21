#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Insert(struct Node *head, int data)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (!head)
    {
        head = new;
        return head;
    }
    struct Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new;

    return head;
}

// recursive reverse print
void recursiveReversePrint(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n");
        return;
    }
    recursiveReversePrint(ptr->next);
    printf("%d\t", ptr->data);
}

int main()
{
    struct Node *head = NULL;
    head = Insert(head, 5);
    head = Insert(head, 6);
    head = Insert(head, 7);
    head = Insert(head, 8);
    printf("Items in the list are: \n");
    recursiveReversePrint(head);

    return 0;
}