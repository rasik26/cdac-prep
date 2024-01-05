#include<stdio.h>
#define SIZE 5

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;

int main()
{
    stack s1;

    return 0;
}

void init_stack(stack *ps)
{
    ps->top = -1;
}