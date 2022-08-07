// place even elememts after odd elements

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

node* input(int n)
{
    int d,i=0;
    node* head=NULL;
    while(i!=n)
    {
        cin>>d;
        insert_at_tail(head,d);
        i++;
    }
    return head;
}

void even_after_odd(node* &head)
{
    bool flagEven = false;
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data % 2 ==0)
        {
            flagEven = true;
            break;
        }
        temp = temp->next;
    }

    // if no even element exits, don't do anything
    if(flagEven == false)
    return;

    bool flagOdd = false;
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data % 2 != 0)
        {
            flagOdd = true;
            break;
        }
        temp = temp->next;
    }
    
    // if no odd element exits, don't do anything
    if(flagOdd == false)
    return;

    node* even = NULL;
    node* odd = NULL;

    node* prevo;
    node* preve;

    temp = head;
    while(temp!=NULL)
    {
        if(temp->data%2==0)
        {
            if(even == NULL)
            {
                even = temp;
                preve = temp;
            }
            else
            {
                preve->next = temp;
                preve = preve->next;
            }
        }
        else
        {
            if(odd == NULL)
            {
                odd = temp;
                prevo = temp;
            }
            else
            {
                prevo->next = temp;
                prevo = prevo->next;
            }
        }
        temp=temp->next;
    }
    head = even;
    preve->next = odd;
    prevo->next = NULL;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int d,n;
    cin>>n;
    node* head=input(n);
    even_after_odd(head);
    print(head);
    return 0;
}