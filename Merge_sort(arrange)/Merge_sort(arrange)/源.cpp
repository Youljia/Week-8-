#include<iostream>
using namespace std;

//n元排列类
class Arrange
{
public:
	//初始化类
	Arrange(int* p, int l)
	{
		this->arra = p;
		this->len = l;
	}
	//析构，防止内存泄漏
	~Arrange()
	{
		cout << "This arra is releasing... ..." << endl;
		if (arra != nullptr)
			delete arra;
		arra = nullptr;
		len = NULL;
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
	//是否为空
	bool is_empty()
	{
		if (len == 0)
			return true;
		return false;
	}
	//查找排列元素
	int get_data(int i)
	{
		return this->arra[i];
	}
	//对换
	void exchange(int i, int j)
	{
		int temp;
		temp = arra[1];
		arra[1] = arra[j];
		arra[j] = temp;
	}
	//n元排列的排列方式
	int ways()
	{
		return count_ways(len);
	}
	int count_ways(int n)
	{
		if (n == 1)
			return 1;
		return n * count_ways(n - 1);

	}
	//是否为自然排列
	bool is_natural()
	{
		for (int i = 1; i < len; ++i)
		{
			if (arra[i] - arra[i - 1] != 1)
				return false;
		}
		return true;
	}
	//逆序数
	int reverse_count()
	{
		int* arra_copy = new int[len];
		for (int x = 0; x < len; ++x)
		{
			arra_copy[x] = this->arra[x];
		}
		int rev = 0;
		merge_sort(arra_copy, 0, len - 1, rev);
		return rev;
	}
	//奇偶排列(0为偶，1为奇)
	int judge_parity()
	{
		int i = reverse_count();
		if (i % 2 == 0)
			return 0;
		else
			return 1;
	}
	//归并排序法
	void merge_sort(int* arra1, int l, int r, int& rev)
	{
		if (l >= r)
			return;
		int mid = (l + r) / 2;
		merge_sort(arra1, l, mid, rev);
		merge_sort(arra1, mid + 1, r, rev);
		merge(arra1, l, mid, r, rev);
	}
	//合并两个有序数组
	void merge(int* arra1, int l, int mid, int r, int& rev)
	{
		if (arra1[mid] > arra1[mid + 1])
		{
			int i = l;
			int j = mid + 1;
			for (int t = l; t <= r; ++t)
			{
				if (i > mid)
				{
					arra1[t] = arra[j];
					++j;
				}
				else if (j > r)
				{
					arra1[t] = arra[i];
					++i;
				}
				else if (arra[i] <= arra[j])
				{
					arra1[t] = arra[i];
					++i;
				}
				else
				{
					arra1[t] = arra[j];
					rev += mid - i + 1;
					++j;
				}
			}
		}
	}


private:
	int* arra;
	int len;
};

//判断是否是n元排列
bool is_arrange(int* arra,int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (arra[i] == arra[j])
				return false;
		}
	}
	return true;
}

int main()
{
	int* p = new int[5];
	p[0] = 5;
	p[1] = 4;
	p[2] = 3;
	p[3] = 2;
	p[4] = 1;
	if (is_arrange(p, 5))
	{
		Arrange a(p, 5);
		int i = a.ways();
		cout << i << endl;
		a.show();
		if (a.is_natural())
			cout << "是！" << endl;
		else
			cout << "否！" << endl;
		a.show();
		cout << a.reverse_count() << endl;
		if (a.judge_parity() == 0)
			cout << "偶排列" << endl;
		else
			cout << "奇排列" << endl;

		a.exchange(1, 4);
		a.show();
		cout << a.reverse_count() << endl;
		if (a.judge_parity() == 0)
			cout << "偶排列" << endl;
		else
			cout << "奇排列" << endl;
	}
	else
		cout << "非排列！" << endl;
	return 0;
}