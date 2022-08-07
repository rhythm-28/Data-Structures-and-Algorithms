// In a given list of strings, find unique prefix of each string

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class node
{
    public:

    char data;
    bool terminal;
    int freq;
    unordered_map<char,node*> next;

    node(char ch)
    {   
        data=ch;
        terminal=false;
        freq=1;
    }
};

class Trie
{
    public:
    node* root;

    Trie()
    {
        root=new node('\0');
    }

    void insert(char a[])
    {
        node* temp=root;
        for(int i=0;a[i]!='\0';i++)
        {
            char ch=a[i];
            // if node is present, go there
            if(temp->next.count(ch))
            {
                temp=temp->next[ch];
                temp->freq++;
            }

            // if node is not present, create the node and then go there
            else
            {
                node* n=new node(ch);
                temp->next[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }

    vector<char> prefix(char a[])
    {
        int i;
        node* temp=root;
        vector<char> v;
        for(i=0;a[i]!='\0';i++)
        {   
            char ch=a[i];
            v.push_back(ch);
            temp=temp->next[ch];

            if(temp->freq==1)
            {
                v.push_back('\0');
                return v;
            }
        }
        vector<char> z;
        z.push_back('-');
        z.push_back('\0');
        return z;
    }
};

int main()
{
    Trie t;
    int i,n;
    cin>>n;
    char a[100][100],b[100];
    for(i=0;i<n;i++)
    cin>>a[i];

    cout<<endl;

    for(i=0;i<n;i++)
    t.insert(a[i]);

    cout<<"prefixes:\n";
    vector<char> v;
    for(i=0;i<n;i++)
    {
        v=t.prefix(a[i]);
        for(int j=0;v[j]!='\0';j++)
        cout<<v[j];
        cout<<endl;
    }

    return 0;
}