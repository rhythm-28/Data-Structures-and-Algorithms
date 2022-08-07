// Search for an element in a circular linked list

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
    {
        head = new node(d);
        head->next=head;
    }

    else
    {
        node* tail=head->next;
        while(tail->next!=head)
        {
            tail=tail->next;
        }
        node* n= new node(d);
        n->next=head;
        head=n;
        tail->next=head;
    }
}

node* search(node* head, int d)
{
    node* temp=head;
    while(temp->next!=head)
    {
        if(temp->data==d)
        return temp;
        
        temp=temp->next;
    }
    if(temp->data==d)
    return temp;

    return NULL;
}

void print(node* head)
{   
    node* temp=head;
    cout<<temp->data;
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
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
    print(head);
    node* n=search(head,key);
    if(n!=NULL)
    cout<<n->data;
    else
    cout<<"not present";
    return 0;
}