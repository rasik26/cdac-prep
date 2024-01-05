
// binary search- prerequisite - sorted array
#include<stdio.h>
#define SIZE 9
int binary_search(int arr[SIZE],int key);
int comparisons = 0;
int main()
{
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    int key;

    printf("Enter the key to search :");
    scanf("%d",&key);
    int index = binary_search(arr,key);
    if(index == -1)
        printf("Key not found !");
    else
        printf("Key is found at index %d\n",index);
        printf("no. of comparisons = %d\n",comparisons);
    return 0;
}

int binary_search(int arr[SIZE],int key)
{
    int left = 0, right = SIZE-1,mid;

    while(left <= right)
    {
        comparisons++;
        mid = (left+right) / 2;

        if(key == arr[mid])
            return mid; 
        
        if(key < arr[mid])
            right = mid -1;
        else // key > arr[mid]
            left = mid+1;
    }

    return -1;
}