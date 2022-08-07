// To remove consecutive duplicates from a string

#include<iostream>
using namespace std;
int main()
{
    int n;
    char a[10];
    cin>>n;
    fflush(stdin);
    cin.getline(a,n);
    int i,j=0;
    for(i=1;i<n;i++)
    {
        if(a[i]!=a[j])
        {
            j++;
            a[j]=a[i];
        }
    }
    a[j+1]='\0';
    for(i=0;i<j;i++)
    cout<<a[i];
    return 0;
}