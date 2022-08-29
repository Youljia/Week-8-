#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
	vector<string> svec{ "ab","cd" };
	//ʹ��t������
	for (auto t = svec.begin(); t != svec.end(); ++t)
		cout << *t << endl;

	vector<int> ivec(5,9);
	//ĩβ���Ԫ��
	ivec.push_back(10);
	for (auto t = ivec.begin(); t != ivec.end(); ++t)
		cout << *t << endl;
	//��ѯ�����ĳ��ֵ������
	cout << ivec[0] << endl;
	ivec[0] = 10;
	cout << ivec[0] << endl;
	//��ѯ��������
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

	//�����޸����е�ֵ
	for (auto& item : v)
	{
		for (auto& s : item)
			s = toupper(s);
	}
	for (auto item : v)
		cout << item << "  ";
	return 0;
}