// Binary Search

#include <stdio.h>

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

    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==b)
        {
            c=m;
            break;
        }
        else if(b>a[m])
        {
            l=m+1;
        }
        else
        {
            h=m-1;
        }
    }
    
    if(l>h)
    printf("Element is not present");
    else
    printf("The value is present at the position %d : ", c+1);
    return 0;
}
