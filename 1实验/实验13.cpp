#include<iostream>
using namespace std;
int main()
{
	int a,b,i,j; 
	cin>>a>>b;
	int k[100][100];
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			cin>>k[j][i];
		}
	}
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(k[j][i]!=0)
			{
				cout<<i<<" "<<j<<" "<<k[j][i]<<endl;
			}
			
		}
	}
	return 0;
}
