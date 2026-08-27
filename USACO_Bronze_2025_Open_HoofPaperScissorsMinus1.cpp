#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> outcomes(n + 2, vector<char> (n + 2, 0)); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> outcomes[i][j];
            if (outcomes[i][j] != 'D') {
                if (outcomes[i][j] == 'W') {
                    outcomes[j][i] = 'L';
                } 
                else {
                    outcomes[j][i] = 'W';
                }
            }
        }
    }
    vector<pair<int, int>> combos(m + 2);
    for (int i = 1; i <= m; i++) {
        cin >> combos[i].first >> combos[i].second;
    }
    for (int x = 1; x <= m; x++) {
        int s1 = combos[x].first;
        int s2 = combos[x].second;
        int wins = 0;
        for (int i = 1; i <= n; i++) {
            if ((outcomes[i][s1] == 'W') && (outcomes[i][s2] == 'W')) {
                wins += 1;
            }
        }
        int bessie_wins = 0;
        for (int i = 1; i <= n; i++) {
            if ((outcomes[i][s1] == 'W') && (outcomes[i][s2] == 'W')) {
                bessie_wins += n;
            } 
            else {
                bessie_wins += wins;
            }
        }
        cout << bessie_wins << "\n";
    }   
} 