// Deletion at a given place in a linked list
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

void delete_from_middle(node* &head,int place)
{
    if(place==1)
    {
        node* temp=head->next;
        delete head;
        head=temp;
        return;
    }
    node* temp=head;
    int jumps=0;
    while(jumps<place-2)
    {
        temp=temp->next;
        jumps++;
    }
    node* n=temp->next;
    temp->next=n->next;
    delete n;
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

    delete_from_middle(head,5);

    print(head);

    return 0;
}