// To find maximum sum of elements of array such that no two consecutive elements are taken

#include<iostream>
#include<math.h>
using namespace std;

int filter(int n,int a[])
{
    static int max=0;
    int j=0,current_bit,previous_bit=0,sum=0;
    while(n>0)
    {
        current_bit=(n&1);

        if(current_bit==1 && previous_bit==1)
        return max;

        else if(current_bit==1)
        sum+=a[j];

        j++;
        n=n>>1;
        previous_bit=current_bit;
    }

    if(sum>max)
    max=sum;

    return max;
}

void find_specialized_Subsets(int a[],int n)
{
    int i,max;
    for(i=0;i<pow(2,n);i++)
    max=filter(i,a);
    cout<<max;
}

int main()
{
    int i;
    int a[100000],n;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    find_specialized_Subsets(a,n);
    return 0;
}