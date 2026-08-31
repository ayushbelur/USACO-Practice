#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> closings(n + 1);
    vector<int> visits(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> closings[i];
        closings[i] -= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> visits[i];
    }
    vector<int> max_s(n);
    for (int i = 0; i < n; i++) {
        max_s[i] = closings[i] - visits[i];
    }
    sort(max_s.begin(), max_s.end());
    reverse(max_s.begin(), max_s.end());
    for (int i = 0; i < q; i++) {
        int s, v;
        cin >> v >> s;
        int needed_s = max_s[v - 1];
        if (needed_s >= s) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}