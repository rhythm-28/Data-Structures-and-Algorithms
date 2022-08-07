// Sort a linked list using Merge Sort
// O[n*log(n)]

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

node* mid_finder(node* head)
{
    node* fast=head->next;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* MergeSort(node*head)
{
    // base case
    if(head->next==NULL)
    return head;

    // recursive case
    node* mid=mid_finder(head);
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;

    a=MergeSort(a);
    b=MergeSort(b);
    node*c=Merge(a,b);

    return c;
}

int main()
{
    node* head=NULL;
    cin>>head;
    cout<<head;
    head=MergeSort(head);
    cout<<head;
    return 0;
}