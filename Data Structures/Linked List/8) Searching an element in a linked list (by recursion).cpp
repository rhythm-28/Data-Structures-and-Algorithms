// Searching an element in a linked list (by recursion)
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void insert_at_head(node* &head,int d)
{
    if(head==NULL)
    head = new node(d);
    else
    {
        node* n= new node(d);
        (*n).next=head;
        head=n;
    }
}

void print(node* head)
{   
    while(head!=NULL)
    {
        cout<<(*head).data;
        head=(*head).next;
    }
}

bool search(node* head,int key)
{
    if(head==NULL)
    return false;
    else if(head->data==key)
    return true;
    else
    return search(head->next,key);
}

int main()
{
    node* head=NULL;
    insert_at_head(head,5);
    insert_at_head(head,3);
    insert_at_head(head,2);
    insert_at_head(head,1);
    insert_at_head(head,9);

    int key;
    cin>>key;
    cout<<search(head,key);

    return 0;
}