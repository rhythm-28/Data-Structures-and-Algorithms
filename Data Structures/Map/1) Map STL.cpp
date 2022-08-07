// Map STL

#include<iostream>
#include<map>
#include<utility>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // 1) Insertion
    map<int,int> m;
    int a=3,b=5;
    m.insert(make_pair(3,5));

    // 2) another way to insert
    m[100]=2000;
    cout<<m[100]<<endl;

    // 3) Print a particular key element
    cout<<m[3]<<endl;

    // 4) To update an existing value
    int x=3,y=6;
    m[x]=y; 
    cout<<m[x]<<endl;

    m[x]+=1001;
    cout<<m[x]<<endl;

    // 5) to search for an element using key
    auto it=m.find(3);
    if(it!=m.end())
    cout<<it->second<<endl;

    // 6) to iterate over all elements
    for(auto it=m.begin();it!=m.end();it++)
    cout<<(*it).first<<"->"<<it->second<<endl;;
    cout<<endl;

    return 0;
}