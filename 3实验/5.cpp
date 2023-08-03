#include<iostream>
#include<cmath>
using namespace std;

const double pi = acos(-1);

class Shape {

public:

Shape() {}

virtual double area() = 0;

virtual void input() = 0;

virtual double volume() = 0;

virtual ~Shape() {}

};

class Cuboid:public Shape{
	private:
		double l,w,h;
		double s,v;
	public:
		void input();
		double area();
		double volume();
};
void Cuboid::input(){
	cin>>l>>w>>h;
}
double Cuboid::area(){
	return 2*(l*w+l*h+w*h);
}

double Cuboid::volume(){
	return l*w*h;
}

class Cylinder:public Shape{
	private:
		double r,h;
		double s,v;
	public:
		void input();
		double area();
		double volume();
};
void Cylinder::input(){
	cin>>r>>h;
	
}
double Cylinder::area(){
	return pi*r*r+2*pi*r*h;
}
double Cylinder::volume(){
	return pi*r*r*h;
}

class Ball:public Shape{
	private:
		double r;
	public:
		void input();
		double area();
		double volume();
};
void Ball::input(){
	cin>>r;
	
}
double Ball::area(){
	return pi*r*r*4;
}
double Ball::volume(){
	return pi*r*r*r*4/3;
}
void work(Shape *s) {

s->input();

cout << s->area() << " " << s->volume() << endl;

delete s;

}

int main() {

char c;

while (cin >> c) {

switch (c) {

case 'y':

work(new Cylinder());

break;

case 'c':

work(new Cuboid());

break;

case 'q':

work(new Ball());

break;

default:

break;

}

}

return 0;

}
