/*
 * @FileName   : 钢条切割.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/04 18:49:23
 * 动态规划
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // 不同长度钢条的价格

void best_cut(int len){
    vector<int> dp(len + 1, 0); // 计算每个长度的最优总价
    vector<int> cut(len + 1, 0); // 计算切割长度
    dp[0] = 0, dp[1] = 1;
    // 循环计算每个长度的dp
    for(int i = 2; i <= len; i++) {
        int max = price[i], maxlen = i; // 默认不切
        for(int j = 1; j < i; j++){
            if(dp[j] + dp[i - j] > max){
                max = dp[j] + dp[i - j];
                maxlen = j;
            }
        }
        dp[i] = max;
        cut[i] = maxlen;
    }
    // 输出
    cout<<"长度为"<<len<<"的钢管最优切割步骤为: ";
    int cutting = len;
    while(cut[cutting] != cutting) {
        cout<<cut[cutting]<<" ";
        cutting = cutting - cut[cutting];
    }
    cout<<cutting<<endl;
    cout<<"最大价值为："<<dp[len]<<endl;
}

int main() {
    best_cut(10);
    return 0;
}