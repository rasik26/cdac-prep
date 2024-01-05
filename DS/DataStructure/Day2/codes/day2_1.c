#include<stdio.h>
#define SIZE 6
#define swap(a,b) {int t = a;a=b; b=t;}
void selection_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
    //int arr[SIZE] = {30,20,60,50,10,40};
    int arr[SIZE] = {10,20,30,40,50,60};
    printf("Array before sort \n");
    display(arr);
    selection_sort(arr);
    printf("\nArray after sort !\n");
    display(arr);
    return 0;
}

void selection_sort(int arr[SIZE])
{
    int sel_pos,pos;
    int iterations = 0,comparisons = 0;
    for(sel_pos= 0 ;sel_pos<SIZE-1;sel_pos++)
    {
        iterations++;
        for(pos=sel_pos+1;pos<SIZE;pos++)
        {
            comparisons++;
            if(arr[sel_pos] > arr[pos]) // arr[0] > arr[1]   arr[0] > arr[2]
            {
                swap(arr[sel_pos],arr[pos]);
                //{int t = a;a=b; b=t;}
                /*
                    int t = arr[sel_pos];
                    arr[sel_pos] = arr[pos];
                    arr[pos] = t;
                */
            }
        }
    }
    printf("\nIterations = %d  comparisons = %d\n",iterations,comparisons);
}

void display(int arr[SIZE])
{
    for(int i =0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}