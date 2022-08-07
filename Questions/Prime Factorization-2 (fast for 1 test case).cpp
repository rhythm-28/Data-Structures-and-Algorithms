// Prime Factorization 
// For 1 test case = O(root n)
// For n test cases = O(n* root n)

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {        
            while(n%i==0)
            {
                 n=n/i;
                 cout<<i<<" ";
            }
        }
    }
    if(n!=1)
    cout<<n;
    return 0;
}