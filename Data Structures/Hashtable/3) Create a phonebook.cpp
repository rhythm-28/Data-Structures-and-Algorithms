// Create a phonebook

#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    unordered_map<string,vector<string>> a;
    int n,i,m,j;
    string name,number;
    vector<string> v;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>name;
        cin>>m;
        for(j=0;j<m;j++)
        {
            cin>>number;
            v.push_back(number);
        }
        a.insert(make_pair(name,v));
        v.clear();
    }

    for(auto p:a)
    {
        cout<<p.first<<"->";
        for(auto k:p.second)
        cout<<k<<",";
        cout<<endl;
    }
    return 0;
}