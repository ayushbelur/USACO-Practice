#include <bits/stdc++.h>
using namespace std;

int find(int n, vector<int>& parent) {
    if (parent[n] == n) {
        return n;
    }
    else {
        return parent[n] = find(parent[n], parent);
    }
}

void unite(int x, int y, vector<int>& parent) {
    int root1 = find(x, parent);
    int root2 = find(y, parent);
    if (root1 != root2) {
        parent[root1] = root2;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> parent(500001);
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            unite(u, v, parent);
        }
        if (find(1, parent) == find(n, parent)) {
            cout << 0 << "\n";
        }
        else {
            long long answer = 1e16;
            vector<vector<int>> components(500001);
            for (int i = 1; i <= n; i++) {
                components[find(i, parent)].push_back(i);
            }
            vector<long long> first_cost(500001, 1e16);
            vector<long long> last_cost(500001, 1e16);
            for (int i = 1; i <= n; i++) {
                int id = find(i, parent);
                auto it1 = lower_bound(components[find(1, parent)].begin(), components[find(1, parent)].end(), i);
                if (it1 != components[find(1, parent)].end()) {
                    long long diff = *it1 - i;
                    first_cost[id] = min(first_cost[id], diff * diff);
                }
                if (it1 != components[find(1, parent)].begin()) {
                    long long diff = i - *prev(it1);
                    first_cost[id] = min(first_cost[id], diff * diff);
                }
                auto it2 = lower_bound(components[find(n, parent)].begin(), components[find(n, parent)].end(), i);
                if (it2 != components[find(n, parent)].end()) {
                    long long diff = *it2 - i;
                    last_cost[id] = min(last_cost[id], diff * diff);
                }
                if (it2 != components[find(n, parent)].begin()) {
                    long long diff = i - *prev(it2);
                    last_cost[id] = min(last_cost[id], diff * diff);
                }
            }
            for (int x = 1; x <= n; x++) {
                answer = min(answer, first_cost[x] + last_cost[x]);
            }
            cout << answer << "\n";
        }
    }
}  
