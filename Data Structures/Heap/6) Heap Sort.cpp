// Heap Sort
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

void heapify(vector<int> &a,int i,bool minHeap,int size)
{
    int left=2*i;
    int right=(2*i)+1;
    int x=i;
    int n=size-1;

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
        heapify(a,x,minHeap,size);
    }
}

void convert(vector<int> &a,int n,bool minHeap)
{   
    int i;
    for(i=n/2;i>0;i--)
    heapify(a,i,minHeap,n);
}

void HeapSort(vector<int> &a,int n)
{
    // build heap
    // maxHeap for ascending & minHeap for descending
    convert(a,n,0);

    while(n>1)
    {
        // swap first with last
        swap(a[1],a[n-1]);

        // decrease size of array
        n--;

        // correct to form heap again
        heapify(a,1,0,n);
    }
}

int main()
{
    int n,i,d;
    vector<int> a;
    cin>>n;
    a.push_back(-1);
    for(i=0;i<n;i++)
    {
        cin>>d;
        a.push_back(d);
    }
    n++;
    HeapSort(a,n);
    for(i=1;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}