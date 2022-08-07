//To convert a string into an integer (using recursion)

#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int int_convert(string b,int i,int p)
{
    if(i==-1)
    return 0;
    else
    return (b[i]-'0')*p+int_convert(b,i-1,p*10);
}

int main()
{
    string s;
    int a;
    getline(cin,s);
    a=int_convert(s,s.size()-1,1);
    cout<<a;
    return 0;
}