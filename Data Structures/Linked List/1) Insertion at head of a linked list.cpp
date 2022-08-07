// Insertion at head of a linked list
#include<iostream>
using namespace std;

// create a user defined data type to store data of current node and address of next node
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

// head is passed by reference as we want to update head (head should keep pointing towards first element)
// if we had passsed head by value, a local variable called head would have been created which would have lost its value by the end of the function
void insert_at_head(node* &head,int d)
{
    // create a memory space of data-type node and initialize data with given value and next with null for first element
    // head should now point to this memory space
    if(head==NULL)
    head = new node(d);

    // create a memory space of data type node and initialize data with given value and next with null
    // this memory space's next should now point to the next element (whose address is currently stored in head)
    // head should now point to this newly created space 
    else
    {
        node* n= new node(d);
        (*n).next=head;
        head=n;
    }
}

// head is passed by value as we don't won't head to update head 
void print(node* head)
{   
    while(head!=NULL)
    {
        cout<<(*head).data;
        head=(*head).next;
    }
}

int main()
{
    node* head=NULL;
    insert_at_head(head,5);
    insert_at_head(head,3);
    insert_at_head(head,2);
    insert_at_head(head,1);
    insert_at_head(head,9);
    
    print(head);

    return 0;
}