// Insertion at a given place in a linked list
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

void insert_after_places(node* &head,int d,int places)
{
    node* temp=head;
    int jumps=0;
    while(jumps<places-1)
    {
        temp=temp->next;
        jumps++;
    }
    node* n= new node(d);
    n->next=temp->next;
    temp->next=n;
}

void print(node* head)
{   
    while(head!=NULL)
    {
        cout<<(*head).data;
        head=(*head).next;
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

    insert_after_places(head,4,3);

    print(head);

    return 0;
}