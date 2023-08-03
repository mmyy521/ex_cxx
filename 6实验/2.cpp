	#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
bool cmp(string a,string b){
	return a>b;
}
int main(){
	vector<string> a;
	int n;
	cin>>n;
	string str[n];
	string tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		char arr[100];
		strcpy(arr,tmp.c_str());//将C++的string转化为C的字符串数组
		sort(arr,arr+tmp.size());
		tmp=arr;
		a.push_back(tmp);
	}
	sort(a.begin(),a.end(),cmp);
		vector<string>::iterator it=a.begin();
for(;it!=a.end();it++)
{
	cout<<*it<<endl;
}
    return 0;
} 

