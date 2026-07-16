#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> start_counts(5001);
    vector<long long> end_counts(5001);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        start_counts[start] += 1;
        end_counts[end] += 1;
    }
    vector<long long> differences(10002, 0);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            differences[i + j] += start_counts[i] * start_counts[j];
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            differences[i + j + 1] -= end_counts[i] * end_counts[j];
        }
    }
    long long ans = 0;
    for (int k = 0; k <= 2 * m; k++) {
        ans += differences[k];
        cout << ans << "\n";
    }
}