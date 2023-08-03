#include<iostream>
#include<string>
using namespace std;
class Sales_data {

	//依次输入书号、销量和收入

	friend istream& operator>>(istream&, Sales_data&);

	//依次输出书号、销量、收入和均价

	friend ostream& operator<<(ostream&, const Sales_data&);

	friend bool operator==(const Sales_data&, const Sales_data&);

	friend bool operator!=(const Sales_data&, const Sales_data&);

	// for "+", assume that both objects refer to the same book

	friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:

	Sales_data() : units_sold(0), revenue(0.0) {}

	Sales_data(const string& s, unsigned n, double r) : bookNo(s), units_sold(n), revenue(r) {}

	string get_bookNo() const;

	// for "+=", assume that both objects refer to the same book

	Sales_data& operator+=(const Sales_data&);

private:

	double avg_price() const;  //均价，等于收入除以销量

	string bookNo;        //书号

	unsigned units_sold; //销量

	double revenue;      //收入

};

double Sales_data::avg_price()const  {
	double m;
	m = revenue / units_sold;
	return m;
}
string Sales_data::get_bookNo()const {
	return bookNo;
}
Sales_data& Sales_data::operator+=(const Sales_data& s) {
	
	
	this->units_sold +=  s.units_sold;
	this->revenue += s.revenue ;
	return  *this;
}
istream & operator>>(istream & is, Sales_data & s) {
	is >> s.bookNo>> s.units_sold >> s.revenue;
	return is;
}
ostream& operator<<(ostream & os, const Sales_data & s) {
	os << s.bookNo<< " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
	return os;
}

bool operator==(const Sales_data& s1, const Sales_data&s2) {
	if (s1.revenue == s2.revenue)
		return 1;
	else
		return 0;
}
bool operator!=(const Sales_data& s1, const Sales_data& s2) {
	if (s1.revenue != s2.revenue)
		return 1;
	else
		return 0;
}
Sales_data operator+(const Sales_data& s1, const Sales_data&s2) {
	Sales_data m;
	m.bookNo = s1.bookNo;
	m.revenue = s1.revenue + s2.revenue;
	m.units_sold = s1.units_sold + s2.units_sold;
	return m;
}
int main() {

	Sales_data item1, item2;

	while (cin >> item1 >> item2) {

		cout << item1 << "\n" << item2 << "\n";

		if (item1 == item2)

			cout << item1.get_bookNo() << " equals " << item2.get_bookNo() << "\n";

		if (item1 != item2)

			cout << item1.get_bookNo() << " doesn't equal " << item2.get_bookNo() << "\n";

		cout << (item1 + item2) << "\n";

		item1 += item2;

		cout << item1 << "\n";

	}

	return 0;

}

