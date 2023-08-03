#include<iostream>
using namespace std;
int main()
{
	int n,time=0;
	cin>>n;
	while(n!=1)
	{
		if(n%2==0)
	{
		n=n/2;
		time+=1;	
	}
	else
	{
		n=3*n+1;
		time+=1;
	}
	}
	if(n%2==0)
	{
		n=n/2;
		time+=1;	
	}
	else
	{
		n=3*n+1;
		time+=1;
	}
	cout<<time-1;
 } 
