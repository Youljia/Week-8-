#include<iostream>
using namespace std;

class Solution
{
public:
	Solution(int* p, int l)
	{
		arra = new int[l];
		this->len = l;
		for (int i = 0; i < l; ++i)
			this->arra[i] = p[i];
	}
	~Solution()
	{
		cout << "This arra is releasing... ..." << endl;
		if (arra != nullptr)
			delete[] arra;
		arra = nullptr;
		len = NULL;
	}
	void sort()
	{
		quick_sort(0, len - 1);
	}
	void show()
	{
		cout << "[ ";
		for (int i = 0; i < len; ++i)
		{
			cout << arra[i];
			if (i != len - 1)
				cout << ",";
		}
		cout << " ]" << endl;
	}
private:
	//递归调用
	//意义:对[l,r]进行排序
	void quick_sort(int l, int r)
	{
		if (l >= r)
			return;
		//为区间添加随机性
		int q = rand() % (r - l + 1);
		swap(arra[l], arra[l + q]);
		int p = partition(l, r);
		quick_sort(l, p - 1);
		quick_sort(p + 1, r);
	}
	int partition(int l, int r)
	{
		int i = l + 1;
		int j = r;
		while (true)
		{
			while (i <= j && arra[i] < arra[l])
				++i;
			while (i <= j && arra[j] > arra[l])
				--j;

			if (i >= j)
				break;

			swap(arra[i], arra[j]);
			++i;
			--j;
		}
		swap(arra[j], arra[l]);
		return j;
	}
	//互换
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
	int p[10] = { 2,3,4,5,6,1,7,8,9,10 };
	Solution s(p, 10);
	s.show();
	s.sort();
	s.show();
	return 0;
} 