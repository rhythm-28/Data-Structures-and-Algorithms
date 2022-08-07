// To create subsets of a character array

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

void filter(int n,char a[])
{
    int j=0,last_bit;
    while(n>0)
    {
        last_bit=(n&1);
        if(last_bit==1)
        cout<<a[j];
        j++;
        n=n>>1;
    }
    cout<<endl;
}

void find_Subsets(char a[])
{
    int n=strlen(a),i;
    for(i=0;i<pow(2,n);i++)
    filter(i,a);
}

int main()
{
    int i;
    char a[100000];
    fflush(stdin);
    cin>>a;
    find_Subsets(a);
    return 0;
}