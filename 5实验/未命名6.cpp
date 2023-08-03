#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
template <typename T> class MyQueue;//ǰ������
template <typename T> std::ostream& operator<<(std::ostream&, const MyQueue<T>&);
template <typename T>
class QueueItem
{
public:
    QueueItem(const T& t) :item(t), next(0)
    {}
private:
    T item; //value stored in this element
    QueueItem* next; // pointer to next element in the MyQueue

    friend class MyQueue<T>;//��Ԫ��    
    //ͨ����Ԫ��������<<�����ģ�庯����Ҫд��<<���<Type>
    friend ostream& operator<< <T> (ostream& os, const MyQueue<T>& q);
};

template <typename T>
class MyQueue
{
public:
    MyQueue() : head(0), tail(0) {} // Empty MyQueue

    MyQueue(const MyQueue& Q) //�������캯��
        :head(0), tail(0)
    {
        CopyElements(Q);
    }

    ~MyQueue() { Destroy(); }

    MyQueue& operator=(const MyQueue& q) {
        head = q.head;
        tail = q.tail;
        return *this;
    }

    // return element from head of MyQueue
    T& Front() { return head->item; }

    const T& Front() const { return head->item; }

    void Push(const T& item) //add element to back of MyQueue
    {
        QueueItem<T>* newNode = new QueueItem<T>(item);    //����һ��Node���ָ��newNode
       
        QueueItem<T>* p = head;              //����ָ��pָ��ͷ���
        if (head == NULL) {           //��ͷ���Ϊ��ʱ������newNodeΪͷ���
            head = newNode;
        }
        else                          //ѭ��֪�����һ���ڵ㣬��newNode���������
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newNode;
        }
    }

    void Pop() // remove element from head of MyQueue
    {
        QueueItem<T>* p = head;
        if (p == NULL ) {   //�ж��Ƿ�Ϊ�ձ����쳣
            cout << "������Ϊ�ձ�" << endl;
        }
        else
        {
            head = head->next;
            delete p;
              //����һ��ռλ�ڵ�
              //ͷ����ָ�����
        }

    }
    bool Empty() const { return head == 0; }

    void Display() const {
        QueueItem<T>* p = head;
        
        while (p != NULL)
        {
            cout << p->item << " ";
            p = p->next;
        }
       
        p = NULL;
    }
private:
    QueueItem<T>* head;
    QueueItem<T>* tail;
    void Destroy() //delete all the elements
    {
        QueueItem<T>* p = head;
        QueueItem<T>* f = head->next;
        while (f != NULL) {
            p->next = f->next;
            delete f;
            f = p->next;
        }
        tail = head;
    }

    void CopyElements(const MyQueue& q) {
        head = q.head;
        tail = q.tail;
    }

    //������Ԫ����
    friend ostream& operator<< <T> (ostream& os, const MyQueue<T>& q);
};
template <typename T>
ostream& operator<< (ostream& os, const MyQueue<T>& q) {
    QueueItem<T>* p = q.head;
    cout << "< ";
    while (p )
    {
        cout << p->item << " ";
        p = p->next;
    }
    cout << ">";
    p = NULL;
    return os;
}

int main()
{
    MyQueue<int> qi;
    qi.Push(1);
    qi.Push(2);
    qi.Push(3);
    qi.Push(4);
    qi.Push(5);
    qi.Pop();
    qi.Display();
    cout << "\n";
    cout << qi;
    cout << endl;

    MyQueue<int> qi2(qi);
    qi2.Display();
    cout << endl;

    MyQueue<int> qi3;
    qi3 = qi;
    cout << qi3;

    return 0;
}
