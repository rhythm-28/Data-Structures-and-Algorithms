// To print subsets of a character array (by recursion)

#include<iostream>
using namespace std;

void find_subsets(char input[],char output[],int i,int j)
{
    // base case
    // reached end of array
    if(input[i]=='\0')
    {
        output[j]=input[i];
        cout<<output<<endl;
    }

    //recursive case
    else
    {
        // include element at (i)th index
        output[j]=input[i];
        find_subsets(input,output,i+1,j+1);

        // exclude element at (i)th index
        find_subsets(input,output,i+1,j);
    }
}

int main()
{
    int n,i;
    char input[10],output[10];
    cin>>n;
    fflush(stdin);
    cin.getline(input,n);
    find_subsets(input,output,0,0);
    return 0;
}