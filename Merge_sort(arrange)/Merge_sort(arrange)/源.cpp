#include<iostream>
using namespace std;

//nԪ������
class Arrange
{
public:
	//��ʼ����
	Arrange(int* p, int l)
	{
		this->arra = p;
		this->len = l;
	}
	//��������ֹ�ڴ�й©
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
	//�Ƿ�Ϊ��
	bool is_empty()
	{
		if (len == 0)
			return true;
		return false;
	}
	//��������Ԫ��
	int get_data(int i)
	{
		return this->arra[i];
	}
	//�Ի�
	void exchange(int i, int j)
	{
		int temp;
		temp = arra[1];
		arra[1] = arra[j];
		arra[j] = temp;
	}
	//nԪ���е����з�ʽ
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
	//�Ƿ�Ϊ��Ȼ����
	bool is_natural()
	{
		for (int i = 1; i < len; ++i)
		{
			if (arra[i] - arra[i - 1] != 1)
				return false;
		}
		return true;
	}
	//������
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
	//��ż����(0Ϊż��1Ϊ��)
	int judge_parity()
	{
		int i = reverse_count();
		if (i % 2 == 0)
			return 0;
		else
			return 1;
	}
	//�鲢����
	void merge_sort(int* arra1, int l, int r, int& rev)
	{
		if (l >= r)
			return;
		int mid = (l + r) / 2;
		merge_sort(arra1, l, mid, rev);
		merge_sort(arra1, mid + 1, r, rev);
		merge(arra1, l, mid, r, rev);
	}
	//�ϲ�������������
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

//�ж��Ƿ���nԪ����
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
			cout << "�ǣ�" << endl;
		else
			cout << "��" << endl;
		a.show();
		cout << a.reverse_count() << endl;
		if (a.judge_parity() == 0)
			cout << "ż����" << endl;
		else
			cout << "������" << endl;

		a.exchange(1, 4);
		a.show();
		cout << a.reverse_count() << endl;
		if (a.judge_parity() == 0)
			cout << "ż����" << endl;
		else
			cout << "������" << endl;
	}
	else
		cout << "�����У�" << endl;
	return 0;
}