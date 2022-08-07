// Searching in a Hashtable

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

template<typename T>
class node
{
    public:

    T data;
    string key;
    node<T>* next;

    node(string s,T d)
    {
        data=d;
        key=s;
        next=NULL;
    }
    ~node()
    {
        if(next!=NULL)
        delete next;
    }
};

template<typename T>
class hashtable
{
    node<T>** table;
    int csize;
    int tsize;

    int hash(string s)
    {
        int sum=0,p=1;
        for(int i=0;i<s.length();i++)
        {
            sum+=(s[i]*p)%tsize;
            sum=sum%tsize;
            p=(p*27)%tsize;
        }
        return sum;
    }
    
    void rehash()
    {
        node<T>** oldtable=table;
        int oldtablesize=csize;
        int tsize=2*tsize;
        int i;
        table=new node<T>*[tsize];
        for(i=0;i<tsize;i++)
        table[i]=NULL;
        node<T>* temp;
        csize=0;

        for(i=0;i<oldtablesize;i++)
        {
            temp=oldtable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->data);
                temp=temp->next;
                csize++;
            }
            if(oldtable[i]!=NULL)
            delete oldtable[i];
        }
        delete [] oldtable;
    }

    public:

    hashtable(int n)
    {
        csize=0;
        tsize=n;
        table=new node<T>*[tsize];
        for(int i=0;i<tsize;i++)
        table[i]=NULL;
    }

    void insert(string key,T data)
    {
        // hash fn here
        int idx=hash(key);

        // seaparate chaining
        node<T>* n=new node<T>(key,data);
        n->next=table[idx];
        table[idx]=n;
        csize++;

        int load_factor=csize/tsize;
        if(load_factor>0.75)
        rehash();
    }

    T* search(string key)
    {
        int i=hash(key);
        node<T>* temp=table[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            return &temp->data; 

            temp=temp->next;
        }
        return NULL;
    }

    void print()
    {
        for(int i=0;i<tsize;i++)
        {
            node<T>*temp=table[i];
            cout<<i<<") ";
            while(temp!=NULL)
            {
                cout<<temp->key<<"-"<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
        cout<<endl;
    } 
};

void input(hashtable<int> &h,int n)
{
    int d,i;
    string s;
    for(i=0;i<n;i++)
    {
        cin>>s;
        cin>>d;
        h.insert(s,d);
    }    
}

int main()
{
    int n;
    cin>>n;
    hashtable<int> h(15);
    input(h,n);
    h.print();
    string key;
    fflush(stdin);
    getline(cin,key);
    int* ans=h.search(key);
    if(ans==NULL)
    cout<<"not found";
    else
    cout<<*ans;
    return 0;
}
