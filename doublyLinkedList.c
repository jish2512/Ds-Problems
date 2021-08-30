#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traverseDoublyList(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertFirstNode(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
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

    head->prev = NULL;
    head->data = 45;
    head->next = second;

    second->prev = head;
    second->data = 23;
    second->next = third;

    third->prev = second;
    third->data = 34;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 22;
    fourth->next = NULL;
    // int temp = *second->next;
    // printf("second address %d \n", temp);
    printf("before insertion \n");
    traverseDoublyList(head);

    head = insertFirstNode(head, 60);
    printf("after insertion \n");
    traverseDoublyList(head);
}
