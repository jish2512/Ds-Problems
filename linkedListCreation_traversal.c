#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseLindedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *RemoveDuplicates(struct Node *head)
{
    struct Node *p = head;
    struct Node *z;
    while (p->next != NULL)
    {
        if (p->data == p->next->data)
        {
            z = p->next->next;
            free(p->next);
            p->next = z;
        }
        else
            p = p->next;
    }
    return head;
}
struct Node *InsertAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return head;
}
struct Node *InsertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
struct Node *ReverseLinkedList(struct Node *head){
    struct Node *prev=NULL;
    struct Node *current=head;
    struct Node *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}

struct Node *InsertAtindex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main(int argc, char const *argv[])
{
    /* code */
    struct Node *head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf(" Before Insert \n");
    printf("the head is %d \n",head->data);
    traverseLindedList(head);
    // head=InsertAtBeginning(head, 45);
    // head =InsertAtindex(head,2,45);
    // head =InsertAtEnd(head,45);
    head = ReverseLinkedList(head);
    printf(" After Insert \n");
    traverseLindedList(head);
    return 0;
}
