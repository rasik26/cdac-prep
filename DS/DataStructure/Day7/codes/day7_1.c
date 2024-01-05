#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;
void init_stack(stack *ps);
void push(stack *ps,int val);
void pop(stack *ps);
int peek(stack *ps);
int is_stack_full(stack *ps);
int is_stack_empty(stack *ps);

int main()
{
    int choice;
    stack s;
    int value;
    init_stack(&s);
do
{
    printf("enter your choice :\n");
    printf("0.Exit\n1.Push\n2.Pop\n3.Peek :\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
            exit(0);

        case 1: // push
            if(is_stack_full(&s))
            {
                printf("Stack is full");
            }
            else
            {
                printf("Enter the value to push into the stack :");
                scanf("%d",&value);
                push(&s,value);
                printf("The value pushed = %d\n",value);
            }
            break;
        case 2: // pop
                if(is_stack_empty(&s))
                {
                    printf("stack is empty! nothing to pop !\n");
                }
                else
                {
                    int element = peek(&s);
                   pop(&s);
                    printf("element popped = %d\n",element);
                }
                break;
            case 3:
                if(is_stack_empty(&s))
                    printf("Stack empty !nothing to peek !");
                else
                {
                    int ele = peek(&s);
                    printf("Topmost element to peek = %d\n",ele);
                }
                break;
            default:
                printf("enter the valid choice between 0 to 3!");

    }
}while(choice !=0);
    return 0;
}

void init_stack(stack *ps)
{
    ps->top = -1;
}

void push(stack *ps,int val)
{
    ps->top++;
    ps->arr[ps->top] = val;
}

void pop(stack *ps)
{
    ps->arr[ps->top] = 0;
    ps->top--;
}

int peek(stack *ps)
{
    return ps->arr[ps->top];
}

int is_stack_full(stack *ps)
{
    if(ps->top == SIZE-1)
        return 1;
    else 
        return 0;
}

int is_stack_empty(stack *ps)
{
    if(ps->top == -1)
        return 1;
    else
        return 0;
}