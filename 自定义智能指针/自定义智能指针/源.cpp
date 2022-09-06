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

//自定义智能指针类
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

	//重载->操作符
	T* operator->()
	{
		return this->ptr;
	}
	//重载*操作符
	T& operator*()
	{
		return *(this->ptr);
	}
private:
	T* ptr;
};

int main()
{
	//智能指针
	auto_ptr<A> ptr(new A(10));
	//通过指针访问
	ptr->show();
	//通过对象访问
	(*ptr).show();

	Auto_ptr<A> ptr1(new A(10));
	ptr1->show();
	(*ptr1).show();
	return 0;
}