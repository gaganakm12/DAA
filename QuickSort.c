#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
int partition(int A[size],int l,int r)
{
    int i,j,pivot,temp;
    pivot=A[l];
    i=l+1;
    j=r;
    while(1)
    {
        while(pivot>=A[i]&&i<=r)
        {
            count++;
            i++;
        }
        while(pivot<A[j])
        {
            count++;
            j--;
        }
        count++;
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        else
        {
            temp=A[j];
            A[j]=A[l];
            A[l]=temp;
            return j;
        }
    }
}
void quicksort(int A[size],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(A,l,r);
        quicksort(A,l,s-1);
        quicksort(A,s+1,r);
    }
}
int main()
{
    int n,A[size],i;
    printf("Enter size:\n");
    scanf("%d",&n);
    printf("\nRead the elements:\n");
    for(i=0;i<=n-1;i++)
        scanf("%d",&A[i]);
    quicksort(A,0,n-1);
    printf("\nThe sorted elements are:\n");
    for(i=0;i<=n-1;i++)
        printf("%d\t",A[i]);
    printf("\nCount=%d",count);
    return 0;
}
