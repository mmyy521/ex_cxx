#include<iostream>
#include<algorithm>				//����ʱ��Ҫ�ո��пո񼴽����� 
#include<string>
#include<vector>
bool cmp(char a,char b)///�ȽϺ���
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
