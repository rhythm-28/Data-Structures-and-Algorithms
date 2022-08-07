// Insert and Search functions in Trie

#include<iostream>
#include<unordered_map>
using namespace std;

class node
{
    public:

    char data;
    bool terminal;
    unordered_map<char,node*> next;

    node(char ch)
    {   
        data=ch;
        terminal=false;
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
            temp=temp->next[ch];

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

    bool find(char a[])
    {
        node* temp=root;
        for(int i=0;a[i]!='\0';i++)
        {
            char ch=a[i];

            // if character is not present, that means given word is not present
            if(temp->next.count(ch)==0)
            return false;
            
            // if character is present, go there to look for remaining characters
            else
            temp=temp->next[ch];
        }

        // check if last character is a terminal node
        // if it is a terminal node, then the given word is present in Trie
        if(temp->terminal)
        return true;

        // if it is not a terminal node, then the given node is not present in Trie.
        // It was just a part of another word
        else
        return false;
    }
};

int main()
{
    Trie t;
    int i,n;
    cin>>n;
    char a[100][100],b[100];
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<endl;

    for(int i=0;i<n;i++)
    t.insert(a[i]);

    cin>>b;
    cout<<t.find(b);

    return 0;
}