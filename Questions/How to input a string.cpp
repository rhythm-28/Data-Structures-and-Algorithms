// How to input a string
// How cin.getline works internally

#include<iostream>
using namespace std;
void Read(char a[],int n,char delim)
{
    char ch;
    ch=cin.get();
    int i=0;
    while(ch!=delim)
    {
        a[i]=ch;
        i++;
        if(i==(n-1))
        break;
        ch=cin.get();
    }
    a[i]='\0';
    return ;
}

int main()
{
    char a[10],delim;
    int n;
    cin>>n;
    fflush(stdin);
    cin>>delim;
    //Read(a,n,delim);
    cin.getline(a,n+1,delim);
    cout<<a;
    return 0;
}