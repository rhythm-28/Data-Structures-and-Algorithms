// Print max of every k consecutive elements of an array

#include<iostream>

// to pop elements from both sides
#include<deque>

using namespace std;
int main()
{
    int n,i,a[100000],k;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>k;
    deque<int> d;
    
    // for first k elements
    for(i=0;i<k;i++)
    {
        while(!d.empty() && a[i]>a[d.back()])
        {
            d.pop_back();
        }
        d.push_back(i);
    }
    cout<<a[d.front()]<<" ";

    // for rest of the elements
    for(i=k;i<n;i++)
    {
        // remove the previous element as it is not part of the window
        if(!d.empty() && d.front()==i-k)
        d.pop_front();

        // remove elements which are not useful and are in the window
        while(!d.empty() && a[i]>a[d.back()])
        {
            d.pop_back();
        }

        // add the new element which is now part of the window
        d.push_back(i);

        cout<<a[d.front()]<<" ";
    }

    return 0;
}