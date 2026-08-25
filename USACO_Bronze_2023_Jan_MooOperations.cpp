#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int x = 0; x < q; x++) {
        string str;
        cin >> str;
        if (str.size() < 3) {
            cout << -1 << "\n";
            continue;
        }
        bool possible = false;
        int pre_changes = str.size() - 3;
        int added_changes = 3;
        for (int i = 0; i < str.size() - 2; i++) {
            if (str[i + 1] == 'M') {
                continue;
            }
            else {
                possible = true;
                string curr = "";
                curr.push_back(str[i]);
                curr += str[i + 1];
                curr += str[i + 2];
                if (curr == "MOO") {
                    added_changes = 0;
                    break;
                }
                else if (curr == "OOO" || curr == "MOM") {
                    added_changes = 1;
                }
                else {
                    added_changes = min(added_changes, 2);
                }
            }
        }
        if (possible) {
            cout << pre_changes + added_changes << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}