#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum(const vector<int>& arr) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    vector<int> arr = { 4, -3, 5, -2, -1, 2, 6, -2 };
    int result = maxSubArraySum(arr);
    cout << "动态规划算法求得的最大子段和为: " << result << endl;
    return 0;
}
