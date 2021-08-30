#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}
int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int stackTop(struct stack *s){
    if (isEmpty(s) == 1)
    {
        printf("under overflow\n");
        return -1;
    }
    return s->arr[s->top];
}

int stackBottom(struct stack *s){
    if (isEmpty(s) == 1)
    {
        printf("under overflow\n");
        return -1;
    }
    return s->arr[0];
}
void push(struct stack *s, int data)
{
    if (isFull(s) == 1)
        printf("stack overflow\n");
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = data;
    }
}
int pop(struct stack *s)
{
    if (isEmpty(s) == 1)
    {
        printf("under overflow\n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top = s->top - 1;
        return val;
    }
}
void printStack(struct stack *s)
{
    if (!isEmpty(s))
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d \n", s->arr[i]);
        }
    }
}
int peek(struct stack *s,int position){
    if(s->top-position+1<0)printf("No number \n");
    return s->arr[s->top-position+1];
}

int main(int argc, char const *argv[])
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Is full %d\n", isFull(s));
    printf("Is Empty %d\n", isEmpty(s));
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    //push(s,6);
    printf("Is full after push %d\n", isFull(s));
    printf("Is Empty after push %d\n", isEmpty(s));

    printf("after push\n");
    printStack(s);

    int popped = pop(s);
    printf("after pop %d\n",popped);
    printf("after peek %d\n",peek(s,3));
    printStack(s);
    printf("stack top %d\n",stackTop(s));
    printf("stack bottom %d\n",stackBottom(s));
    return 0;
}
