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
	//����[]
	char operator[](int i);
	//����=
	void operator=(const char* p);
	void operator=(const MyString& another);
	//����==
	bool operator==(const char* p);
	bool operator==(const MyString& another);
	//����+
	MyString operator+(const char* p);
	MyString operator+(const MyString& another);
private:
	int len;
	char* str;
};

