/*
 * @FileName   : 矩阵链乘.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/04 20:04:50
 * 动态规划
 */
#include <iostream>
#include <vector>
using namespace std;

void matrix_times(vector<int> matrix)
{
    int max = 1, len = matrix.size() - 1;
    for (int i = 0; i < len + 1; i++)
    {
        max *= matrix[i];
    }
    vector<vector<int>> times(len + 1, vector<int>(len + 1, 0)); // 记录乘积最小次数
    vector<vector<int>> cut(len + 1, vector<int>(len + 1, 0)); // 记录断开位置
    // 循环对角线
    for (int n = 2; n <= len; n++)
    {
        //循环行
        for (int i = 1; i <= len - n + 1; i++)
        {
            int j = i + n - 1;
            //设置初始值
            times[i][j] = times[i + 1][j] + matrix[i - 1] * matrix[i] * matrix[j];
            cut[i][j] = j;
            // 找最小值并记录
            for (int k = i + 1; k < j; k++)
            {
                int current = times[i][k] + times[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j];
                if (current < times[i][j])
                {
                    times[i][j] = current;
                    cut[i][j] = k;
                }
            }
        }
    }
    // 输出
    cout << times[1][len] << endl;
    int now = 1, p = 1, target = cut[now][len];
    while (p <= len)
    {
        cout << "(";
        while (p <= target)
            cout << p++;
        cout << ")";
        now = target + 1;
        if (now <= len && target != cut[now][len])
            target = cut[now][len];
        if (target != len)
            cout << "(";
    }
    cout << ")" << endl;
}

int main()
{
    vector<int> p = {5, 10, 3, 12, 5, 50, 6};
    matrix_times(p);
    return 0;
}