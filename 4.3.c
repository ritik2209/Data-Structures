#include <stdio.h>
#include <stdlib.h>

void Heap(int* arr, int n)
{
    while(n>1 && arr[n]>arr[n/2])
    {
        int temp=arr[n];
        arr[n]=arr[n/2];
        arr[n/2]=temp;
        n=n/2;
    }
}

void HeapDel(int *arr,int n)
{
    for(int i=n;i>1;i--)
    {
        int temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
        for(int j=1;j<i;j++)
            Heap(arr,j);
    }
}
int main()
{
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the elements: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(i>1)
            Heap(arr,i);
    }
    printf("The Heap Array: ");
    for(i=1;i<=n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    HeapDel(arr,n);
    printf("The Sorted Array: ");
    for(i=1;i<=n;i++)
        printf("%d ",arr[i]);
}

