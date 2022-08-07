// To find length of largest subsequence of consecutive integers (using set)

#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int function(int a[],int n)
{
    // created set to minimize searching time
    // searching an element in array requires O(n) time
    // searching an element in unordered set requies O(1) time 
    unordered_set<int> s;
    int i;
    for(i=0;i<n;i++)
    s.insert(a[i]);

    int count=1,ans=1;
    for(i=0;i<n;i++)
    {
        int x=a[i];
        auto it=s.find(x-1);
        if(it==s.end())
        {
            x++;
            while(s.find(x)!=s.end())
            {
                count++;
                x++;
            }
            ans=max(ans,count);
            count=1;
        }
    }
    return ans;   
}

int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<function(a,n);
    return 0;
}
