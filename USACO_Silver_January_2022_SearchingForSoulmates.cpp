#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cow1, cow2;
        cin >> cow1 >> cow2;
        int curr1, curr2 = cow1, cow2;
        vector<int> cow1_to_1;
        vector<int> cow2_to_1;
        cow1_to_1.push_back(curr1);
        cow2_to_1.push_back(curr2);
        int size1, size2 = 0;
        while (curr1 != 0) {
            if (curr1 % 2 == 0) {
                curr1 = curr1 / 2;
            }
            else {
                curr1 = curr1 + 1;
            }
            cow1_to_1.push_back(curr1);
            size1 += 1;
        }
        while (curr2 != 0) {
            if (curr2 % 2 == 0) {
                curr2 = curr2 / 2;
            }
            else {
                curr2 = curr2 - 1;
            }
            cow2_to_1.push_back(curr2);
            size2 += 1;
        }
        long long min_ops = 1e18;
        for (int i = 0; i < size1; i++){
            for (int j = 0; j < size2; j++) {
                if (cow1_to_1[i] >= cow2_to_1[j]) {
                    break;
                }
                min_ops = min(min_ops, i + j + (cow2_to_1[j] - cow1_to_1[i]));
            }
        }
        cout << min_ops << "\n";
    }
}