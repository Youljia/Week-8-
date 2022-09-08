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
	//对arra[l,r]进行排序
	void quick_sort(int l, int r)
	{
		if (l >= r)
			return;
		//增加随机性
		int q = l + rand() % (r - l + 1);
		swap(arra[l], arra[q]);
		//partition
		int lt = l;
		int gt = r + 1;
		int i = l + 1;
		while (i < gt)
		{
			if (arra[i] > arra[l])
			{
				--gt;
				swap(arra[i], arra[gt]);
			}
			else if (arra[i] < arra[l])
			{
				++lt;
				swap(arra[i], arra[lt]);
				++i;
			}
			else
				++i;
		}
		swap(arra[l], arra[lt]);
		//递归调用
		quick_sort(l, lt - 1);
		quick_sort(gt, r);
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
	int p[6] = { 3,4,1,7,3,3 };
	Solution s(p, 6);
	s.show();
	s.sort();
	s.show();

	int p1[10] = { 2,3,4,5,6,1,7,1,1,1 };
	Solution s1(p1, 10);
	s1.show();
	s1.sort();
	s1.show();
	return 0;
}