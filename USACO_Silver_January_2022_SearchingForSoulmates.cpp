#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int x = 0; x < n; x++) {
        long long cow1, cow2;
        cin >> cow1 >> cow2;
        long long curr1 = cow1;
        long long curr2 = cow2;
        vector<long long> cow1_to_1;
        vector<long long> cow2_to_1;
        cow1_to_1.push_back(curr1);
        cow2_to_1.push_back(curr2);
        while (curr1 > 1) {
            if (curr1 % 2 == 0) {
                curr1 = curr1 / 2;
            }
            else {
                curr1 = curr1 + 1;
            }
            cow1_to_1.push_back(curr1);
        }
        while (curr2 > 1) {
            if (curr2 % 2 == 0) {
                curr2 = curr2 / 2;
            }
            else {
                curr2 = curr2 - 1;
            }
            cow2_to_1.push_back(curr2);
        }
        long long min_ops = 1e18;
        for (int i = 0; i < cow1_to_1.size(); i++){
            for (int j = 0; j < cow2_to_1.size(); j++) {
                if (cow1_to_1[i] > cow2_to_1[j]) {
                    continue;
                }
                min_ops = min(min_ops, i + j + (cow2_to_1[j] - cow1_to_1[i]));
            }
        }
        cout << min_ops << "\n";
    }
}
 