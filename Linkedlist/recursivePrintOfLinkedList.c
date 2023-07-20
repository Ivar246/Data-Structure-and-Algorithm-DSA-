#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *tail;

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

// reverse
struct Node *reverse(struct Node *current, struct Node *prev)
{
    if (current == NULL)
    {
        return prev;
    }
    struct Node *next = current->next;
    current->next = prev;
    return reverse(next, current);
}

// recursive print
void print(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d\t", ptr->data);
    return print(ptr->next);
}

// recursive reverse print
void reversePrint(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n");
        return;
    }
    reversePrint(ptr->next);
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
    print(head);
    // head = reverse(head, NULL);
    reversePrint(head);
    return 0;
}