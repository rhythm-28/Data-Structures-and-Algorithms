// Phone Keypad Problem

#include<iostream>
using namespace std;

char characters[][5]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void phone_keypad(char keys[],int i,char output[],int j)
{
    // base case
    if(keys[i]=='\0')
    {
        output[j]=keys[i];
        cout<<output<<endl;
    }

    // recursive case
    else
    {
        int k,m=keys[i]-'0';
        for(k=0;characters[m][k]!='\0';k++)
        {
            output[j]=characters[m][k];
            phone_keypad(keys,i+1,output,j+1);
        }
    }
}

int main()
{
    char keys[]="23",output[100];
    //int n;
    //cin>>n;
    //fflush(stdin);
    //cin.getline(keys,n);
    //cout<<keys;
    phone_keypad(keys,0,output,0);
    return 0;
}