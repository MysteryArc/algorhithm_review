/*
 * @FileName   : 基数排序.cpp
 * @Author     : WangHengyu [wanghyuuuuu@163.com]
 * @CreateTime : 2024/01/03 16:44:21
 * 基于计数排序实现基数排序
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void radixSort(vector<int> &nums){
    int maxDigit = 0;
    for(int i = 0; i < nums.size(); i++){
        int digit = floor(log10(abs(nums[i]))) + 1;
        maxDigit = max(maxDigit, digit);
    }
    for(int i = 0; i < maxDigit; i++){
        vector<int> count(10, 0);
        // 计数
        for(int j = 0; j < nums.size(); j++){
            int num = nums[j] / int(pow(10, i)) % 10;
            count[num]++;
        }
        // 根据计数数组计算位置数组(结束位置的后一位)
        for(int j = 1; j < 10; j++){
            count[j] = count[j] + count[j - 1];
        }
        // 创建新数组并插入数据,由于记录的是结束位置的后一位，需要反向插入数据并在插入时将位置减一
        vector<int> res(nums.size());
        for(int j = nums.size() - 1; j >= 0; j--){
            int num = nums[j] / int(pow(10, i)) % 10;
            res[--count[num]] = nums[j];
        }
        // 输出一轮排序结果
        cout<<"第"<<i + 1<<"轮排序结果: ";
        for(int j = 0; j < res.size(); j++){
            cout<<res[j]<<" ";
        }
        cout<<endl;
        nums = res;
    }
}

int main() {
    vector<int> a = {329, 457, 657, 839, 436, 720, 355};
    radixSort(a);
    return 0;
}