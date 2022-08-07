//Find LCM of 2 numbers
#include<iostream>
using namespace std;

int find_gcd(int n1,int n2)
{
	if(n2==0)
	return n1;
	else
	return find_gcd(n2,n1%n2);
}

int main()
{
	int n1,n2,g,l;
	cin>>n1>>n2;
	g=find_gcd(n1,n2);
	
    //LCM*GCD=N1*N2
    l=(n1*n2)/g;
	cout<<l;
	return 0;
}