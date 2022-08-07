// Backtracking -- Permutations of a string

#include<iostream>
using namespace std;

void swap(char* ch1, char* ch2)
{
    char temp;
    temp=*ch1;
    *ch1=*ch2;
    *ch2=temp;
}

void permutations(char a[],int i)
{
    if(a[i]=='\0')
    {
        cout<<a<<endl;
        return;
    }
    
    int j=i;
    while(a[j]!='\0')
    {
        swap(a[i],a[j]);
        permutations(a,i+1);

        // Backtracking
        swap(a[i],a[j]);

        j++;
    }
}

int main()
{
    char a[100];
    cin>>a;
    cout<<endl;
    permutations(a,0);
    return 0;
}