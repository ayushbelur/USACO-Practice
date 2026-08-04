#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> wishlists(502);
vector<vector<int>> adj_list(502);

vector<int> visited(502, false);

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        bool add = true;
        for (int j = 1; j <= n; j++) {
            int gift;
            cin >> gift;
            wishlists[i].push_back(gift);
            if (gift == i) {
                add = false;
            }
            if (add) {
                adj_list[i].push_back(gift);
            }
        }
    }
    vector<vector<bool>> connected(502, vector<bool> (502, false));
    for (int i = 1; i <= n; i++) {
        connected[i][i] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj_list[i]) {
            connected[i][neighbor] = true;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (connected[i][k] && connected[k][j]) {
                    connected[i][j] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int gift : wishlists[i]) {
            if (connected[gift][i]) {
                cout << gift << "\n";
                break;
            }
        }
    }
}
