#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev, *next;
    int data;
};

struct Node *head; // global variable- pointer to head node

// finding length
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

// create new node
struct Node *GetNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// insert in begining
void insertAtFirst(int data)
{
    struct Node *newNode = GetNewNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// inserting in end
void insertAtEnd(int data)
{
    struct Node *newNode = GetNewNode(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

// inserting in specific position
void insertAtPosition(int data, int pos)
{
    if (pos > length())
    {
        printf("Invalid position.");
        return;
    }
    struct Node *newNode = GetNewNode(data);
    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// deleting first
void deleteFirst()
{
    if (head == NULL)
    {
        printf("Empty List.");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

// deleting last
void deleteLast()
{
    if (head == NULL)
    {
        printf("Empty List.");
        return;
    }
    struct Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// delete specific node
void deleteSpecificNode(int pos)
{
    if (pos < 1 || pos >= length())
    {
        printf("Invalid Position.");
        return;
    }
    if (head == NULL)
    {
        printf("Empty list.");
        return;
    }
    struct Node *temp = head;
    struct Node *temp2 = NULL;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    temp->next->prev = temp;
    free(temp2);
}

// void print
void print()
{
    if (head == NULL)
    {
        printf("list is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("list are: \n");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        printf("\t");
    }
}

int main()
{
    head = NULL;
    insertAtFirst(5);
    insertAtFirst(6);
    insertAtEnd(10);
    print();
    deleteSpecificNode(2);
    print();
}