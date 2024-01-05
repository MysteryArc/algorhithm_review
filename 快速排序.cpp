/*
 * @FileName   : 快速排序.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/03 14:16:04
 */
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void quickSort(vector<int> &nums, int begin, int end)
{
    if (begin < end)
    {
        int base = nums[begin];
        int i = begin, j = end;
        while (i < j)
        {
            while (nums[j] >= base && i < j)
            {
                j--;
            }
            while (nums[i] <= base && i < j)
            {
                i++;
            }
            swap(nums, i, j);
        }
        swap(nums, begin, j);
        quickSort(nums, begin, j - 1);
        quickSort(nums, j + 1, end);
    }
}

int main()
{
    vector<int> nums = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}