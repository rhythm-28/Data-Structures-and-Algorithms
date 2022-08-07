//Replace pi with 3.14 in a string (using recursion)

#include<iostream>
using namespace std;

void replace_pi(char a[],int i,int n)
{
    if(i!=n-1)
    {
        if(a[i]=='p' && a[i+1]=='i')
        {
            n=n+2;
            //Shifting elements two places forward
            int j;
            for(j=n-1;j>=i+2;j--)
            a[j]=a[j-2];

            //Replacing
            a[i]='3';
            a[i+1]='.';
            a[i+2]='1';
            a[i+3]='4';

            //next 3 elements can't be "pi" as they are "3.14"
            i=i+3;
            
            // size of array is increased by 2
            n=n+2;
        }

        //Check for further elements
        replace_pi(a,i+1,n);
    }
}

int main()
{
    char a[100];
    int n,i;
    cin>>n;
    fflush(stdin);
    cin.getline(a,n);
    replace_pi(a,0,n);
    for(i=0;a[i]!='\0';i++)
    cout<<a[i];
    return 0;
}