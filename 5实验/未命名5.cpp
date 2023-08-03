#include<iostream>
#include<cstdlib>
using namespace std;
template<class T, int SIZE = 20>
class Stack
{
private: 
    T array[SIZE];        //���飬���ڴ��ջ��Ԫ��
    int top;                //ջ��λ�ã������±꣩
public:
    Stack(){
	top=-1;}//���캯������ʼ��ջ
	         
    void Push(const T & s)  //Ԫ����ջ
    {
    	if(top!=SIZE-1){
    		top+=1;
    		array[top]=s;
		}
		else
		exit(1);
	}
	T Pop()                //ջ��Ԫ�س�ջ
    {
    	
    	if(top!=-1){
			T tem;
    		tem=array[top]; 
    		top-=1;
    		return tem;
		}
		else
		{exit(1);
		 } 
		
	}
	void Clear()           //��ջ���
    {
		 top=-1;
	}
	const T & Top() const  //����ջ��Ԫ��
    {
    	if(top!=-1){
    		return array[top];
		}
		else
		exit(1);
	}
	bool Empty() const    //����ջ�Ƿ�Ϊ��
    {
    	if(top==-1){
    		return 1;
		}
		else
		return 0;
	}
	bool Full() const     //�����Ƿ�ջ��
    {
    	if(top==SIZE){
    		return 1;
		}
		else
		return 0;
	}
	int Size()            //���ص�ǰջ��Ԫ�ظ���
	{
		return top+1;
	}
};


int main()
{
    Stack<int, 10> intStack;

    int n;
    cin >> n; //n<=10
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        intStack.Push(temp);
    }

    for (int i = 0; i < n; i++)
    {
        cout << intStack.Top() << " ";
        intStack.Pop();
    }
    cout<<endl;

    if(intStack.Empty())
        cout<<"Now, intStack is empty."<<endl;

    Stack<string,5> stringStack;
    stringStack.Push("One");
    stringStack.Push("Two");
    stringStack.Push("Three");
    stringStack.Push("Four");
    stringStack.Push("Five");
    cout<<"There are "<<stringStack.Size()<<" elements in stringStack."<<endl;
    stringStack.Clear();
    if(stringStack.Empty()) 
        cout<<"Now, there are no elements in stringStack"<<endl;

    return 0;
}

 
