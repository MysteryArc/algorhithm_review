/*
 * @FileName   : BFS.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/05 16:14:05
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<char> v = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
vector<int> step(8, 0);
vector<int> flag(8, 0);

void BFS(queue<int> &q, vector<vector<int>> &adj)
{
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v.size(); i++)
        {
            if (adj[current][i] == 1 && flag[i] == 0)
            {
                q.push(i);
                flag[i] = 1;
                step[i] = step[current] + 1;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << v[i] << ":" << step[i] << " ";
    }
    cout << endl;
}

// 输出短程线
void getPath(vector<vector<int>> &adj, int index)
{
    vector<char> path;
    int current = index;
    int len = step[current];
    while (len > 0)
    {
        path.push_back(v[current]);
        for (int i = 0; i < 8; i++)
        {
            if (adj[current][i] == 1 && step[i] == len - 1)
            {
                current = i;
                len--;
                break;
            }
        }
    }
    path.push_back(v[1]);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> adjMatrix(8, vector<int>(8, 0));
    adjMatrix[0][1] = adjMatrix[0][4] = adjMatrix[1][0] = adjMatrix[1][5] = adjMatrix[2][3] = adjMatrix[2][5] = adjMatrix[2][6] = adjMatrix[3][2] = adjMatrix[3][7] = adjMatrix[4][0] = adjMatrix[5][1] = adjMatrix[5][2] = adjMatrix[5][6] = adjMatrix[6][2] = adjMatrix[6][5] = adjMatrix[6][7] = adjMatrix[7][3] = adjMatrix[7][6] = 1;
    queue<int> q;
    q.push(1);
    flag[1] = 1;
    BFS(q, adjMatrix);
    for (int i = 0; i < v.size(); i++)
    {
        cout << "to " << v[i] << ": ";
        getPath(adjMatrix, i);
    }
    return 0;
}