#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, sum = 0, minLength = INT_MAX;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];

        while (sum >= target) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }

    return minLength == INT_MAX ? 0 : minLength;
}

int main() {
    int target, n;
    cin >> target;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}
