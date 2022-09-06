#pragma once
#include<iostream>
using namespace std;
class MyString
{
public:
	MyString();
	MyString(const char* p);
	MyString(const MyString& another);
	~MyString();
	//重载[]
	char operator[](int i);
	//重载=
	void operator=(const char* p);
	void operator=(const MyString& another);
	//重载==
	bool operator==(const char* p);
	bool operator==(const MyString& another);
	//重载+
	MyString operator+(const char* p);
	MyString operator+(const MyString& another);
private:
	int len;
	char* str;
};

