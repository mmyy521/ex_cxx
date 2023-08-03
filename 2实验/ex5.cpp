#include<iostream>
#include<string>
using namespace std;

class Subject    //ѡ����
{
private:
    double score[3];                //3�ſγɼ�
    const int SMath, SEng, SCpp;    //3�ſε�ѧ�֣��ֱ�Ϊ4��2��2
public:
    Subject(int math = 0, int eng = 0, int cpp = 0);
    void Input();            //����3�ſεĳɼ�
    friend class Student;    //��Ԫ��
};

Subject::Subject(int math,int eng,int cpp):SMath(4),SEng(2),SCpp(2)
{
	
}

void Subject::Input(){
	int math,eng,cpp;
	cin >> math >> eng >> cpp; 
	score[0] = math;
	score[1] = eng;
	score[2] = cpp;
}

class Student
{
private:
    string ID;        //ѧ��
    string name;       //����
    double GPA;        //ƽ��ѧ�ֻ�=���ɼ�1xѧ��1+�ɼ�2xѧ��2+�ɼ�3xѧ��3��/��ѧ��1+ѧ��2+ѧ��3��
public:
    Student(string id = "00000", string na = "Noname");
    void CalculateGPA(const Subject &sub);    //����ƽ��ѧ�ֻ�
    void Input();                            //����ѧ�ź�����
    void Show(const Subject &sub)const;        //���������Ϣ
};

Student::Student(string id,string na){
	ID = id;
	name = na;
}

void Student::CalculateGPA(const Subject & sub){
	GPA = (sub.score[0]*sub.SMath+sub.score[1]*sub.SEng+sub.score[2]*sub.SCpp)/(sub.SMath+sub.SEng+sub.SCpp);
	
}

void Student::Input(){
	string i,n;
	cin>>i>>n;
	ID = i;
	name = n;
}

void Student::Show(const Subject &sub)const{
	cout<<"ID: "<<ID<<","<<" Name: "<<name<<"\n";
	cout<<"Math "<<"Eng "<<"Cpp"<<"\n";
	cout<<sub.score[0]<<' '<<sub.score[1]<<' '<<sub.score[2]<<' '<<"\n";
	cout<<"GPA: "<<GPA<<endl;
}

int main()
{
    int n;        //ѧ������
    cin >> n;
    Student *stu = new Student[n];
    Subject *sub = new Subject[n];
    for (int i = 0; i < n; i++)
    {
        stu[i].Input();
        sub[i].Input();
    }
    for (int i = 0; i < n; i++)
    {
        stu[i].CalculateGPA(sub[i]);
        stu[i].Show(sub[i]);
    }
    delete[] stu;
    delete[] sub;
    return 0;
}

