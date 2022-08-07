// Largest of n character arrays
// O(n)

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,n,m,b,max=0;
    char a[100],c[100];
    cin>>n;
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        cin.getline(a,m);
        fflush(stdin);
        b=strlen(a);
        if(b>=max)
        {
            max=b;
            strcpy(c,a);
        }
    }
    cout<<c;
    return 0;
}