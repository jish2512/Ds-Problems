#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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
int stackTop(struct stack *s)
{
    return s->arr[s->top];
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
int isOperand(char a)
{
    if (a == '*' || a == '-' || a == '/' || a == '+')
        return 1;
    return 0;
}

int precedance(char a)
{
    if (a == '*' || a == '/')
        return 3;

    if (a == '+' || a == '-')
        return 1;

    return 0;
}

int isOperator(char a)
{
    if (a == '*' || a == '-' || a == '/' || a == '+')
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    char *infix = "a-b+t/6";
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    s->size = strlen(infix) + 1;
    s->top = -1;
    s->arr = (char *)malloc(strlen(infix) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[i] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedance(infix[i]) > precedance(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[i]=pop(s);
        j++;
    }
    postfix[j]='\0';
    printf("infix to postfix %s", postfix);
    return 0;
}
