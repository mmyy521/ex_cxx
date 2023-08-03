// 注意：无需提交main函数
#include<iostream>
#include<string>
using namespace std;
class CPU {
private:
	string cpuType;
	double frequency;
public:
	CPU(string c, double f) {
		this->cpuType = c;
		this->frequency = f;
	}
	CPU() {}
	~CPU() {}
	string ct() {
		return cpuType;
	}
	double fq() {
		return frequency;
	}
};
class Disk {
private:
	string  diskType;
	double  capacity;
public:
	Disk(string d, double c) {
		diskType = d;
		capacity = c;
	}
	Disk() {}
	~Disk() {}

	string dt() {
		return diskType;
	}
	double cc() {
		return capacity;
	}
};
class Computer {
private:
	string a;
	double b;
	string Dc;
	double Dd;
public:
	Computer(CPU c, Disk d) {
		a = c.ct();
		b = c.fq();
		Dc = d.dt();
		Dd = d.cc();
	}
	void Print() {
		cout << "The computer has a cpu and a disk." << endl;
		cout << "CPU type: " << a << ",  CPU frequency: " << b << " GHz" << endl;
		cout << "disk type: " << Dc << ", disk capacity: " << Dd << " T" << endl;
	}
};
int main()
{
	string cpuType, diskType;
	double frequency, capacity;
	cin >> cpuType >> frequency >> diskType >> capacity;
	CPU cpu(cpuType, frequency);
	Disk disk(diskType, capacity);
	Computer computer(cpu, disk);

	computer.Print();
	return 0;
}