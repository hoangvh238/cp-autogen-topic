#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> nums;
    vector<vector<int>> result;

    void InputFormat() {
        LINE(N);
        LINE(nums % SIZE(N));
    }

    void OutputFormat() {
        LINES(result);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(3 <= N && N <= 3000);
        CONS(eachElementBetween(nums, -100000, 100000));
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({"6", "-1 0 1 2 -1 -4"});
        Output({
            "-1 -1 2",
            "-1 0 1"
        });
    }

    void SampleTestCase2() {
        Input({"3", "0 1 1"});
        Output({});
    }

    void SampleTestCase3() {
        Input({"3", "0 0 0"});
        Output({
            "0 0 0"
        });
    }

    void BeforeTestCase() {
        nums.clear();
        result.clear();
    }

    void TestGroup1() {
        CASE(N = 6, nums = {-1, 0, 1, 2, -1, -4});
        CASE(N = 3, nums = {0, 1, 1});
        CASE(N = 3, nums = {0, 0, 0});
    }

    void TestGroup2() {
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(3, 10), generateRandomArray(N, nums, -10, 10));
        }
    }

    void TestGroup3() {
        CASE(N = 3000, generateRandomArray(N, nums, -100000, 100000));
    }

    void TestGroup4() {
        CASE(N = 3000, generateAllZerosArray(N, nums));
    }

    void TestGroup5() {
        CASE(N = 3000, generateBalancedArray(N, nums, -100000, 100000));
    }

private:
    void generateRandomArray(int n, vector<int>& arr, int lo, int hi) {
        for (int i = 0; i < n; i++) {
            arr.push_back(rnd.nextInt(lo, hi));
        }
    }

    void generateAllZerosArray(int n, vector<int>& arr) {
        arr.assign(n, 0);
    }

    void generateBalancedArray(int n, vector<int>& arr, int lo, int hi) {
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            arr.push_back(rnd.nextInt(lo, -1));
        }
        for (int i = 0; i < half; i++) {
            arr.push_back(rnd.nextInt(1, hi));
        }
        if (n % 2 == 1) {
            arr.push_back(0);
        }
        rnd.shuffle(arr.begin(), arr.end());
    }
};
