#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace  std;
int main(){
	queue<int> q1;
	int n,i;
	cin>>n;
	for(i=1;i<n+1;i++){
		q1.push(i);
	}
	while(!q1.empty()){
		cout<<q1.front();
			q1.pop();
			q1.push(q1.front());
			q1.pop();
	}
	return 0;
}
