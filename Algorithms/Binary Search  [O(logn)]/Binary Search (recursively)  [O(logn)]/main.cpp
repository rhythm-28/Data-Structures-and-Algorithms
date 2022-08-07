// Binary Search (recursively)

#include <stdio.h>

int Search(int l,int h,int a[],int b)
{
    int m=(l+h)/2;
    if(a[m]==b)
        return m;
    else if(b<a[m])
        return Search(l,m-1,a,b);
    else if(b>a[m])
        return Search(m+1,h,a,b);
}
int main()
{
    int l,h,m,a[100],b,c,n,i;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    printf("Enter elements of sorted array : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter value to be searched: \n");
    scanf("%d",&b);
    l=0;
    h=n-1;
    printf("The value is present at the position: %d ", Search(l,h,a,b)+1);
    return 0;
}
