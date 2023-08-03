#include<iostream>
#include<string>
using namespace std;
class Singer {
private:
	string name;
	string sex;
	int age;
	double g;
public:
	friend bool operator > (const Singer&, const Singer&);
	friend bool operator == (const Singer&, const Singer&);
	friend ostream& operator<<(ostream&, const Singer&);
	friend istream& operator>>(istream&, Singer&);
	string getName();

};


bool operator > (const Singer& a, const Singer& b) {
	if (a.g > b.g)
		return 1;
	else
		return 0;
}
bool operator == (const Singer& a, const Singer& b) {
	if (a.g == b.g) {
		return 1;
	}
	else
		return 0;
}
ostream& operator<<(ostream& os, const Singer& s) {
	os << s.name << " " << s.sex << " " << s.age << " " << s.g << endl;
	return os;
}
istream& operator>>(istream & is, Singer& s) {
	is >> s.name >> s.sex >> s.age >> s.g;
	return is;
}
string Singer::getName() {
	return name;
}

int main()

{

	Singer s1, s2;

	cin >> s1 >> s2;

	cout << s1 << "\n" << s2 << endl;

	if (s1 > s2)

		cout << s1.getName() << "'s score is higher than " << s2.getName() << "'s.\n";

	else if (s1 == s2)

		cout << s1.getName() << "'s score is equal to " << s2.getName() << "'s.\n";

	else

		cout << s1.getName() << "'s score is lower than " << s2.getName() << "'s.\n";

	return 0;

}



