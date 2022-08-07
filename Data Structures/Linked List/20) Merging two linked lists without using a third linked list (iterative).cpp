// Merging two linked lists without using a third linked list (iterative)

#include<iostream>
using namespace std;

class node
{
    public:
    long long int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void insert_at_tail(node* &head,long long int d)
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
    long long int d,n;
	cin>>n;
    for(long long int i=0;i<n;i++)
    {
        cin>>d;
        insert_at_tail(head,d);
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

node* Merge(node* head1, node* head2)
{   
    node* head3=NULL;
    if(head1==NULL)
    {
        head3=head2;
        return head3;
    }
    if( head2==NULL)
    {
        head3=head1;
        return head3;
    }
    if(head1->data<head2->data)
    {
        head3=head1;
        head1=head1->next;
    }
    else
    {
        head3=head2;
        head2=head2->next;
    }
    node* temp=head3;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
        }
        else
        {
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
    }
    if(head1!=NULL)
    temp->next=head1;
    if(head2!=NULL)
    temp->next=head2;
    return head3;
}

int main()
{
	
	
		node* head1=NULL;
    	node* head2=NULL;
    	node* head3=NULL;
    	cin>>head1>>head2;
    	head3=Merge(head1,head2);
    	cout<<head3;
	
    return 0;
}
