// Reverse a Linked List (Recursively)
// O(n) Time
// O(n) Space 

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

node* reverse(node* &head)
{
    // base case
    // when only 1 element is left
    if(head->next==NULL)
    return head;

    // head of small linked list
    node* small_head=reverse(head->next);

    // tail of small linked list
    node* small_tail=head->next;

    //joining current element to tail of small linked list
    small_tail->next=head;
    head->next=NULL;
    return small_head;
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
    head=reverse(head);
    print(head);
    return 0;
}