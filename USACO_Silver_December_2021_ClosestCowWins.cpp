#include <bits/stdc++.h>
using namespace std;

long long sliding_window(int width, int num_patches, const vector<pair<int, long long>>& patches) {
    int l = 0;
    long long window_sum = 0;
    long long total_max = 0;
    for (int r = 0; r < num_patches; r++) {
        window_sum += patches[r].second;
        while ((patches[r].first - patches[l].first) * 2 >= width) {
            window_sum -= patches[l].second;
            l += 1;
        }
        total_max = max(window_sum, total_max);
    }
    return total_max;
}

 
int main() {
    int k, m, n;
    cin >> k >> m >> n;
    vector<pair<int, long long>> patches;
    for (int i = 0; i < k; i++) {
        int p, t;
        cin >> p >> t;
        patches.push_back({p, t});
    }
    sort(patches.begin(), patches.end());
    vector<int> bad_cows;
    for (int i = 0; i < m; i++) {
        int f;
        cin >> f;
        bad_cows.push_back(f);
    }
    vector<long long> rewards;
    sort(bad_cows.begin(), bad_cows.end());
    int idx = 0;
    long long left_total = 0;
    while (idx < k && patches[idx].first < bad_cows[0]) {
        left_total += patches[idx].second;
        idx += 1;
    }
    rewards.push_back(left_total);
    for (int i = 0; i < m - 1; i++) {
        long long total = 0;
        int l = bad_cows[i];
        int r = bad_cows[i + 1];
        int w = r - l;
        vector<pair<int, long long>> interval_patches;
        int num = 0;
        while (idx < k && patches[idx].first < r) {
            total += patches[idx].second;
            interval_patches.push_back({patches[idx].first, patches[idx].second});
            idx += 1;
            num += 1;
        }
        long long reward = sliding_window(w, num, interval_patches);
        rewards.push_back(reward);
        rewards.push_back(total - reward);
    }
    long long right_total = 0;
    while (idx < k) {
        right_total += patches[idx].second;
        idx += 1;
    }
    rewards.push_back(right_total);
    sort(rewards.begin(), rewards.end());
    reverse(rewards.begin(), rewards.end());
    long long sum = 0;
    int limit = min(n, (int)rewards.size());
    for (int i = 0; i < limit; i++) {
        sum += rewards[i];
    }
    cout << sum;
}