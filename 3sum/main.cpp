#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) left++; // Skip duplicates
                while (left < right && nums[right] == nums[right + 1]) right--; // Skip duplicates
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = threeSum(nums);

    for (const auto& triplet : result) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
}
