#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = head;
    newNode->data = data;
    head = newNode;
    return head;
}

void traverseLD(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
}
int isFull(struct Node *head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
        return 1;
    return 0;
}
int isEmpty(struct Node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}
int pop(struct Node **head)
{
    struct Node *ptr = *head;
    *head = (*head)->next;
    int val = ptr->data;
    // printf("popped item %d \n", val);
    free(ptr);
    return val;
}
int stackTop(struct Node *head)
{
    if (isFull(head))
        return head->data;
    return -1;
}

int stackBottom(struct Node *head)
{
    if (isFull(head))
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        return head->data;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 7);

    traverseLD(head);
    printf("is Empty %d\n", isEmpty(head));
    printf("is Full %d\n", isFull(head));
    //head = pop(head);
    // printf("the popped value is %d\n", pop(head));
    traverseLD(head);
    printf("stack bottom %d\n", stackBottom(head));
    printf("stack top %d\n", stackTop(head));
    printf("popped item %d \n", pop(&head));
    traverseLD(head);
    return 0;
}
