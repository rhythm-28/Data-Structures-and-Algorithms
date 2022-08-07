// To sort n strings lexiographically

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s[100];
    int i,n;

    cin>>n;
    fflush(stdin);

    for(i=0;i<n;i++)
    getline(cin,s[i]);

    // Sorts s[0],s[1],s[2],.....,s[n-1] lexiographically
    sort(s,s+n);

    for(i=0;i<n;i++)
    cout<<s[i]<<endl;
    return 0;
}