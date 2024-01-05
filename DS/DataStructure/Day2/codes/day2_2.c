#include<stdio.h>
#define SIZE 6
#define swap(a,b) {int t = a;a=b; b=t;}
void bubble_sort(int arr[SIZE]);
void efficient_bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
    //int arr[SIZE] = {30,20,60,50,10,40};
    int arr[SIZE] = {1,2,3,4,5,6};
    printf("\n Before sort \n");
    display(arr);
   // bubble_sort(arr);
   efficient_bubble_sort(arr);
    printf("\nAfter sort\n");
    display(arr);
    return 0;
}

// efficient bubble
void efficient_bubble_sort(int arr[SIZE])
{
    int iterations = 0,comparisons = 0;
    int flag;
    for(int it = 0; it < SIZE-1 ; it++)
    {
        flag = 0;
        iterations++;
        for(int pos= 0; pos < SIZE-1-it;pos++)
        {
            comparisons++;
            if(arr[pos] > arr[pos+1])
            { // arr [0] > arr[1] -> arr[1] > arr[2]
                swap(arr[pos],arr[pos+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    printf("\niterations= %d  comparisons = %d\n",iterations,comparisons);
}

// normal bubble sort

void bubble_sort(int arr[SIZE])
{
    int iterations = 0,comparisons = 0;
    int flag;
    for(int it = 0; it < SIZE-1 ; it++)
    {
        
        iterations++;
        for(int pos= 0; pos < SIZE-1-it;pos++)
        {
            comparisons++;
            if(arr[pos] > arr[pos+1])
            { // arr [0] > arr[1] -> arr[1] > arr[2]
                swap(arr[pos],arr[pos+1]);
              
            }
        }
        
    }
    printf("\niterations= %d  comparisons = %d\n",iterations,comparisons);
}


void display(int arr[SIZE])
{
    for(int i =0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}
