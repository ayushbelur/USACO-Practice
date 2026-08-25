#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> cows(n + 1);
    vector<int> range(n + 1);
    int pos_g = -1;
    int pos_h = -1;
    int last_g = -1;
    int last_h = -1;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i];
        if (cows[i] == 'G') {
            if (pos_g == -1) {
                pos_g = i;
            }
            last_g = i;
        }
        else {
            if (pos_h == -1) {
                pos_h = i;
            }
            last_h = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> range[i];
    }
    int real_g = -1;
    int real_h = -1;
    if (range[pos_g] >= last_g) {
        real_g = pos_g;
    }
    if (range[pos_h] >= last_h) {
        real_h = pos_h;
    }
    long long total = 0;
    if (real_g != -1 && real_h != -1) {
        total += 1;
    }
    if (real_g != -1) {
        for (int i = 1; i <= real_g; i++) {
            if (cows[i] == 'H') {
                if (range[i] >= real_g) {
                    total += 1;
                }
            }
        }
    }
    if (real_h != -1) {
        for (int i = 1; i <= real_h; i++) {
            if (cows[i] == 'G') {
                if (range[i] >= real_h) {
                    total += 1;
                }
            }
        }
    }
    cout << total;
}