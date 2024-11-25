#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int target;
    vector<int> nums;
    int result;

    void InputFormat() {
        LINE(target);
        LINE(nums % SIZE(nums.size()));
    }

    void OutputFormat() {
        LINE(result);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= target && target <= 1e9);
        CONS(1 <= nums.size() && nums.size() <= 1e5);
        CONS(eachElementBetween(nums, 1, 1e4));
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
        Input({
            "7",
            "2 3 1 2 4 3"
        });
        Output({
            "2"
        });
    }

    void SampleTestCase2() {
        Input({
            "4",
            "1 4 4"
        });
        Output({
            "1"
        });
    }

    void SampleTestCase3() {
        Input({
            "11",
            "1 1 1 1 1 1 1 1"
        });
        Output({
            "0"
        });
    }

    void BeforeTestCase() {
        nums.clear();
    }

    void TestGroup1() {
        CASE(target = 7, nums = {2, 3, 1, 2, 4, 3});
        CASE(target = 15, nums = {1, 2, 3, 4, 5});
        CASE(target = 50, nums = vector<int>(10, 5));
        CASE(target = 1000, nums = vector<int>(1e5, 1));
        CASE(target = 50000, nums = generateLargeArray(1e5, 1, 1e4));
    }

    void TestGroup2() {
        CASE(target = rnd.nextInt(1, 1e9), nums = generateLargeArray(1e5, 1, 1e4));
        CASE(target = rnd.nextInt(1, 1e9), nums = generateLargeArray(5000, 1, 100));
        CASE(target = rnd.nextInt(1, 1e9), nums = generateEdgeCaseArray(1e5, 1));
        CASE(target = 1, nums = vector<int>(1e5, 1));
        CASE(target = 1e9, nums = vector<int>(1e5, 1e4));
    }

private:
    vector<int> generateLargeArray(int size, int minVal, int maxVal) {
        vector<int> result(size);
        for (int& x : result) {
            x = rnd.nextInt(minVal, maxVal);
        }
        return result;
    }

    vector<int> generateEdgeCaseArray(int size, int value) {
        return vector<int>(size, value);
    }
};
