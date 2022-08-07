// Selection Sort (Optimized)

#include <stdio.h>

int main()
{
    int n,i,j,temp=0,a[100],min_index;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n-1;i++)
    {
        min_index=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<a[min_index])
            min_index=j;
        }
        
        //Swapping only one time for every element in array

        temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;
    }
    printf("The sorted array is: ");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
