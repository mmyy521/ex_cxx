#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h> 
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<int> v(a,a+n);
		sort(v.begin(),v.end());
		for(int j=0;j<m;j++)
		{
			int f;
			cin>>f;
			vector<int>::iterator low; 
			low = lower_bound(v.begin(),v.end(),f);
			if(*low==f)
				cout<<f<<" found at "<<(low-v.begin()+1)<<endl;
			else
				cout<<f<<" not found"<<endl;
		}
	}
	return 0;
}
