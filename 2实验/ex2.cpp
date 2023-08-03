#include<iostream>
#include<string>
using namespace std;

class Rectangle
{
private:

  double length; //��

  double width; //��
public:

  Rectangle(double Length=10.,double Width=5.);

  double Area(); //��ȡ���

  double Perimeter();//��ȡ�ܳ�
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
