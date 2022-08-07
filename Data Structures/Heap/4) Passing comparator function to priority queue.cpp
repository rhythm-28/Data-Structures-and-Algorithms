// Passing comparator function to priority queue

#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Person
{
    public:
    
    int age;
    string name;
    
    Person()
    {

    }

    Person(int x,string s)
    {
        age=x;
        name=s;
    }
};

class Compare
{
    public:
    bool operator()(Person a,Person b)
    {
        return a.age<b.age;
    }
};

int main()
{
    priority_queue<Person,vector<Person>,Compare> a;
    int i,k,n,age;
    string name;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>name;
        cin>>age;
        Person p(age,name);
        a.push(p);
    }
    cin>>k;
    for(i=0;i<k;i++)
    {
        Person q;
        q=a.top();
        cout<<q.age<<" "<<q.name<<endl;
        a.pop();
    }
    return 0;
}