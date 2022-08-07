// Create Multiple Linked Lists (cascading)

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

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
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

istream& operator>>(istream &cin,node* &head)
{
    input(head);

    //cascading
    return cin;
}


ostream& operator<<(ostream &cout,node* head)
{
    print(head);

    //cascading
    return cout;
}

int main()
{
    int d;
    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    cin>>head1>>head2>>head3;
    cout<<head1<<head2<<head3;
    return 0;
}