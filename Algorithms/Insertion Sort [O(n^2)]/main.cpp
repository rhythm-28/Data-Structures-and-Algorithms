//Insertion Sort
// O(n^2)

#include<iostream>
#include<vector>
using namespace std;
void InsertionSort(vector<int> a,int n)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int i,n,y;
    vector<int> a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y;
        a.push_back(y);
    }
    InsertionSort(a,n);
    for(i=0;i<n;i++)
    cout<<a[i];
    return 0;
}