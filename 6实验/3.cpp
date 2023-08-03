#include<iostream>
#include<string>
#include<algorithm>
#include <list>
using namespace std;
struct Student {
    int no;
    string name;
};
void Input(list<Student> & l){
	int n;
     cin>>n;
     while (n--)
     {
	Student stu;
	cin>>stu.no>>stu.name;
	l.push_back(stu);
 	}
} 
void Show(list<Student> &l){
	list<Student>::iterator it;
    for(it=l.begin();it!=l.end();it++)
     {  cout<<(*it).no<<" "<<(*it).name<<endl;
     }
}

int main()
{
    std::list<Student> li;

    Input(li); //ÊäÈë
    Show(li); //Êä³ö

    return 0;
}
