#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
	vector<string> svec{ "ab","cd" };
	//使用t迭代器
	for (auto t = svec.begin(); t != svec.end(); ++t)
		cout << *t << endl;

	vector<int> ivec(5,9);
	//末尾添加元素
	ivec.push_back(10);
	for (auto t = ivec.begin(); t != ivec.end(); ++t)
		cout << *t << endl;
	//查询里面的某个值的引用
	cout << ivec[0] << endl;
	ivec[0] = 10;
	cout << ivec[0] << endl;
	//查询数据类型
	cout << typeid(ivec.begin()).name() << endl;
	cout << typeid(ivec).name() << endl;

	//Practice
	vector<string> v;
	string s;
	char c = 'y';
	while (c == 'y' || c == 'Y')
	{
		cout << "Please typing your word... ..." << endl;
		cin >> s;
		v.push_back(s);
		cout << "Continue?('y'or'n')" << endl;
		cin >> c;
	}

	for (auto item : v)
		cout << item << "  ";
	cout << endl;
	cout << "After changing... ..." << endl;

	//引用修改其中的值
	for (auto& item : v)
	{
		for (auto& s : item)
			s = toupper(s);
	}
	for (auto item : v)
		cout << item << "  ";
	return 0;
}