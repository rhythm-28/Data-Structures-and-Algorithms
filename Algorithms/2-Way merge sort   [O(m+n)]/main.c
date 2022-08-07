// 2-Way merge sort

#include <stdio.h>

int main()
{
    int i=0,j=0,k=0,t,a[10],b[10],c[20],m,n;
    printf("Enter size of first sorted array: \n");
    scanf("%d",&m);
    printf("Enter elements of first array: \n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter size of second sorted array: \n");
    scanf("%d",&n);
    printf("Enter elements of second array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    i=0;
    while(i!=m && j!=n)
    {
        if(a[i]<=b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else if(a[i]>b[j])
        {
            c[k]=b[j];
            k++;
            j++;
        }
    }
    while(i!=m)
    {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j!=n)
    {
        c[k]=b[j];
        k++;
        j++;
    }
    for(t=0;t<k;t++)
    {
        printf("\n%d",c[t]);
    }
    return 0;
}
