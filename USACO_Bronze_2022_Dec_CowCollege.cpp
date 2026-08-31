#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> tuitions(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> tuitions[i];
    }
    sort(tuitions.begin(), tuitions.end());
    reverse(tuitions.begin(), tuitions.end());
    long long best_tuition = -1;
    long long max_money = 0;
    for (int i = n - 1; i >= 0; i--) {
        long long tuition = tuitions.back();
        long long cows = tuitions.size();
        long long money = cows * tuition;
        if (money > max_money) {
            max_money = money;
            best_tuition = tuition;
        }
        tuitions.pop_back();
    }
    cout << max_money << " " << best_tuition;
}