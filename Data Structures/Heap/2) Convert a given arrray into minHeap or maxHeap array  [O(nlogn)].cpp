// Convert a given arrray into minHeap/maxHeap array
// O(nlogn)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b,bool minHeap)
    {
    if(minHeap==true)
    return a<b;
    else
    return a>b;
}

void convert(vector<int> &a,int n,bool minHeap)
{   
    int i;
    for(i=2;i<n;i++)
    {
        int idx=i;
        int parent=i/2;
        while(idx>1 && compare(a[idx],a[parent],minHeap))
        {
            swap(a[idx],a[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
}

int main()
{
    int n,i,d;
    vector<int> a;
    a.push_back(-1);
    bool b;
    // true(1) for minHeap
    // false(0) for maxHeap
    cin>>b;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>d;
        a.push_back(d);
    }
    n++;
    convert(a,n,b);
    for(i=1;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}