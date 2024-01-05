/*
 * @FileName   : 最大兼容活动.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/05 14:17:24
 * 贪心算法
 */
#include <iostream>
#include <vector>
using namespace std;

void activityChain(vector<int> begin, vector<int> end)
{
    int now = 0;
    for (int i = 0; i < end.size(); i++)
    {
        if (begin[i] >= now)
        {
            cout << i + 1 << " ";
            now = end[i];
        }
    }
    cout << endl;
}

int main()
{
    vector<int> begin = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    vector<int> end = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    activityChain(begin, end);
    return 0;
}