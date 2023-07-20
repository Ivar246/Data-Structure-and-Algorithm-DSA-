#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *tail;

int length()
{
    int l = 0;
    struct Node *temp = head;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

void insertAtBegining(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtEnd(int data)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    int l = length();
    if (l == 0)
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

// insert in nth position
void insert(int data, int n)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if (n == 1)
    {
        new->next = head;
        head = new;
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < n - 1; i++)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

// delete node

// delete the begining node
int deleteFirst()
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
}

// delete node from end
int deleteLast()
{
    if (head == NULL)
    {
        return 0;
    }
    struct Node *temp1 = head;
    struct Node *temp2 = NULL;
    while (temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
}

// // delete node before targetPosition
// void deleteBefore(int n)
// {
//     struct Node *temp1 = head;
//     struct Node *temp2 = NULL;
//     for (int i = 1; i < n - 1; i++)
//     {
//         temp2 = temp1;
//         temp1 = temp1->next;
//     }
//     temp2->next = temp1->next;
//     temp1->next = NULL;
//     free(temp1);
// }

// iterative print of linked list
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

    insertAtBegining(5);
    insertAtBegining(6);
    insertAtBegining(7);
    insertAtBegining(8);
    insertAtEnd(1);
    insert(25, 2);

    print();
    // deleteBefore(2);
    // deleteFirst();
    // deleteLast();

    print();
    printf("The length of list is %d", length());
    return 0;
}