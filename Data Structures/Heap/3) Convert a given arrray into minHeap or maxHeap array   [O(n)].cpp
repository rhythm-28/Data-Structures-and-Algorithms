// Convert a given arrray into minHeap/maxHeap array
// O(n)

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

void heapify(vector<int> &a,int i,bool minHeap)
{
    int left=2*i;
    int right=(2*i)+1;
    int x=i;
    int n=a.size()-1;

    if(left<=n)
    {
        if(compare(a[left],a[x],minHeap))
        x=left;
    }

    if(right<=n)
    {
        if(compare(a[right],a[x],minHeap))
        x=right;
    }

    if(x!=i)
    {
        swap(a[x],a[i]);
        heapify(a,x,minHeap);
    }
}

void convert(vector<int> &a,int n,bool minHeap)
{   
    int i;
    for(i=(n-1)/2;i>0;i--)
    heapify(a,i,minHeap);
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