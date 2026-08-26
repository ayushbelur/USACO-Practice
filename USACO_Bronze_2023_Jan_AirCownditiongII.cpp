#include <bits/stdc++.h>
using namespace std;

struct AC {
    int ai, bi, pi, mi;
};

struct Cow {
    int si, ti, ci;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Cow> cows(21);
    vector<AC> acs(11);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].si >> cows[i].ti >> cows[i].ci;
    }
    for (int i = 0; i < m; i++) {
        cin >> acs[i].ai >> acs[i].bi >> acs[i].pi >> acs[i].mi;
    }
    int min_cost = 1e9;
    int limit = (1 << m) - 1;
    for (int mask = 1; mask <= limit; mask++) {
        vector<int> cooling(101, 0);
        int curr_cost = 0;
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                curr_cost += acs[i].mi;
                cooling[acs[i].ai - 1] += acs[i].pi;
                cooling[acs[i].bi] -= acs[i].pi;
            }
        }
        vector<int> stalls(102, 0);
        for (int i = 0; i < 100; i++) {
            if (i == 0) {
                stalls[0] = cooling[0];
            }
            else {
                stalls[i] = stalls[i - 1] + cooling[i];
            }
        }
        bool valid = true;
        for (int x = 0; x < n; x++) {
            for (int i = cows[x].si - 1; i <= cows[x].ti - 1; i++) {
                if (stalls[i] < cows[x].ci) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            min_cost = min(min_cost, curr_cost);
        }
    }
    cout << min_cost;  
}