#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<int> crossings(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> crossings[i];
    }
    bool gr = true;
    string answer = "";
    int spot = 0;
    while (true) {
        if (gr) {
            if (spot < n && crossings[spot] > 0) {
                crossings[spot] -= 1;
                spot += 1;
                answer += 'R';
            }
            else {
                gr = false;
                if (spot == 0 && crossings[0] == 0) {
                    break;
                }
            }
        }
        else {
            if (spot > 0 && (spot == n || crossings[spot] == 0 || crossings[spot - 1] > 1)) {
                crossings[spot - 1] -= 1;
                spot -= 1;
                answer += 'L';
            }
            else {
                gr = true;
                if (spot == 0 && crossings[0] == 0) {
                    break;
                }
            }
        }
    }
    cout << answer;
}
