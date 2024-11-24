#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int m, n;
    vector<int> nums1, nums2;
    double median;

    void InputFormat() {
        LINE(m, n);
        LINE(nums1 % SIZE(m));
        LINE(nums2 % SIZE(n));
    }

    void OutputFormat() {
        LINE(median);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(0 <= m && m <= 1000);
        CONS(0 <= n && n <= 1000);
        CONS(1 <= m + n && m + n <= 2000);
        CONS(isSorted(nums1));
        CONS(isSorted(nums2));
        CONS(eachElementInRange(nums1, -1'000'000, 1'000'000));
        CONS(eachElementInRange(nums2, -1'000'000, 1'000'000));
    }

private:
    bool isSorted(const vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    }

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
        Input({"2 1", "1 3", "2"});
        Output({"2.00000"});
    }

    void SampleTestCase2() {
        Input({"2 2", "1 2", "3 4"});
        Output({"2.50000"});
    }

    void BeforeTestCase() {
        nums1.clear();
        nums2.clear();
    }

    void TestCases() {
        CASE(m = 0, n = 5, nums1 = {}, nums2 = generateSortedArray(5, -1'000'000, 1'000'000));
        CASE(m = 2, n = 2, nums1 = {1, 2}, nums2 = {3, 4});
        CASE(m = 1000, n = 1000, nums1 = generateSortedArray(1000, -1'000'000, 0), nums2 = generateSortedArray(1000, 1, 1'000'000));
    }

private:
    vector<int> generateSortedArray(int size, int minValue, int maxValue) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) arr[i] = rnd.nextInt(minValue, maxValue);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
