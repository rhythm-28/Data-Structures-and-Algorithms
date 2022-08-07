// To find first non-repeating character in a running stream of characters

#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<char> q;
    int a[26]={0};
    char ch;
    cin>>ch;
    while(ch!='.')
    {
        // put in queue
        q.push(ch);

        // update in hashmap
        a[ch-97]++;

        // check front until you find 1
        while(!q.empty() && a[q.front()-97]!=1)
        {
            q.pop();
        }
        if(q.empty())
        cout<<"-1 ";
        else
        cout<<q.front()<<" ";

        cin>>ch;
    }
    return 0;
}