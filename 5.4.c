#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int b_search(int* arr, int lower, int upper, int target)
{
    int mid=(upper+lower)/2;
    if(lower<=upper)
    {
        if(target<arr[mid])
            b_search(arr,lower,mid-1,target);
        else if(target > arr[mid])
            b_search(arr,mid+1,upper,target);
        else
            return 1;
    }
    else
        return 0;
}
int main()
{
    int n;
    printf("Enter the number of data: ");
    scanf("%d",&n);
    int arr[n];
    int lower=0;
    int upper=n-1;
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,n);
    int target;
    printf("Enter the data you want to search: ");
    scanf("%d",&target);
    int check=b_search(arr,lower,upper,target);
    if(check==1)
        printf("%d found!",target);
    else
        printf("%d not found!",target);
}
