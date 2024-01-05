#include<stdio.h>
#define SIZE 9
int linear_search(int arr[SIZE],int key);
int comparisons = 0;
int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    int key;
    // accept the key from the user;
    printf("enter the key :");
    scanf("%d",&key);

    int index = linear_search(arr,key);
    if(index == -1)
        printf("Key not found !\n");
    else
        printf("key is found at index %d\n",index);
        printf("comparisons = %d\n",comparisons);

    return 0;
}

int linear_search(int arr[SIZE],int key)
{
    
    // start the traversal from 0th index
    for(int i = 0;i<SIZE;i++)
    {
        //compare each element with the key
        comparisons++;
        if(key == arr[i])
        {
            // return index
            return i;
        }
    }
    return -1;
}