#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n + 1);
    vector<long long> freq(n + 1, 0);
    vector<long long> pref(n + 1, 0);
    vector<bool> seen(1000001, false);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0) {
            pref[i] = 0;
            if (!seen[arr[i]]) {
                pref[i] += 1;
                seen[arr[i]] = true;
            }
        }
        else {
            pref[i] = pref[i - 1];
            if (!seen[arr[i]]) {
                pref[i] += 1;
                seen[arr[i]] = true;
            }
        }
    }
    long long moos = 0;
    for (int i = n - 1; i >= 0; i--) {
        freq[arr[i]] += 1;
        if (freq[arr[i]] == 2) {
            moos += pref[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] >= 3) {
            moos -= 1;
            freq[arr[i]] = 0;
        }
    }
    cout << moos;
}