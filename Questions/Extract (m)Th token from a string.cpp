//Extract (m)Th token from a string
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string extractToken(string s,int key)
{
    char* a=strtok((char*)s.c_str()," ");
    while(key>1)
    {
        a=strtok(NULL," ");
        key--;
    }
    return (string)a; 
}

int main()
{
    int key;
    string s;
    getline(cin,s);
    cin>>key;
    cout<<extractToken(s,key);
    return 0;
}