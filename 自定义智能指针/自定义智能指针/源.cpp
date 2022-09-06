#include<iostream>
#include<memory>
using namespace std;

class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	~A()
	{
		cout << "Releasing... ..." << endl;
	}
	void show()
	{
		cout << "a = " << this->a;
	}
private:
	int a;
};

//�Զ�������ָ����
template <typename T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr)
	{
		this->ptr = ptr;
	}
	~Auto_ptr()
	{
		if (ptr != nullptr)
			delete ptr;
		ptr = nullptr;
	}

	//����->������
	T* operator->()
	{
		return this->ptr;
	}
	//����*������
	T& operator*()
	{
		return *(this->ptr);
	}
private:
	T* ptr;
};

int main()
{
	//����ָ��
	auto_ptr<A> ptr(new A(10));
	//ͨ��ָ�����
	ptr->show();
	//ͨ���������
	(*ptr).show();

	Auto_ptr<A> ptr1(new A(10));
	ptr1->show();
	(*ptr1).show();
	return 0;
}