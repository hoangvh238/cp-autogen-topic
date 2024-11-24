#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    unordered_map<int, int> freq;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }

    int maxFreq = 0, result = INT_MAX;
    for (const auto& [num, count] : freq) {
        if (count > maxFreq || (count == maxFreq && num < result)) {
            maxFreq = count;
            result = num;
        }
    }

    cout << result << endl;
    return 0;
}
