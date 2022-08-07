// Deletion at tail of a linked list
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

void delete_from_tail(node* &head)
{
    node* tail=head;
    node* prev=head; 
    while(tail->next!=NULL)
    {
        prev=tail;
        tail=tail->next;
    }
    delete tail;
    prev->next=NULL;
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

    delete_from_tail(head);

    print(head);

    return 0;
}