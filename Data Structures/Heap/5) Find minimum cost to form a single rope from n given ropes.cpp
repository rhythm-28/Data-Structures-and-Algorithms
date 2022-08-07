// Find minimum cost to form a single rope from n given ropes
// cost of joining 2 ropes with length a & b = a+b

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int find_cost(vector<int> a,int n)
{
    int i,x,y,z,cost=0;
    //for(i=0;i<n;i++)
    //h.push(a[i]);
    priority_queue< int, vector<int> , greater<int> > h(a.begin(),a.end());
    while(h.size()>1)
    {
        // find 2 minimum elements
        x=h.top();
        h.pop();
        y=h.top();
        h.pop();

        // find cost
        z=x+y;
        cost+=z;

        // update heap with new rope 
        h.push(z);
    }
    return cost;
}   

int main()
{
    int n,i,d;
    vector<int> a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>d;
        a.push_back(d);
    }
    cout<<"minimum cost is "<<find_cost(a,n);
    return 0;
}