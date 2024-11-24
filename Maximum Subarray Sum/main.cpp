#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxSubArray(vector<int>& nums) {
    long long currentSum = 0, maxSum = nums[0];
    for (int num : nums) {
        currentSum = max((long long)num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) cin >> num;
    cout << maxSubArray(nums) << endl;
    return 0;
}
