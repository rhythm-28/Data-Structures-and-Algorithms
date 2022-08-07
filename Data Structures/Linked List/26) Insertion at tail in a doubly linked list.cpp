// Insertion at tail in a doubly linked list

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

void insert_at_tail(node* &head, int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    node* n=new node(d);
    tail->next=n;
    n->prev=tail;
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
    insert_at_tail(head,5);
    insert_at_tail(head,3);
    insert_at_tail(head,2);
    insert_at_tail(head,1);
    insert_at_tail(head,9);
    
    print(head);
    cout<<endl;

    return 0;
}