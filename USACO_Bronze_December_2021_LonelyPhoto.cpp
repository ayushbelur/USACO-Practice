#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    string line;
    cin >> line;
    long long lps = 0;
    for (int i = 0; i < n; i++) {
        long long llps = 0;
        if (i > 0 && line[i - 1] != line[i]) {
            llps += 1;
            for (int j = i - 2; j >= 0 && line[j] == line[i - 1]; j--) {
                llps += 1;
            }
        }
        long long lrps = 0;
        if (i + 1 < n && line[i] != line[i + 1]) {
            lrps += 1;
            for (int j = i + 2; j < n && line[j] == line[i + 1]; j++) {
                lrps += 1;
            }
        }
        lps += (lrps * llps);
        if (llps >= 2) {
            lps += llps - 1;
        }
        if (lrps >= 2) {
            lps += lrps - 1;
        }
    }
    cout << lps;
}