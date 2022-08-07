// To check if a string is palindrome or not

#include<iostream>
using namespace std;
int main()
{
    int n;
    char a[10];
    cin>>n;
    fflush(stdin);
    cin.getline(a,n+1);
    int i=0,j=n-1,x=0;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else
        {
            x=-1;
            break;
        }
    }
    if(x==-1)
    cout<<"Not a palindrome";
    else
    cout<<"Palindrome";
    return 0;
}