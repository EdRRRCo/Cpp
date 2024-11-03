#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  

using namespace std;

int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;

    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int maxSubArraySum(const vector<int>& arr, int left, int right) {
    if (left == right) return arr[left];

    int mid = (left + right) / 2;

    int left_max = maxSubArraySum(arr, left, mid);
    int right_max = maxSubArraySum(arr, mid + 1, right);
    int cross_max = maxCrossingSum(arr, left, mid, right);

    return max({ left_max, right_max, cross_max });
}

int main() {
    vector<int> arr = { 4, -3, 5, -2, -1, 2, 6, -2 };
    int result = maxSubArraySum(arr, 0, arr.size() - 1);
    cout << "分治算法求得的最大子段和为: " << result << endl;
    return 0;
}
