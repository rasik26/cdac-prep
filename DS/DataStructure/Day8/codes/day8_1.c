// linear queue
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
void display(queue *pq);
int get_front(queue *pq);

int main()
{
    int choice;
    int ele;
    queue Q;
    init_queue(&Q);
do
{
    printf("\nEnter your choice !\n");
    printf("0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 0:
            exit (0);
        case 1: // enqueue
            if(is_queue_full(&Q))
            {
                printf("Queue is full !");
            }
            else
            {
                printf("enter the element to push !");
                scanf("%d",&ele);
                enqueue(&Q,ele);
                printf("%d pushed into queue !",ele);
            }
            break;
        case 2: // dequeue
            if(is_queue_empty(&Q))
                printf("Queue is empty!");
            else
            {
                
                int val = get_front(&Q);
                dequeue(&Q);
                printf("value deleted = %d\n",val); // 17
            }
            break;
        case 3:
                if(is_queue_empty(&Q))
                    printf("Queue is empty !");
                else
                    display(&Q);
                    break;
        default: 
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
    pq->rear++;
    pq->arr[pq->rear] = val;
    if(pq->front == -1)
        pq->front = 0;

}

void dequeue(queue *pq)
{
    pq->arr[pq->front] = 0;
    pq->front++;
}

int is_queue_full(queue *pq)
{
   
        if(pq->rear == SIZE -1)
            return 1;
        else
            return 0;
    
    
  //  return (pq->rear == SIZE -1);
}

int is_queue_empty(queue *pq)
{
    if(pq->rear == -1 || pq->front > pq->rear)
        return 1;
    else    
        return 0;
}


void display(queue *pq)
{
    int i;

    for(i=pq->front ; i<=pq->rear ; i++) // i = 0 ;i<=2
    {
        printf("%4d",pq->arr[i]); // arr[3] arr[4]
    }
}

int get_front(queue *pq)
{
    return pq->arr[pq->front];
}