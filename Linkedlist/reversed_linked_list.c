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
struct Node *reverse(struct Node *head)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        // preserving next of current
        next = current->next;
        // setting current next to previous node address
        current->next = prev;
        // reseting previous and current pointer
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void print(struct Node *head)
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
    struct Node *head = NULL;
    head = Insert(head, 5);
    head = Insert(head, 6);
    head = Insert(head, 7);
    head = Insert(head, 8);
    print(head);
    head = reverse(head);
    print(head);
    return 0;
}