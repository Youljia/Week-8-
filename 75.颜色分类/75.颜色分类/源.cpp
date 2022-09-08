#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(0, nums.size() - 1, nums);
    }

    void quick_sort(int l, int r, vector<int>& nums)
    {
        if (l >= r)
            return;
        //三路快速排序法的partition
        int lt = l;
        int gt = r + 1;
        int i = l + 1;
        while (i < gt)
        {
            if (nums[i] > nums[l])
            {
                --gt;
                swap(nums[i], nums[gt]);
            }
            else if (nums[i] < nums[l])
            {
                ++lt;
                swap(nums[i], nums[lt]);
                ++i;
            }
            else
                ++i;
        }
        swap(nums[l], nums[lt]);
        quick_sort(l, lt - 1, nums);
        quick_sort(gt, r, nums);
    }

    void swap(int& i, int& j)
    {
        int temp = i;
        i = j;
        j = temp;
    }
};

int main()
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(0);
    for (int i = 0; i < 6; ++i)
        cout << v1.at(i) << endl;

    Solution s;
    s.sortColors(v1);
    for (int i = 0; i < 6; ++i)
        cout << v1.at(i) << endl;
}