#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

int palindrome(struct Node *head)
{
    char str[100];
    while (head != NULL)
    {
        str=str+head->data;
        head = head->next;
    }
    return 0;
}
void travelLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    push(&head, 45);
    push(&head, 22);
    push(&head, 32);
    push(&head, 12);
    push(&head, 443);
    travelLinkedList(head);
    printf(" sum = %d",sumofNodes(head));
    return 0;
}
