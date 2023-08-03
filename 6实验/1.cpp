#include<iostream>
#include<algorithm>				//输入时不要空格，有空格即结束。 
#include<string>
#include<vector>
bool cmp(char a,char b)///比较函数
{
    return a>b;
}
using namespace std;
int main() {
	string str;
    while(cin>>str){
        int len = str.length();
        sort(str.begin(), str.end(),cmp);
        cout<<str<<endl;
    }
    return 0;

}
