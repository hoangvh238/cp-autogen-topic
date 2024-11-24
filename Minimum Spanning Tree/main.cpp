#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank[pu] == rank[pv]) rank[pu]++;
        return true;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    long long totalWeight = 0;
    for (const auto& [w, u, v] : edges) {
        if (uf.unite(u, v)) totalWeight += w;
    }

    cout << totalWeight << endl;
    return 0;
}
