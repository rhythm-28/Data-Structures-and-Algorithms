// Insertion at head in a doubly linked list

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};

void insert_at_head(node* &head, int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    
    node* n=new node(d);
    n->next=head;
    head->prev=n;
    head=head->prev;
}

void print(node* head)
{   
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
}

int main()
{
    node* head=NULL;
    insert_at_head(head,5);
    insert_at_head(head,3);
    insert_at_head(head,2);
    insert_at_head(head,1);
    insert_at_head(head,9);
    
    print(head);
    cout<<endl;

    return 0;
}