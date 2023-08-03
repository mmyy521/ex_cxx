#include<iostream>
#include<string>
using namespace std;

class Date    //日期类
{
private:
    int Date_year;    //年
    int Date_month;    //月
    int Date_day;    //日
public:
    Date(int year=2000, int month=1, int day=1);
    void show();    //以“年-月-日”格式输出年月日
    ~Date();
};
Date::~Date(){
}
Date::Date(int year,int month,int day){
	this->Date_year=year;
	this->Date_month=month;
	this->Date_day=day;
}

void Date::show(){
	cout<<"Birthday:"<<Date_year<<"-"<<Date_month<<"-"<<Date_day;
}

class Croster    //名单类
{
private:
    string name;
    Date birthday;
public:
    Croster();
    Croster(string name,int year,int month,int day);
    Croster(string name, Date date);
    void show();//显示姓名和出生日期
   ~Croster();
};

Croster::Croster(){
	name = "NULL";
	
	birthday =Date (0,0,0);
}

Croster::Croster(string name,int year,int month,int day){
	this->name = name;
	Date tmp(year,month,day); 
	birthday = tmp;
}

Croster::Croster(string name, Date date){
	this->name=name;
	birthday = date;
}

Croster::~Croster(){
	
}
void Croster::show(){
	cout<<"Name:"<<name<<",";
	birthday.show();
}

int main(){
	string na;
	int a,b,c;
	int x;
	while(cin>>x){
		if(x==0){
		Croster n;
		n.show();
		break;	
		} 
		if(x==1){
			
			cin>>na>>a>>b>>c;
			Croster n(na,a,b,c);
			n.show();
		}
		if(x==2){
			cin>>na>>a>>b>>c;
			Date m(a,b,c);
			Croster n(na,m);
			n.show();
		}
		if(x==-1){
			return 0;
		}
	}
}
