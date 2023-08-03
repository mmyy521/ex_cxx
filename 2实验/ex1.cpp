#include<iostream>
#include<cmath>
#include<iomanip>
const double PI=acos(-1.0);
using namespace std;

 class Circle{
 	private:
 	double r;
 	double s;
 	public:
 		void get();
 		void cal();
 		void print();
 };
void Circle::get(){
	cin>>r;
	this->r=r;
}

void Circle::cal(){
	s=PI*r*r;
}
void Circle::print(){
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<s;
}

int main(){
	Circle a;
	a.get();
	a.cal();
	a.print();
} 
