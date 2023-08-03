#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void PrintF(string& StringPrint) {
    cout << StringPrint << endl;
}
int main() {
    vector<string> studentName;
    int n;
    cin>>n;
    string str[n+1];
    for(int i;i<n+1;i++)
    {
    	getline(cin,str[i]);
	}
	for(int j=0;j<n+1;j++)
	{
		studentName.push_back(str[j]);
	}
    
    
    //Êä³öÎ´ÅÅÐòµÄÃû×Ö
    /*for_each(studentName.begin(), studentName.end(), PrintF);
    sort(studentName.begin(), studentName.end());  //ÅÅÐòº¯Êý
    cout << "ÅÅÐòºóµÄÃû×Ö£º" << endl;*/
    for_each(studentName.begin(), studentName.end(), PrintF);
    return 0;
}

