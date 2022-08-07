// Methods to declare a 2-D array

#include<iostream>
using namespace std;
int main()
{
    /* Method-1
    completely in stack */
    int a[3][4];
    //input values from user

    /*Method-2
    completely in stack */
    int b[3][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11}};


    /* Method-3
    partially in stack & heap */ 
    int* c[3];
    for(int i=0;i<3;i++)
    c[i]=new int[4];

    /* Method-4
    completely in heap*/
    int **d;
    d=new int*[3];
    for(int j=0;j<3;j++)
    d[j]=new int[4];

    return 0;
}