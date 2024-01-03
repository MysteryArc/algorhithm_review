/*
 * @FileName   : LCS.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2023/11/23 14:47:30
 * 最长公共子串
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void lcs(string s1, string s2)
{
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length()));
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            int index1 = i, index2 = j;
            while (index1 < s1.length() && index2 < s2.length() && s1[index1] == s2[index2])
            {
                dp[index1][index2]++;
                index1++;
                index2++;
            }
        }
    }
    int maxlen = 0, maxi = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (dp[i][j] > maxlen)
            {
                maxlen = dp[i][j];
                maxi = i;
            }
        }
    }
    cout << "最长公共子串长度为：" << maxlen << endl;
    cout << "子串为：" << s1.substr(maxi - maxlen + 1, maxlen) << endl;
}

int main()
{
    string str1 = "10010101";
    string str2 = "010110110";
    lcs(str1, str2);
    return 0;
}