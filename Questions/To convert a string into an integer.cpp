//To convert a string into an integer

#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int int_convert(string b)
{
    int ans=0,p=1,n=b.length(),i;
    for(i=n-1;i>=0;i--)
    {
        ans+=((b[i]-'0')*p);
        p=p*10;
    }
    return ans;
}

int main()
{
    string s;
    int a;
    getline(cin,s);
    a=int_convert(s);
    cout<<a;
    return 0;
}