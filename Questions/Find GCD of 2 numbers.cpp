//Find GCD of 2 numbers
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
	int n1,n2;
	cin>>n1>>n2;
	cout<<find_gcd(n1,n2);
	return 0;
}