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

void merge(int* left,int len1,int* right,int len2,int* arr,int n )
{
    int i=0,j=0,k=0;
    while(i<len1 && j<len2)
    {
        if(left[i]<right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<len1)
        arr[k++]=left[i++];
    while(j<len2)
        arr[k++]=right[i++];
}
void m_sort(int* arr, int n)
{
    if(n>1)
    {
        int mid=n/2;
        int len1=mid;
        int len2=n-mid;
        int left[len1];
        int right[len2];
        int j=0;
        for(int i=0;i<mid;i++)
            left[j++]=arr[i];
        j=0;
        for(int i=mid;i<n;i++)
            right[j++]=arr[i];
        m_sort(left,len1);
        m_sort(right,len2);
        merge(left,len1,right,len2,arr,n);
    }
}
int main(int argc, char* argv[])
{
    //int n;
    int n=argc-1;
    //printf("Enter the number of data: ");
    //scanf("%d",&n);
    int arr[n];
    for(int i=1;i<argc;i++)
    {
        arr[i-1]=string_to_int(argv[i]);
    }
    /*printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);*/
    m_sort(arr,n);
    printf("After Sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
