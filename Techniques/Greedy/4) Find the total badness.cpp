// Find the total badness
// badness = | alloted rank-preferred rank |

// O(max_value-min_value)
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n,a[10000],b[10000],i,c,ma;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    // finding max
    ma=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>ma)
        ma=a[i];
    }

    for(i=1;i<=ma;i++)
    b[i]=0;

    for(i=0;i<n;i++)
    {
        c=a[i];
        b[c]++;
    }

    int x,badness=0,rank=1;
    for(i=1;i<=ma;i++)
    {
        x=b[i];
        while(x!=0)
        {
            badness+=abs(i-rank);
            rank++;
            x--;
        }
    }
    cout<<badness;
    return 0;
}