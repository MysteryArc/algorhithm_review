#include <iostream>
#include <cmath>
using namespace std;

void merge(int nums[], int begin, int end, int mid)
{
    int i = begin;
    int j = mid + 1;
    int res[end];
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (nums[i] < nums[j])
        {
            res[k++] = nums[i++];
        }
        else
            res[k++] = nums[j++];
    }
    while (i <= mid)
    {
        res[k++] = nums[i++];
    }
    while (j <= end)
    {
        res[k++] = nums[j++];
    }
    k = 0;
    for (int p = begin; p <= end; p++)
    {
        nums[p] = res[k++];
    }
}

void divide(int nums[], int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        divide(nums, begin, mid);
        divide(nums, mid + 1, end);
        merge(nums, begin, end, mid);
    }
}

int main()
{
    int a[] = {1, 3, 20, 6, 5, 4};
    int size = sizeof(a) / sizeof(a[0]);
    divide(a, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}