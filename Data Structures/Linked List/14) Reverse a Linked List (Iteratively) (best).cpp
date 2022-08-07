// Reverse a Linked List (Iteratively)
// O(n) Time
// O(1) Space

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

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

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

node* input()
{
    int d;
    node* head=NULL;
    cin>>d;
    while(d!=-1)
    {
        insert_at_tail(head,d);
        cin>>d;
    }
    return head;
}

// we swap addresses instead of swapping values as whatever the size of values, size of address is always same and small
void reverse(node* &head)
{
    node* prev=NULL;
    node* temp=head;
    node* n=head;
    while(temp!=NULL)
    {
        // save the next node
        n=temp->next;

        //make current node point to previous
        temp->next=prev;

        // take 1 step forward
        prev=temp;
        temp=n;
    }
    head=prev;
}

int main()
{
    int d;
    node* head=input();
    print(head);
    reverse(head);
    print(head);
    return 0;
}