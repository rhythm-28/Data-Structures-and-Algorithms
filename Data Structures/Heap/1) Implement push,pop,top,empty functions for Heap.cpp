// Implement push,pop,top,empty functions for Heap

#include<iostream>
#include<vector>
using namespace std;

class Heap
{
    vector<int> a;
    bool minHeap;

    bool compare(int a,int b)
    {
        if(minHeap==true)
        return a<b;
        else
        return a>b;
    }

    void heapify(int i)
    {
        int left=2*i;
        int right=(2*i)+1;
        int x=i;
        int n=a.size()-1;

        if(left<=n)
        {
            if(compare(a[left],a[x]))
            x=left;
        }

        if(right<=n)
        {
            if(compare(a[right],a[x]))
            x=right;
        }

        if(x!=i)
        {
            swap(a[x],a[i]);
            heapify(x);
        }
    }

    public:

    int i,parent;

    Heap(bool b)
    {
        minHeap=b;
        a.push_back(-1);
    }

    void push(int data)
    {
        a.push_back(data);
        i=a.size()-1;
        parent=i/2;
        while(i>1 && compare(a[i],a[parent]))
        {
            swap(a[i],a[parent]);
            i=parent;
            parent=parent/2;
        }
    }

    // returns maximum priority element for maxHeap
    // returns minimum priority element for minHeap
    // returns root node
    int top()
    {
        return a[1];
    }

    void pop()
    {
        // swap with klast element
        swap(a[1],a[a.size()-1]);

        // delete the last element
        a.pop_back();

        // place the new top to its correct position
        heapify(1);
    }

    bool empty()
    {
        return a.size()==1;
    }
};

void input(Heap &h,int n)
{
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        h.push(d);
    }
}

void print(Heap h)
{
    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
}

int main()
{
    int n;
    bool b;
    // true(1) for minHeap
    // false(0) for maxHeap
    cin>>b;
    cin>>n;
    Heap h(b);
    input(h,n);
    print(h);
    return 0;
}