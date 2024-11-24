#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, M;
    vector<tuple<int, int, int>> edges;
    long long minWeightSum;

    void InputFormat() {
        LINE(N, M);
        LINES(edges) % SIZE(M);
    }

    void OutputFormat() {
        LINE(minWeightSum);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(2 <= N && N <= 100000);
        CONS(N - 1 <= M && M <= 100000);
        CONS(eachEdgeValid(edges, N));
    }

private:
    bool eachEdgeValid(const vector<tuple<int, int, int>>& edges, int n) {
        for (auto [u, v, w] : edges) {
            if (!(0 <= u && u < n && 0 <= v && v < n && 1 <= w && w <= 1000)) return false;
            if (u == v) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3 3",
            "0 1 2",
            "1 2 3",
            "2 0 4"
        });
        Output({
            "5"
        });
    }

    void BeforeTestCase() {
        edges.clear();
    }

    void TestCases() {
        CASE(N = 5, M = 10, edges = generateCompleteGraph(N, 1, 10));
    }

private:
    vector<tuple<int, int, int>> generateCompleteGraph(int n, int minWeight, int maxWeight) {
        vector<tuple<int, int, int>> result;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                result.emplace_back(u, v, rnd.nextInt(minWeight, maxWeight));
            }
        }
        rnd.shuffle(result.begin(), result.end());
        return result;
    }
};
