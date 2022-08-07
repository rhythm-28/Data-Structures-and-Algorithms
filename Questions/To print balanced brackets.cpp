// To print balanced brackets 

#include<iostream>
using namespace std;

void find_subsets(char n,char output[],int i,int count_open,int count_close)
{
    // base case
    // reached end of array
    if(i==(2*n))
    {
        output[i]='\0';
        cout<<output<<endl;
    }

    //recursive case
    if(count_open<n)
    {
        output[i]='(';
        find_subsets(n,output,i+1,count_open+1,count_close);
    }
    if(count_close<count_open)
    {
        output[i]=')';
        find_subsets(n,output,i+1,count_open,count_close+1);
    }
}

int main()
{
    int n,i;
    char input[10],output[10];
    cin>>n;
    find_subsets(n,output,0,0,0);
    return 0;
}