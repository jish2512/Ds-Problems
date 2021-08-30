#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}
struct Node *deleteByValue(struct Node *head, int value)
{
    if (head->data == value)
    {
        head = deleteFirstNode(head);
        return head;
    }
    struct Node *ptr = head;
    struct Node *q = head->next;
    int i = 0;
    while (q->next != NULL)
    {
        if (q->data == value)
        {
            i = 1;
            break;
        }
        ptr = ptr->next;
        q = q->next;
    }
    if (i == 1)
    {
        ptr->next = q->next;
        free(q);
    }
    return head;
}

void main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 45;
    head->next = second;
    second->data = 23;
    second->next = third;
    third->data = 34;
    third->next = fourth;
    fourth->data = 22;
    fourth->next = NULL;
    // int temp = *second->next;
    // printf("second address %d \n", temp);
    printf("before deletion \n");
    traverseList(head);

    // head = deleteFirstNode(head);
    //head = deleteAtEnd(head);
    //head = deleteAtIndex(head, 2);
    head = deleteByValue(head, 60);
    printf("after deletion \n");
    traverseList(head);
}
