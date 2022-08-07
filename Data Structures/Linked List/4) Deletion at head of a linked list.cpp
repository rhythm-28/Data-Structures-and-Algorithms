// Deletion at head of a linked list
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

void delete_from_head(node* &head)
{
    node* temp=head->next;
    delete head;
    head = temp;
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

    delete_from_head(head);

    print(head);

    return 0;
}