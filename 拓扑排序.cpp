/*
 * @FileName   : 拓扑排序.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/05 17:30:13
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<char> v = {'A', 'B', 'C', 'D', 'E'};

void topo(vector<int> &in, vector<vector<int>> adj)
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int current = q.front();
        cout << v[current] << " ";
        q.pop();
        for (int i = 0; i < 5; i++)
        {
            if (adj[current][i] == 1)
            {
                if (--in[i] == 0)
                    q.push(i);
            }
        }
    }
}

int main()
{
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    vector<int> in(5); // 入度
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            in[i] += adjMatrix[j][i];
        }
    }
    topo(in, adjMatrix);
    return 0;
}