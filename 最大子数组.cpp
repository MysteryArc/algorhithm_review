/*
 * @FileName   : 最大子数组.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/03 13:15:25
 * 动态规划法
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int maxSubarray(vector<int> nums)
{
    int size = nums.size();
    int res = 0, sum[size] = {0};
    sum[0] = nums[0], res = sum[0];
    int begin = 0, end = 0, len = 1;
    for (int i = 1; i < size; i++)
    {
        if (nums[i] > sum[i - 1] + nums[i])
            len = 1;
        else
            len++;
        sum[i] = max(sum[i - 1] + nums[i], nums[i]);
        if (sum[i] > res)
        {
            end = i;
            begin = i - len + 1;
            res = sum[i];
        }
    }
    cout << "最大子数组为：";
    for (int i = begin; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl
         << "和为：" << res << endl;
    return res;
}

int main()
{
    vector<int> a = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    maxSubarray(a);
    return 0;
}