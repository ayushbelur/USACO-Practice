#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        string s;
        cin >> s;
        if (s.back() == '0') {
            cout << "E" << "\n";
        }
        else {
            cout << "B" << "\n";
        }
    }
}