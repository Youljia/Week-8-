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

	int find(const int k)
	{
		return quick_sort(0, this->len - 1, k);
	}

	int quick_sort(int l, int r, int k)
	{
		int p = partition(l, r);
		if (p == k)
			return arra[p];
		else if (p > k)
			quick_sort(l, p - 1, k);
		else
			quick_sort(p + 1, r, k);
	}

	int partition(int l, int r)
	{
		int j = l;
		int i = l + 1;
		for (i; i <= r; ++i)
		{
			if (arra[i] <= arra[l])
			{
				j++;
				swap(arra[i], arra[j]);
			}
		}
		swap(arra[l], arra[j]);
		return j;
	}

	//»¥»»
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
	int p[6] = {1,3,2,9,5,8 };
	Solution s(p, 6);
	cout << s.find(2) << endl;
	return 0;
}