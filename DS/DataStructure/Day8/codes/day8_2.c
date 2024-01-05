// circular queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct queue
{
    int arr[SIZE];
    int front; 
    int rear;
}queue;
 
void init_queue(queue *pq);
void enqueue(queue *pq,int val);
void dequeue(queue *pq);
int is_queue_full(queue *pq);
int is_queue_empty(queue *pq);
int get_front(queue *pq);
void display(queue *pq);
int main()
{
    int choice,value;
    queue Q;
    init_queue(&Q);
do
{
    printf("\nEnter the choice \n");
    printf("0. Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
            exit(0);
        case 1:
            if(is_queue_full(&Q))
                printf("Queue is full !");
            else
            {
                printf("enter the value !");
                scanf("%d",&value);
                enqueue(&Q,value);
                printf("%d is pushed into queue !",value);
            }
            break;
        case 2:
            if(is_queue_empty(&Q))
                printf("Queue is empty !");
            else
            {
                int num = get_front(&Q);
                dequeue(&Q);
                printf("Value deleted = %d\n",num);

            }
            break;
        case 3:
            if(is_queue_empty(&Q))
                printf("Queue is empty !");
            else
                display(&Q);
            break;
        default :
            printf("enter valid choice !");
    }
}while(choice != 0);

    return 0;
}

void init_queue(queue *pq)
{
    pq->front = -1;
    pq->rear = -1;
}

void enqueue(queue *pq,int val)
{
    pq->rear = (pq->rear+1)%SIZE;
    pq->arr[pq->rear] = val;
    if(pq->front == -1)
        pq->front = 0;
}

void dequeue(queue *pq)
{
    if(pq->front == pq->rear) // deleteing last element
        pq->front = pq->rear = -1;
    else
        pq->front = (pq->front+1) % SIZE;
}

int is_queue_full(queue *pq)
{
    if(pq->front == (pq->rear +1) % SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_queue_empty(queue *pq)
{
    if(pq->rear == -1 )
        return 1;
    else
        return 0;
}

int get_front(queue *pq)
{
    return pq->arr[pq->front];
}

void display(queue *pq)
{
    int i;
    for(i=pq->front ; i<= pq->rear ;i++)
    {
        printf("%4d",pq->arr[i]);
    }
    printf("\n");
}