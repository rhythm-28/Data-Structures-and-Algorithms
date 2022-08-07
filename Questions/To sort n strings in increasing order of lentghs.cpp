// To sort n strings in increasing order of lentghs

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string s1,string s2)
{
    int a=s1.length(),b=s2.length();
    return a<b;
}
int main()
{
    string s[100];
    int i,n;

    cin>>n;
    fflush(stdin);

    for(i=0;i<n;i++)
    getline(cin,s[i]);

    sort(s,s+n,compare);

    for(i=0;i<n;i++)
    cout<<s[i]<<endl;
    return 0;
}