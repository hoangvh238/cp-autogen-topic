#include "tcframe/spec.hpp"
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    vector<int> nums;
    vector<vector<int>> res;

    void InputFormat() {
        LINE(nums);
    }

    void OutputFormat() {
        LINES(res);
    }

    void Constraints() {
        CONS(3 <= nums.size() && nums.size() <= 3000);
        CONS(eachElementInRange(nums, -100000, 100000));
    }

private:
    bool eachElementInRange(const vector<int>& v, int lo, int hi) {
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
        Input({"-1 0 1 2 -1 -4"});
        Output({"-1 -1 2", "-1 0 1"});
    }

    void SampleTestCase2() {
        Input({"0 1 1"});
        Output({});
    }

    void SampleTestCase3() {
        Input({"0 0 0"});
        Output({"0 0 0"});
    }

    void TestCases() {
        CASE(nums = {-1, 0, 1, 2, -1, -4});
        CASE(nums = {0, 1, 1});
        CASE(nums = {0, 0, 0});
        CASE(nums = {-100000, -100000, 200000});
        CASE(nums = {1, 2, -3, 4, 5, -6});
        CASE(nums = {0, 0, 0, 0, 0});
        CASE(nums = {-1, -1, 2, 2, 0, 0});
        CASE(nums = {3, -3, 0, 1, -1, -2, 2});
        CASE(nums = {100000, -50000, -50000});
        CASE(nums = generateArray(3000, -100000, 100000));
        CASE(nums = generateArray(3000, -5, 5));
        CASE(nums = generateArray(3, -100000, 100000));
        CASE(nums = generateArray(100, -1000, 1000));
        CASE(nums = generateArray(3000, -100000, 0));
        CASE(nums = generateArray(3000, 0, 100000));
        CASE(nums = generateArray(3000, -10, 10));
        CASE(nums = {0, 0, 1, -1, 2, -2});
        CASE(nums = {-1, 0, 1});
        CASE(nums = {2, -1, -1, 1});
        CASE(nums = {1, -1, 0, 0, 0});
    }

private:
    vector<int> generateArray(int size, int lo, int hi) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = rnd.nextInt(lo, hi);
        }
        return arr;
    }
};