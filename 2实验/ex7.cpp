#include<iostream>
#include<string.h>
using namespace std;

class Date
{
public:
Date(int d = 0, int m = 0, int y = 0); //构造函数

int get_day() const; // 返回day

int get_month() const; //返回month

int get_year() const; // 返回year

static void set_default(int ,int,int); //设置default_date

static int get_default_day(); //返回缺省day

static int get_default_month(); //返回缺省month

static int get_default_year(); //返回缺省year

Date & add_year(int n); //加n年

Date & add_month(int n); //加n月，考虑超过12月

Date & add_day(int n); //加n天，考虑进位月和年，考虑闰年

private:

int day, month, year;
 
static Date default_date; //初始化为 1901年1月1日
};

void Date::set_default(int x, int y, int z){
	default_date.day = x;
	default_date.month = y;
	default_date.year =z;
}
Date Date::default_date(1,1,1901);

Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y; 
}                                 

int Date::get_day() const{
	return day;
}

int Date::get_month() const{
	return month;
}

int Date::get_year() const{
	return year;
}



int Date::get_default_day(){
	return default_date.day;
}

int Date::get_default_month(){
	return default_date.month;
}

int Date::get_default_year(){
	return default_date.year;
}

Date & Date::add_year(int n){
	year+=n;
	return *this;
}

Date & Date::add_month(int n){
/*	if(n+month>12)
	{
		year += ( n + month)/12;
		if((n+month) % 12==0){
			month = 1;
		} 
		else
		month = (n+month) % 12;
	}
	else{
		month+=n;
	}*/
	int t=n;
	for(int i=0;i<t;i++){
		month++;
		
		if(month>12){
			month=1;
			year++;
		}
	} 
	return *this;
}

Date & Date::add_day(int n){
	for(int i=1 ;i<=n ;i++)
	{
		day+=1;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
			if( day == 32)
			{
				if(month==12)
				{
					year++;
					month=1;
					day=1;
				}
				else
				{
					month+=1;
					day=1;
				}
				
			}
		}
		if(month==2)
		{
			if((year % 4==0 && year % 100!=0)||year % 400==0 )//是闰年的话， 
			{
				if(day > 29)
				{
						month+=1;
						day=1;
				}
			} 
			else if(day > 28)
			{		
				month+=1;
				day=1;
					
			} 
		}
		if(month==4||month==6||month==9||month==11)
			{
				if(day > 30)
				{
						month+=1;
						day=1;
					
				}
			}
		
	}
	return *this;
}

int main()
{
char type[110];

int day,mon,year;

int addday,addmon,addyear;

while(cin>>type)

{

if(strcmp(type,"Date") == 0)//正常输入 

{

cin>>day>>mon>>year;

Date mydate(day,mon,year);//实现年月日的相加 

cin>>addday>>addmon>>addyear;

mydate.add_day(addday).add_month(addmon).add_year(addyear);

cout << mydate.get_day() << " " << mydate.get_month() << " " << mydate.get_year() << endl;

}

else if(strcmp(type,"defaultDate") == 0)//输出既定日期 

{

cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;

}

else if(strcmp(type,"setdefaultDate") == 0)

{

	cin>>day>>mon>>year;
	
	Date::set_default(day,mon,year);
	
	cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;

}

}

return 0;

}
 
