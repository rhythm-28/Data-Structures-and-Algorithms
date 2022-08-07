// Merging two linked lists without using a third linked list (recursive)

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

node* Merge(node* head1,node* head2)
{
    // base case
    if(head1==NULL)
    return head2;
    else if(head2==NULL)
    return head1;

    // recursive case
    else
    {
        node* head3;
        if(head1->data < head2-> data)
        {
            head3=head1;
            head3->next=Merge(head1->next,head2);
        }
        else
        {
            head3=head2;
            head3->next=Merge(head1,head2->next);
        }
        return head3;
    }
    
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    cin>>head1>>head2;
    cout<<head1<<head2;
    head3=Merge(head1,head2);
    cout<<head3;
    return 0;
}