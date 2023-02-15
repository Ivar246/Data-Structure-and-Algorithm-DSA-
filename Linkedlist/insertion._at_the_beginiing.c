#include <stdio.h>
#include <stdlib.h>

// creating node
struct Node
{
    int data;
    struct Node *next;
};

// pointer to head node
// stores address of head
struct Node *head;

void InsertAtBegining(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d/n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = NULL; // empty head points nowhere
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number:\n");
        scanf("%d", &x);
        InsertAtBegining(x);
        Print();
    }
    return 0;
}