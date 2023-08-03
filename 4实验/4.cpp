#include<iostream>
#include<cstring>
using namespace std;
class String
{
private:
	char* s;
public:
	String();
	String(const char*);
	String(const String&);
	~String();
	String& operator=(const char*);
	String& operator=(const String&);
	String operator+(const char*);
	String operator+(const String&);
	String& operator+=(const char*);
	String& operator+=(const String&);
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, const String&);
	friend bool operator==(const String&, const char*);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const char*);
	friend bool operator!=(const String&, const String&);
};
String::String() {
	s = NULL;
}
String::String(const char* x)
{
	s = new char[strlen(x) + 1];
	strcpy(s, x);
}
String::String(const String& x)
{
	
		s = new char[strlen(x.s) + 1];
		strcpy(s, x.s);
}
String::~String()
{		delete[] s;
}
String& String::operator=(const char* x) {
	if (s != NULL) {
		delete[] s;

	}
	s = new char[strlen(x) + 1];
	strcpy(s, x);
	return *this;
	
}
String& String::operator=(const String& x) {
	
			s=new char[strlen(x.s+1)];
			strcpy(s, x.s);
			return *this;
	
}
String String::operator+(const String& x) {
	strcat(s,x.s);
}
String String::operator+(const char* x) {
//	s = new char[strlen(s)+strlen(x) + 1];
//	strcat(s, x);
	return String(s)+String(x);
}
String& String::operator+=(const char* x) {
	strcat(s,x);
	return *this;
	
}
String& String::operator+=(const String& x) {//此处有疑问 
     char*t;
	t = new char[strlen(s) + strlen(x.s) + 1];
	t=this->s;
	strcat(t, x.s);
	this->s=t;
	return *this;
}
istream& operator>>(istream& is, String& x) {
	char tem[1000];
	is>>tem;
	strcpy(x.s,tem);
	return is;
}
ostream& operator<<(ostream& os, const String& x) {
	os << x.s;
	return os;
}
bool operator==(const String& x, const char* s2) {
	if (strcmp(x.s, s2)==0) {
		return 1;
	}
	else {
		return 0;
	}
}
bool operator==(const String& x, const String& s2) {
	if (strcmp(x.s, s2.s) == 0)
		return 1;
	else
		return 0;
		

}
bool operator!=(const String& x, const char* s2) {
	if (strcmp(x.s,s2) != 0)
		return 1;
	else
		return 0;
		
}
bool operator!=(const String& x, const String& s2) {
	if (strcmp(x.s, s2.s) != 0)
		return 1;
	else
		return 0;


}
int main()
{
	String s;
	s += "hello";
	cout << s << endl;
	String s1("String1");
	String s2("copy of ");
	s2 += "String1";
	cout << s1 << "\n" << s2 << endl;
	String s3;
	cin >> s3;
	cout << s3 << endl;
	String s4("String4"), s5(s4);
	cout << (s5 == s4) << endl;
	cout << (s5 != s4) << endl;
	String s6("End of "), s7("my string.");
	s6 += s7;
	cout << s6 << endl;
	return 0;
}


