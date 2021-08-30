#include <stdio.h>
#include <stdlib.h>

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
int main(int argc, char const *argv[])
{
    char str[] = "7-(8(3*9)+(11+12)-8)()";
    int len = sizeof(str) / sizeof(char);
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = len+1;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char underFlow = 'N';
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' && !isFull(s))
        {
            s->top = s->top + 1;
            s->arr[s->top] = str[i];
        }
        if (str[i] == ')')
        {
            if (isEmpty(s))
            {
                underFlow = 'Y';
                break;
            }
            s->top = s->top - 1;
        }
    }
    if (underFlow == 'Y')
        printf(" stack is underflow not balanced \n");
    else if (s->top > -1)
        printf("UnBalanced\n");
    else
        printf("Balanced\n");
    return 0;
}
