// To convert decimal into binary

#include<iostream>
using namespace std;

int convert_to_Binary(int n)
{
    int last_bit,ans=0,p=1;
    while(n>0)
    {
        last_bit=n&1;
        ans+=(p*last_bit);
        p=p*10;
        n=(n>>1);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<convert_to_Binary(n);
    return 0;
}