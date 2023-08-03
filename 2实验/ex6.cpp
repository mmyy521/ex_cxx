#include<iostream>
#include<string>
using namespace std;

class Hotel{
	private:
		int ID;
		string name;
		
	public:
		int getTotal();
		void add(string na);
		string getName();
		void print(); 
};

int total = 0;

int Hotel::getTotal(){
	return total;
}

void Hotel::add(string na){
	total++;
	name = na;	
	ID = total;
}

string Hotel::getName(){
	return name;
}

void Hotel::print(){
	cout<< ID <<" "<< name <<" "<< total;
}
int main(){

Hotel h[100];

h[0].add("Susan");

h[1].add("Peter");

h[2].add("John");

h[3].add("Mary");

h[4].add("Alice");

string name1;

cin>>name1;

for(int i=0;i<total;i++)

{

if(h[i].getName()==name1)

{

h[i].print();

break;

}

}

return 0;
}


