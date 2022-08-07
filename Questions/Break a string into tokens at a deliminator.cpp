// Break a string into tokens at a deliminator
// Use of strtok()

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[100];
    char* delim;

    cin.getline(a,100);
    fflush(stdin);

    cin>>delim;

    char* ptr = strtok(a,delim);
    cout<<ptr<<endl;

    while(ptr!=NULL)
    {
        ptr=strtok(NULL,delim);
        cout<<ptr<<endl;
    }
    return 0;
}
