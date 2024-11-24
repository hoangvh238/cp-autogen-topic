#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> A;
    int result;

    void InputFormat() {
        LINE(N);
        LINE(A % SIZE(N));
    }

    void OutputFormat() {
        LINE(result);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100000);
        CONS(eachElementInRange(A, -1000000, 1000000));
    }

private:
    bool eachElementInRange(const vector<int>& v, int lo, int hi) {
        return all_of(v.begin(), v.end(), [&](int x) { return lo <= x && x <= hi; });
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "7",
            "1 3 2 1 3 1 2"
        });
        Output({
            "1"
        });
    }

    void TestCases() {
        CASE(N = 5, A = {1, 2, 3, 4, 5});
        CASE(N = 5, A = {1, 1, 1, 1, 1});
        CASE(N = 5, A = {-1000000, -1000000, 0, 1, 1});
        CASE(N = 100000, randomArray(N, -1000000, 1000000));
        CASE(N = 100000, largeSingleValue(N, 12345));
    }

private:
    void randomArray(int n, int lo, int hi) {
        A.clear();
        for (int i = 0; i < n; i++) {
            A.push_back(rnd.nextInt(lo, hi));
        }
    }

    void largeSingleValue(int n, int value) {
        A.clear();
        for (int i = 0; i < n; i++) {
            A.push_back(value);
        }
    }
};
