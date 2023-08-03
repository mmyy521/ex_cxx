#include<iostream>
#include<string>
using namespace std;

class Rectangle
{
private:

  double length; //长

  double width; //宽
public:

  Rectangle(double Length=10.,double Width=5.);

  double Area(); //获取面积

  double Perimeter();//获取周长
};

Rectangle::Rectangle(double Length,double Width){
	
	this->length=Length;
	this->width=Width;
}

double Rectangle:: Area(){
	double s;
	s = length*width;
	return s;
}

double Rectangle::Perimeter(){
	double l;
	l=2*(length+width);
	return l;
}

int main(){
	
	double ss;
	double x,y;
	cin>>x;
	cin>>y;
	Rectangle rec1(x,y);
	Rectangle rec2(x+3,y+3);
	ss = (rec2.Area() - rec1.Area())*240;
	double ll;
	ll = rec2.Perimeter()*50;
	cout<<ll<<endl;
	cout<<ss<<endl;
	return 0;
}
