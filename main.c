#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int count;
int bfsm(char t[20], char p[10])
{
    int n,m,i,j;
    n=strlen(t);
    m=strlen(p);
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m&&p[j]==t[i+j])
        {
            j=j+1;
            count++;
        }
        count++;
        if(j==m)
            return i;
    }
    return -1;
}

int main()
{
    int flag;
    char t[100],p[100];
    printf("\nRead text:\n ");
    scanf("%s",t);
    printf("\nRead pattern:\n ");
    scanf("%s",p);
    flag=bfsm(t,p);
    if(flag==-1)
    {
        printf("\nPattern not found ");
        printf("\nCount=%d",count);
    }
    else
    {
        printf("\nPattern found %d",flag+1);
        printf("\nCount=%d",count-1);
    }
    return 0;
}
