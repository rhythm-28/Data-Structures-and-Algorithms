//Rainwater Harvesting

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> a;
    int n,y,i,j,k,x,m,q,sum=0,max;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y;
        a.push_back(y);
    }
    i=0,j=0;
    // Finding i
    for(i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            x=a[i];
            break;
        }
    }
    while(i<n-2)
    {
        //Finding j
        max=a[i+1];
        for(q=i+1;q<n;q++)
        {
            if(a[q]>=max)
            {
                max=a[q];
                j=q;
            }
        }

        //Traversing and adding
        int max_water=min(max,x);
        for(m=i+1;m<=j-1;m++)
        sum+=(max-a[m]);
        i=j;
        x=a[i];
    }
    printf("%d",sum);
    return 0;
}