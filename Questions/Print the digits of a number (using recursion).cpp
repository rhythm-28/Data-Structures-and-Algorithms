//Print the digits of a number (using recursion)

#include<iostream>
#include<string>
using namespace std;

string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void string_printer(int n)
{
    if(n!=0)
    {
        int b=n%10;
        string_printer(n/10);
        cout<<s[b]<<" ";
    }
}

int maim()
{
    int n;
    cin>>n;
    string_printer(n);
    return  0;
}