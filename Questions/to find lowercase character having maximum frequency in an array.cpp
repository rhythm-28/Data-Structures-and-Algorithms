// to find lowercase character having maximum frequency in an array
// Counting Sort
// Hashing
// [O(m)/ O(n)]
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int n,b[30],i,c;
    string s;
	cin>>s;
    for(i=0;i<26;i++)
    b[i]=0;
	n=s.length();
    for(i=0;i<n;i++)
    {
        c=s[i]-97;
        b[c]++;
    }
	int max=b[0],j=0;
	char ch;
    for(i=0;i<26;i++)
    {
        if(b[i]>=max)
		{
			max=b[i];
			j=i+97;
		}
    }
	cout<<(char)j;
    return 0;
}