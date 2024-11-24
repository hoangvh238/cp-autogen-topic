#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int n;
    vector<int> nums;
    long long maxSum;

    void InputFormat() {
        LINE(n);
        LINE(nums % SIZE(n));
    }

    void OutputFormat() {
        LINE(maxSum);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= n && n <= 100000);
        CONS(eachElementInRange(nums, -1'000'000'000, 1'000'000'000));
    }

private:
    bool eachElementInRange(const vector<int>& arr, int lo, int hi) {
        for (int x : arr) {
            if (x < lo || x > hi) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({"5", "-2 1 -3 4 -1"});
        Output({"4"});
    }

    void BeforeTestCase() {
        nums.clear();
    }

    void TestCases() {
        CASE(n = 5, nums = {-2, 1, -3, 4, -1});
        CASE(n = 100000, nums = generateRandomArray(100000, -1'000'000'000, 1'000'000'000));
    }

private:
    vector<int> generateRandomArray(int size, int minValue, int maxValue) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) arr[i] = rnd.nextInt(minValue, maxValue);
        return arr;
    }
};
