#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseCircularList(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertFirstNode(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->next;
    ptr->data=data;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
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

    head->data = 45;
    head->next = second;
    second->data = 23;
    second->next = third;
    third->data = 34;
    third->next = fourth;
    fourth->data = 22;
    fourth->next = head;
    // int temp = *second->next;
    // printf("second address %d \n", temp);
    printf("before insertion \n");
    traverseCircularList(head);

    head = insertFirstNode(head, 60);
    printf("after insertion \n");
    traverseCircularList(head);
}
