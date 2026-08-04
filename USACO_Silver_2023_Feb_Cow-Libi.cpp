#include <bits/stdc++.h>
using namespace std;

int main() {
    int g, n;
    cin >> g >> n;
    vector<vector<long long>> grazings(g);
    for (int i = 0; i < g; i++) {
        long long x, y, time;
        cin >> x >> y >> time;
        grazings[i].push_back(time);
        grazings[i].push_back(x);
        grazings[i].push_back(y);
    }
    sort(grazings.begin(), grazings.end());
    vector<vector<long long>> alibis(n);
    for (int i = 0; i < n; i++) {
        long long x, y, time;
        cin >> x >> y >> time;
        alibis[i].push_back(time);
        alibis[i].push_back(x);
        alibis[i].push_back(y);
    }
    int innocent_cows = 0;
    for (int i = 0; i < n; i++) {
        long long alibi_time = alibis[i][0];
        long long alibi_x = alibis[i][1];
        long long alibi_y = alibis[i][2];
        auto it = lower_bound(grazings.begin(), grazings.end(), vector<long long> {alibi_time, -1000000001, -1000000001});
        long long after_time = -1;
        long long after_x;
        long long after_y;
        if (it != grazings.end()) {
            vector<long long> after = *it;
            after_time = after[0];
            after_x = after[1];
            after_y = after[2];
        }
        long long before_time = -1;
        long long before_x;
        long long before_y;
        if (it != grazings.begin()) {
            it--;
            vector<long long> before = *it;
            before_time = before[0];
            before_x = before[1];
            before_y = before[2];
        }
        if (before_time == -1) {
            if ((after_x - alibi_x) * (after_x - alibi_x) + (after_y - alibi_y) * (after_y - alibi_y) > ((after_time - alibi_time) * (after_time - alibi_time))) {
                innocent_cows += 1;
            }
        }
        else if (after_time == -1) {
            if ((before_x - alibi_x) * (before_x - alibi_x) + (before_y - alibi_y) * (before_y - alibi_y) > ((alibi_time - before_time) * (alibi_time - before_time))) {
                innocent_cows += 1;
            }
        }
        else {
            if ((after_x - alibi_x) * (after_x - alibi_x) + (after_y - alibi_y) * (after_y - alibi_y) > ((after_time - alibi_time) * (after_time - alibi_time)) || (before_x - alibi_x) * (before_x - alibi_x) + (before_y - alibi_y) * (before_y - alibi_y) > ((alibi_time - before_time) * (alibi_time - before_time))) {
                innocent_cows += 1;
            }
        }
    }
    cout << innocent_cows;
}