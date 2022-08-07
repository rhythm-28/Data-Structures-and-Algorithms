// To check whether an array is sorted or not (using recursion)

#include<iostream>
#include<vector>
using namespace std;

bool is_sorted(int i,vector<int> a)
{
    // if array is sorted and pointer reached the end of array
    if(i==a.size()-1)
    return 1;

    // if array is not sorted
    else if(a[i]>a[i+1])
    return 0;

    // if array is sorted and pointer has not reached the end
    else
    return is_sorted(i+1,a);
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
    if(is_sorted(0,a))
    cout<<"sorted";
    else
    cout<<"not sorted";
    return 0;
}