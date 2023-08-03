#include<iostream>
#include<string>
using namespace std;

class Complex

{

private:

	double x;

	double y;

public:

	Complex(double x = 0.0, double y = 0.0);

	Complex& operator+=(const Complex&);

	Complex& operator-=(const Complex&);

	Complex& operator*=(const Complex&);

	Complex& operator/=(const Complex&);

	friend Complex operator+(const Complex&, const Complex&);

	friend Complex operator-(const Complex&, const Complex&);

	friend Complex operator*(const Complex&, const Complex&);

	friend Complex operator/(const Complex&, const Complex&);

	friend bool operator==(const Complex&, const Complex&);

	friend bool operator!=(const Complex&, const Complex&);

	friend ostream& operator<<(ostream&, const Complex&);

	friend istream& operator>>(istream&, Complex&);
};
Complex::Complex(double a, double b) {
	this->x = a;
	this->y = b;
}
Complex& Complex::operator+=(const Complex& c) {
	this->x += c.x;
	this->y += c.y;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	this->x -= c.x;
	this->y -= c.y;
	return *this;
}
Complex& Complex::operator*=(const Complex&c) {
	double x_1;
	x_1 = x * c.x - y * c.y;
	this->y= x * c.y + y * c.x;
	this->x = x_1;
	return *this;
	/*
	* c.x = c1.x * c2.x-c1.y*c2.y;
	c.y = c1.x * c2.y+c1.y*c2.x;
	*/
}
Complex& Complex::operator/=(const Complex& c) {
	double  x_1;
	x_1= (x * c.x + y * c.y) / (c.x * c.x + c.y *c. y);
	this->y  = (y * c.x -x * c.y) / (c.x *c. x +c.y * c.y);
	this->x = x_1;
	return *this;
	/*c.x = (c1.x * c2.x +c1.y * c2.y)/(c2.x*c2.x+c2.y*c2.y);
	c.y = (c1.y*c2.x-c1.x*c2.y)/ (c2.x * c2.x + c2.y * c2.y);
	return c;*/
}
Complex operator+(const Complex& c1, const Complex& c2) {
	Complex c;
	c.x = c1.x + c2.x;
	c.y = c1.y + c2.y;
	return c;
}
Complex operator-(const Complex& c1, const Complex& c2) {
	Complex c;
	c.x = c1.x - c2.x;
	c.y = c1.y - c2.y;
	return c;
}
Complex operator*(const Complex& c1, const Complex& c2) {
	Complex c;
	c.x = c1.x * c2.x-c1.y*c2.y;
	c.y = c1.x * c2.y+c1.y*c2.x;
	return c;
}//复数乘法公式：(a + bi) * (c + di) = (ac - bd) + (ad + bc)i


Complex operator/(const Complex& c1, const Complex& c2) {
	//复数除法公式：(a + bi) / (c + di) = [(ac + bd) / (c * c + d * d)] + [(bc - ad) / (c * c + d * d)]i
	Complex c;
	c.x = (c1.x * c2.x +c1.y * c2.y)/(c2.x*c2.x+c2.y*c2.y);
	c.y = (c1.y*c2.x-c1.x*c2.y)/ (c2.x * c2.x + c2.y * c2.y);
	return c;
}
bool operator==(const Complex&c1, const Complex&c2) {
	if (c1.x == c2.x && c1.y == c2.y)
		return 1;
	else
		return 0;
}
bool operator!=(const Complex& c1, const Complex& c2) {
	if (c1.x != c2.x || c1.y != c2.y|| (c1.x != c2.x && c1.y != c2.y))
		return 1;
	else
		return 0;
}
ostream & operator<<(ostream & os, const Complex& c) {
	os << c.x << " + " << c.y << "i";
	return os;
}
istream & operator>>(istream & is, Complex& c) {
	is >> c.x >> c.y;
	return is;
}
int main()

{

	Complex c1, c2;

	cin >> c1 >> c2;

	cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << endl;

	cout << "c1+c2 = " << c1 + c2 << endl;

	cout << "c1-c2 = " << c1 - c2 << endl;

	cout << "c1*c2 = " << c1 * c2 << endl;

	cout << "c1/c2 = " << c1 / c2 << endl;

	cout << (c1 += c2) << endl;

	cout << (c1 -= c2) << endl;

	cout << (c1 *= c2) << endl;

	cout << (c1 /= c2) << endl;

	cout << (c1 == c2) << " " << (c1 != c2) << endl;

	return 0;

}



