#include<iostream>
#include<string.h>
using namespace std;

class Student{
	private:
		char * name;
	public:
		Student(char *name );
		~Student();
		Student(const Student & s);
	void print(){
		cout<<name<<endl;
	}
};

Student::Student(char *name){
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);
}

Student::~Student(){
	delete [] name;
}

Student::Student(const Student& s){
	this->name = new char[strlen(s.name)+1];
	strcpy(this->name,s.name);
}

int main()
{
	Student s1("lili");
	s1.print();
	Student s2(s1);
	s2.print();
	return 0; 
}
