/*
 * @FileName   : DFS.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/05 14:52:03
 */
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<char> v = {'u', 'v', 'w', 'x', 'y', 'z', 't', 's'};
vector<int> flag(v.size(), 0);

void search(vector<vector<int>> adj, int index)
{
    cout << v[index] << ":" << time(nullptr) << " ";
    flag[index] = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (flag[i] == 0 && adj[index][i] == 1)
        {
            search(adj, i);
        }
    }
}

void DFS(vector<vector<int>> adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        if (flag[i] == 0)
        {
            search(adj, i);
        }
    }
}

int main()
{
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}};
    DFS(adjMatrix);
    cout << endl;
    return 0;
}