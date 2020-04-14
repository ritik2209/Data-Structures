#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int string_to_int(char* s)
{
    int len=strlen(s);
    int i,num=0;
    for(i=0;i<len;i++)
    {
        num=num*10+(s[i]-'0');
    }
    //printf("The Number is: %d\n",num);
    return num;
}

int partition(int* arr, int start, int end)
{
    int pIndex=start;
    int pivot=arr[end];
    for(int i=start;i<=end;i++)
    {
        if(arr[i]<arr[pIndex])
        {
            int temp=arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            pIndex++;
        }
    }
    int temp=arr[pIndex];
    arr[pIndex]=arr[end];
    arr[end]=temp;
    return pIndex;
}

void q_sort(int* arr, int start, int end )
{
    if(start<end)
    {
        int pIndex=partition(arr,start,end);
        q_sort(arr, start, pIndex-1);
        q_sort(arr, pIndex+1, end);
    }
}
int main(int argc, char* argv[])
{
    int n=argc-1;
    /*printf("Enter the number of data: ");
    scanf("%d",&n);*/
    int arr[n];
    for(int i=1;i<argc;i++)
    {
        arr[i-1]=string_to_int(argv[i]);
    }
    //printf("Enter the elements: ");
    //for(int i=0;i<n;i++)
        //scanf("%d",&arr[i]);
    q_sort(arr,0,n-1);
    printf("After Sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
