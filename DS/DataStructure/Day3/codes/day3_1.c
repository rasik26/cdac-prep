#include<stdio.h>
#define SIZE 6
void insertion_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
  //  int arr[SIZE] = {55,44,22,66,11,33};
  int arr[SIZE] = {1,2,3,4,5,6};
    printf("Before Sort !\n");
    display(arr);
    printf("After sort !\n");
    insertion_sort(arr);
    display(arr);
    return 0;
}

void insertion_sort(int arr[SIZE])
{
    int i,key,j;
    int iterations = 0,count = 0;
    for(i=1;i<SIZE;i++)
    {
        j = i-1;
        key = arr[i];
        iterations++;
        while(j >=0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
            count++;
        }
        arr[j+1] = key;
    }
    printf("\nIterations = %d  count = %d\n",iterations,count);
}

void display(int arr[SIZE])
{
    for(int i =0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}