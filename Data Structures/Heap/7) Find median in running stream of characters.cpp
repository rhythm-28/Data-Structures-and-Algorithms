// Find median in running stream of characters

#include<iostream>
#include<queue>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;

    int no,median;
    cin>>no;
    while(no!=-1)
    {
        if(left.empty() && right.empty())
        {
            left.push(no);
            median=no;
        }
        
        else
        {   
            if(left.size()==right.size())
            {
                if(no>median)
                {
                    right.push(no);
                    median=right.top();
                }
                else
                {
                    left.push(no);
                    median=left.top();
                }  
            }
            else if(left.size() > right.size())
            {
                if(no>median)
                right.push(no);

                else
                {
                    right.push(left.top());
                    left.pop();
                    left.push(no);
                }
                median=(left.top()+right.top())/2;
            }
            else
            {
                if(no<median)
                left.push(no);

                else
                {
                    left.push(right.top());
                    right.pop();
                    right.push(no);
                }
                median=(left.top()+right.top())/2;
            }
        }
        cout<<median<<" ";
        cin>>no;
    }
    return 0;
}