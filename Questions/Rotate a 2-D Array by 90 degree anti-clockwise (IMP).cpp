#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n,m,s,k,i,j,temp;
    int a[100][100];
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cin>>a[i][j];
	}
	for(i=0;i<n;i++)
    reverse(a[i],a[i]+n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
            {
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
	return 0;
}