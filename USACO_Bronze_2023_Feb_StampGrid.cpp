#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<char>> grid(n + 2, vector<char> (n + 2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> grid[i][j];
            }
        }
        int k;
        cin >> k;
        vector<vector<char>> stamp(k + 1, vector<char> (k + 1));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                cin >> stamp[i][j];
            }
        }
        vector<vector<char>> new_grid(n + 2, vector<char> (n + 2, '.'));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i + k - 1 > n || j + k - 1 > n) {
                    continue;
                }
                else {
                    vector<vector<char>> new_stamp(k + 1, vector<char> (k + 1));
                    for (int it = 1; it <= 4; it++) {
                        for (int x = 1; x <= k; x++) {
                            for (int y = 1; y <= k; y++) {
                                new_stamp[y][k - x + 1] = stamp[x][y]; 
                            }
                        }
                        stamp = new_stamp;
                        vector<vector<char>> temp_grid(n + 2, vector<char> (n + 2));
                        temp_grid = new_grid;
                        bool stamp_it = true;
                        for (int x = 1; x <= k; x++) {
                            for (int y = 1; y <= k; y++) {
                                if (new_stamp[x][y] == '*') {
                                    temp_grid[i + x - 1][j + y - 1] = new_stamp[x][y];
                                }
                                if (grid[i + x - 1][j + y - 1] == '.' && new_stamp[x][y] == '*') {
                                    stamp_it = false;
                                }
                            }
                        }
                        if (stamp_it) {
                            new_grid = temp_grid;
                        }
                    }
                }
            }
        }
        bool possible = true;
        for (int i = 1; i <= n; i++) {
            if (possible) {
                for (int j = 1; j <= n; j++) {
                    if (new_grid[i][j] != grid[i][j]) {
                        possible = false;
                        break;
                    }
                }
            }
            else {
                break;
            }
        }
        if (possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
} 