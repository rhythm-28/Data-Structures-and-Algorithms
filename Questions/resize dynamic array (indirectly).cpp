// Resize dynamic array (indirectly) 

#include<iostream>
using namespace std;
int main()
{
    int i;
    int *p;
    p=new int[5];
    p[0]=0;
    p[1]=1;
    p[2]=2;
    p[3]=3;
    p[4]=4;

    /* create a new dynamic array,
    copy the previous values,
    point the previous pointer on this array
    and delete the previous array. */
     
    int *q;
    q=new int[10];
    for(int i=0;i<5;i++)
    q[i]=p[i];

    delete []p;
    p=q;
    q=0;

    for(i=0;i<10;i++)
    cout<<p[i]<<endl;


    delete []q;

    return 0;
}