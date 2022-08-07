// Find maximum length of sub-string with no repeating character

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int h[256],i,n;
    char s[100];
    cin>>s;
    for(i=0;i<255;i++)
    h[i]=-1;
    n=strlen(s);
    int last_occur,length=0,max=0;
    for(i=0;i<n;i++)
    {
        last_occur=h[s[i]];

        if(last_occur==-1 || i-last_occur>length)
        length++;

        else
        length=i-last_occur;

        h[s[i]]=i;

        if(max<length)
        max=length;
    }
    cout<<max;
    return 0;
}