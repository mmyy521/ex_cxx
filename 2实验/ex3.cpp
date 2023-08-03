#include<iostream>
#include<string.h>
using namespace std;

class Book
{

private:

char *name; //**����**

char *author; //**����**

int sale; //**������**

public:

Book(); //**�޲ι��캯��**

Book(char *_name, char *_author, int _sale); //**�вι��캯��**

Book(const Book & b); //**�������캯��**

void print(); //**��ʾ����**

~Book(); //**��������**

};

Book::Book(){

	this->name="No name";
	this->author="No author";
	sale = 0;
}
Book::Book(char *_name, char *_author, int _sale){
	this->name=_name;
		this->author=_author;
     
	this->sale = _sale;
}

Book::Book(const Book & b){
	this->name=b.name;
	this->author=b.author;

	this->sale = b.sale;
}

Book::~Book(){

}

void Book::print(){
	cout<<"Name: "<<name<<"\t";
	cout<<"Author: "<<author<<"\t";
	cout<<"Sale: "<<sale<<"\n";
}

int main(){
	char n[100],a[100];
	int sale1;
	cin.getline(n,101);
	cin.getline(a,101);
	cin>>sale1;
	if(strcmp(n,"-1")==0&&strcmp(a,"-1")==0&&sale1==-1){
		Book bk1;
		bk1.print();
	}
	if(strcmp(n,"0")==0&&strcmp(a,"0")==0&&sale1==0){
		Book bk1;
		Book bk2(bk1);
		bk2.print();
	}
	else	
	{
		Book bk(n,a,sale1);
		bk.print();
	}
	return 0;
}
