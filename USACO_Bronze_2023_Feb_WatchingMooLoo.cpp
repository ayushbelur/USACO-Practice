#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long money_spent = 0;
    long long last_day = -1e16;
    for (int i = 0; i < n; i++) {
        long long day;
        cin >> day;
        long long diff = day - last_day;
        if (diff <= k) {
            money_spent += diff;
        }
        else {
            money_spent += k + 1;
        }
        last_day = day;
    }
    cout << money_spent;
}