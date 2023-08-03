#include<iostream>
#include<string.h>
using namespace std;

class Vehicle{
	public:
		char name[110],color[110];
		Vehicle(char *,char*);
		virtual void display() = 0;	
};
Vehicle::Vehicle(char *n,char *c){
	strcpy(name,n);
	strcpy(color,c);
}
class Car:public Vehicle{
	private:
		int passager;
	public:
		Car(char *,char *,int);
		 virtual void display();
};

Car::Car(char *n,char *c,int p):Vehicle(n,c){
	passager = p;
}
void Car::display(){
	cout<<"Car name:"<<name<<" "<<"Car color:"<<color<<" "<<"Car passager:"<<passager<<endl;
}

class Truck:public Vehicle{
	private:
		double Truckcapacity;
	public:
		Truck(char *,char *,double);
		virtual void display();
};

Truck::Truck(char *n,char *c,double t):Vehicle(n,c){
	Truckcapacity = t;
}
void Truck::display(){
	cout<<"Truck name:"<<name<<" "<<"Truck color:"<<color<<" "<<"Truck capacity:"<<Truckcapacity<<endl;
}
int main()

{

Vehicle *p;

char type;

char name[110],color[110];

int pas;

double cap;

while(cin>>type)

{

cin>>name>>color;

if(type == 'C')

{

cin>>pas;

Car car(name,color,pas);

p = &car;

p->display();

}

else if(type == 'T')

{

cin>>cap;

Truck truck(name,color,cap);

p = &truck;

p->display();

}

}

return 0;

}

