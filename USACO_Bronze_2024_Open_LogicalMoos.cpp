#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<string> initial(n + 3);
    initial[0] = "or";
    initial[n + 2] = "or";
    vector<pair<int, int>> starts;
    vector<pair<int, int>> ends;
    starts.push_back({2, 0});
    vector<bool> is_true(n + 3, true);
    vector<int> pref(n + 3, 0);
    int index = 0;
    for (int i = 2; i <= n + 1; i++) {
        pref[i] = pref[i - 1];
        string keyword;
        cin >> keyword;
        initial[i] = keyword;
        if (initial[i] == "or") {
            ends.push_back({i - 1, index});
            index += 1;
            starts.push_back({i + 1, index});
        }
        else {
            if (keyword == "false") {
                is_true[index] = false;
                pref[i] += 1;  
            }
        }
    }
    ends.push_back({n + 1, index});
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    int left = -1;
    int right = -1;
    for (int i = 0; i <= index; i++) {
        if (is_true[i]) {
            if (left == -1) {
                left = i;
            }   
            right = i;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        string b;
        cin >> l >> r;
        l += 1;
        r += 1;
        cin >> b;
        int index1 = lower_bound(starts.begin(), starts.end(), make_pair(l, int(2e9))) - starts.begin() - 1;
        int index2 = lower_bound(ends.begin(), ends.end(), make_pair(r, -1)) - ends.begin();
        bool external_true = false;
        if (left != -1) {
            if (left < index1 || right > index2) {
                external_true = true;
            }
        }

        if (external_true) {
            if (b == "true") {
                cout << "Y";
            }
            else {
                cout << "N";
            }
        }
        else {
            if (pref[l - 1] - pref[starts[index1].first - 1] > 0 || pref[ends[index2].first] - pref[r] > 0) {
                if (b == "false") {
                    cout << "Y";
                }
                else {
                    cout << "N";
                }
            }
            else {
                cout << "Y";
            }
        }
    }
}