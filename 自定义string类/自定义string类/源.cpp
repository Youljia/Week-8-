#include<iostream>
#include<string>
#include"MyString.h"
using namespace std;

int main()
{
	//string其实是一个已经封装好了的类
	string name = "nihaoa";
	//调用了拷贝构造函数（深拷贝）
	string name2 = name;
	name.append("!");
	cout << name[2] << endl;
	cout << name2 << endl;
	string s = "nibab";
	string s1;
	cout << s[5];
	//等号赋值操作符
	s.append("!");
	cout << s1 << endl;
	cout << s << endl;
	if (s1 != s)
	{
		cout << "不相等！" << endl;
	}
	string s2;
	s2 = s + s1;
	cout << s2;
	s1.append(s);

	string s3;
	cin >> s3;
	cout << s3 << endl;
	s3 == "nihaoa";
	MyString s("nihaoa");
	cout << s[2] << endl;
	return 0;
}