// Detect if a cycle is present in given linked list or not

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

void insert_at_tail(node* &head,int d)
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
    tail->next=new node(d);
}

void input(node* &head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        insert_at_tail(head,d);
        cin>>d;
    }
}

bool cycle_detection(node* head)
{
    if(head==NULL)
            return false;    
    node* fast=head->next;
    node* slow=head;
    while(slow!=fast)
    {
        if(fast==NULL || fast->next==NULL)
        return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node* head=NULL;
    input(head);
    print(head);
    cycle_detection(head);
    print(head);
    return 0;
}