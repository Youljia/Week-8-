#include "MyString.h"
//无参构造函数
MyString::MyString()
{
	this->str = nullptr;
	this->len = 0;
}
//深拷贝构造函数
MyString::MyString(const char* p)
{
	this->len = strlen(p);
	this->str = new char[len + 1];
	for (int i = 0; i < len; ++i)
		this->str[i] = p[i];
	this->str[len] = '\0';
}
MyString::MyString(const MyString& another)
{
	this->str = new char[another.len];
	this->len = another.len;
	for (int i = 0; i < len; ++i)
		str[i] = another.str[i];
	str[len] = '\0';
}
MyString::~MyString()
{
	cout << "This string is releasing... ..." << endl;
	if (this->str != nullptr)
		delete[] str;
	this->str = nullptr;
}
//重载[]
char MyString::operator[](int i)
{
	return this->str[i];
}
//重载=
void MyString::operator=(const char* p)
{
	this->len = strlen(p);
	this->str = new char[len + 1];
	for (int i = 0; i < len; ++i)
		this->str[i] = p[i];
	this->str[len] = '\0';
}
void MyString::operator=(const MyString& another)
{
	this->str = new char[another.len];
	this->len = another.len;
	for (int i = 0; i < len; ++i)
		str[i] = another.str[i];
	str[len] = '\0';
}
//重载==
bool MyString::operator==(const char* p)
{
	if (this->len != strlen(p))
		return false;
	else
		for (int i = 0; i < len; ++i)
		{
			if (this->str[i] != p[i])
				return false;
		}
	return true;
}
bool MyString::operator==(const MyString& another)
{
	if (this->len != another.len)
		return false;
	else
		for (int i = 0; i < len; ++i)
		{
			if (this->str[i] != another.str[i])
				return false;
		}
	return true;
}
//重载+
MyString MyString::operator+(const char* p)
{
	MyString str1;
	int i = 0;
	str1.len = this->len + strlen(p);
	str1.str = new char[str1.len + 1];
	for (i; i < this->len; ++i)
		str1.str[i] = this->str[i];
	for (i; i < str1.len; ++i)
		str1.str[i] = p[i];
	str1.str[str1.len] = '\0';
	return str1;
}
MyString MyString::operator+(const MyString& another)
{
	MyString str1;
	int i = 0;
	str1.len = this->len + another.len;
	str1.str = new char[str1.len + 1];
	for (i; i < this->len; ++i)
		str1.str[i] = this->str[i];
	for (i; i < str1.len; ++i)
		str1.str[i] = another.str[i];
	str1.str[str1.len] = '\0';
	return str1;
}

