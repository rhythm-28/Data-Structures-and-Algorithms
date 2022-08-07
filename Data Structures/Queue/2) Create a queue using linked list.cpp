// Create a queue using linked list

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

void insert_at_tail(node *&head,node* &tail,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        tail=head;
        return;
    }
    tail->next=new node(d);
    tail=tail->next;
}

void delete_from_head(node* &head)
{
    node* temp=head->next;
    delete head;
    head = temp;
}

class Queue
{
    node *head;
    node *tail;

    public:

    Queue()
    {
        head=NULL;
    }

    bool empty()
    {
        return head==NULL;
    }

    void push(int data)
    {
        insert_at_tail(head,tail,data);
    }
    void pop()
    {
        if(!empty())
        delete_from_head(head);
    }
    int front()
    {
        if(head!=NULL)
        return head->data;
    }
};

void input(Queue &q)
{
    int i,n,d;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>d;
        q.push(d);
    }
}

void print(Queue q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main()
{
    Queue q;
    input(q);
    print(q);
    return 0;
}