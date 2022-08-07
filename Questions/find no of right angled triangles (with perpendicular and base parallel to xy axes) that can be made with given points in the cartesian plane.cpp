// find no of right angled triangles (with perpendicular and base parallel to x/y axes) that can be made with given points in the cartesian plane

#include<iostream>
#include<unordered_map>
using namespace std;

int triangle(int n,int x[],int y[])
{
    int i,a,b;
    unordered_map<int,int> xc;
    unordered_map<int,int> yc;
    for(i=0;i<n;i++)
    {
        a=x[i];
        if(xc.find(a)==xc.end())
        xc[a]=1;
        else
        xc[a]+=1;

        b=y[i];
        if(yc.find(b)==yc.end())
        yc[b]=1;
        else
        yc[b]+=1;
    }
    int sum=0;
    for(auto p1:xc)
    {
        for(auto p2:yc)
        sum+=(p1.second-1)*(p2.second-1);
    }
    return sum;
}

int main()
{
    int n,i,x[100],y[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    cout<<triangle(n,x,y);
    return 0;   
}