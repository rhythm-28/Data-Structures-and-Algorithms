// Print string wrt numbers (recursion) 
/*
1234 => ABCD, LCD , AWD
*/

#include<iostream>
using namespace std;

char characters[]={'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

void print_string(char inp[],char out[],int i,int j)
{
    // base case
    if(inp[i]=='\0')
    {
        out[j]=inp[i];
        cout<<out<<endl;
    }

    // recursive case
    else
    {
       // include as single
        int digit;
        digit=inp[i]-'0';
        out[j]=characters[digit];
        print_string(inp,out,i+1,j+1);
       
        // include as pair
        if(inp[i+1]!='\0')
        {
            int f_digit=inp[i]-'0';
            int s_digit=inp[i+1]-'0';
            int final_no=(f_digit*10)+s_digit;
            if(final_no<=26)
            {
                out[j]=characters[final_no];
                print_string(inp,out,i+2,j+1);
            }
        }
    }
}

int main()
{
    char inp[100],out[100];
    cin>>inp;
    print_string(inp,out,0,0);
    return 0;
}