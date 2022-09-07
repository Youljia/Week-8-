#include<iostream>
using namespace std;

class Solution
{
public:
	Solution(int* arra, int len)
	{
		this->arra = new int[len];
		for (int i = 0; i < len; ++i)
			this->arra[i] = arra[i];
		this->len = len;
	}
	~Solution()
	{
		cout << "This arra is releasing ... ..." << endl;
		if (arra != nullptr)
			delete[] arra;
		arra = nullptr;
		len = NULL;
	}
	void sort()
	{
		quick_sort(0, len - 1);
	}
	//递归排序
	//意义:对[l,r]进行排序
	void quick_sort(int l, int r)
	{
		if (l >= r)
			return;
		int p = partition(l, r);
		quick_sort(l, p - 1);
		quick_sort(p + 1, r);
	}
	//将元素e排在它最终应该在的位置
	//保证（<e）e (>e)
	int partition(int l, int r)
	{
		int i = l;
		int e = l + 1;
		for (e; e <= r; ++e)
		{
			if (this->arra[e] < this->arra[l])
			{
				i++;
				swap(arra[i], arra[e]);
			}
		}
		swap(arra[i], arra[l]);
		return i;
	}
	void show()
	{
		cout << "[ ";
		for (int i = 0; i < len; ++i)
		{
			cout << this->arra[i];
			if (i != len - 1)
				cout << " , ";
		}
		cout << " ]" << endl;
	}
private:
	void swap(int& i, int& j)
	{
		int temp = i;
		i = j;
		j = temp;
	}
private:
	int* arra;
	int len;
};

int main()
{
	int p[7] = { 4,7,2,1,5,3,6 };
	Solution s(p, 7);
	s.show();
	s.sort();
	s.show();
	return 0;
}