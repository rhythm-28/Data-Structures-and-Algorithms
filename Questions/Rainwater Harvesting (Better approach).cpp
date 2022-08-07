//Rainwater Harvesting

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,i,j,y,sum=0;
    vector<int> a;
    vector<int> l;
    vector<int> r;
    vector<int> temp;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y;
        a.push_back(y);
    }

    // Looking for the highest building on left side
    l.push_back(a[0]);
    for(i=1;i<n;i++)
    l.push_back( max(l[i-1],a[i]) );
    
    //Looking for the highest building on right side
    // The method is different from left side because vector can't store the last element first
    // If array was used, a procedure similar to left highest building would have been adopted for right side too
    j=0;
    temp[j]=a[n-1];
    for(i=n-2;i>=0;i--)
    {
        temp.push_back( max(temp[j],a[i]) );
        j++;
    }
    
    for(i=n-1;i>=0;i--)
    r.push_back(temp[i]);

    for(i=0;i<n;i++)
    sum+=( min(l[i],r[i])-a[i] );

    cout<<sum;
    
    return 0;
}