// To find natural numbers less than m which are divisible by 2,3,5,7,11,13,17 or 19

#include<iostream>
#include<math.h>
using namespace std;

static int ans=0;

void filter(int no,int a[],int m)
{
    int j=0,last_bit,product=1,elements=0;
    int nos_div;
    while(no>0)
    {
        last_bit=(no&1);

        //Finds subsets
        if(last_bit==1)
        {
            // finds product of numbers in the subset and counts no of elements
            product*=a[j];
            elements++;
        }

        j++;
        no=no>>1;
    }

    //finds the number of such numbers which are divisible by the product of subsets 
    nos_div=m/product;

    //inclusion/exclusion
    if(elements%2==0)
    ans-=nos_div;
    else
    ans+=nos_div;
}

void find_Subsets(int a[],int size,int m)
{
    int i;
    for(i=1;i<pow(2,size);i++)
    filter(i,a,m);
}

int main()
{
    int t,m,i,j;
    int primes[8]={2,3,5,7,11,13,17,19},a[8];
    cin>>t;
    while(t--)
    {
        cin>>m;
        ans=0;

        //finding prime numbers smaller than m
        for(i=0;i<8;i++)
        {
            if(m<=primes[i])
            break;
        }

        // if m is greater than all fixed prime numbers
        if(i==8)
        i=7;

        for(j=0;j<=i;j++)
        a[j]=primes[j];

        find_Subsets(a,i+1,m);

        cout<<ans<<endl;
    }
    return 0;
}