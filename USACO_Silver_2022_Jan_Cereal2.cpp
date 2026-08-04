#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int cow;
    bool fav;
};

vector<vector<Edge>> adj_list(200001);
vector<int> order;
vector<bool> visited_cereal(200001, false);
vector<bool> visited_cows(200001, false);

vector<int> cycle_cereal(200001, -1);
vector<int> cycle_cows(200001, -1); 
vector<bool> comp_processed(200001, false);

int cycle_start_cereal = -1;
int cycle_start_cow = - 1;

void get_cycles(int node, int edge1) {
    visited_cereal[node] = true;
    for (Edge& edge : adj_list[node]) {
        if (edge.cow == edge1) {
            continue;
        }
        else {
            if (visited_cereal[edge.to]) {
                if (cycle_start_cereal == -1) {
                    if (edge.fav == true) {
                        cycle_start_cereal = edge.to;
                    }
                    else {
                        cycle_start_cereal = node;
                    }
                    cycle_start_cow = edge.cow;
                }
                break;
            }
            else {
                get_cycles(edge.to, edge.cow);
            }
        }
    }
}

void tree_traversal(int node) {
    visited_cereal[node] = true;
    for (Edge& edge : adj_list[node]) {
        if (visited_cows[edge.cow]) {
            continue;
        }
        else {
            if (!visited_cereal[edge.to]) {
                visited_cows[edge.cow] = true;
                order.push_back(edge.cow);  
                tree_traversal(edge.to);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int fav, next_fav;
        cin >> fav >> next_fav;
        adj_list[fav].push_back({next_fav, i, false});
        adj_list[next_fav].push_back({fav, i, true});
    }
    for (int i = 1; i <= m; i++) {
        if (visited_cereal[i]) {
            continue;
        }
        else {
            cycle_start_cereal = -1;
            cycle_start_cow = -1;
            get_cycles(i, -1);
            comp_processed[i] = true;
            cycle_cereal[i] = cycle_start_cereal;
            cycle_cows[i] = cycle_start_cow;
        }
    }
    fill(visited_cereal.begin(), visited_cereal.end(), false);
    for (int i = 1; i <= m; i++) {
        if (!comp_processed[i]) {
            continue;
        }
        if (visited_cereal[i]) {
            continue;
        }
        else {
            if (cycle_cereal[i] != -1) {
                visited_cows[cycle_cows[i]] = true;
                order.push_back(cycle_cows[i]);
                tree_traversal(cycle_cereal[i]);
            }
            else {
                tree_traversal(i);
            }
        }
    }
    int num_hungry = 0;
    vector<int> hungry_cows;
    for (int i = 1; i <= n; i++) {
        if (!visited_cows[i]) {
            hungry_cows.push_back(i);
            num_hungry += 1;
        }
    }
    cout << num_hungry << "\n";
    for (int cow : order) {
        cout << cow << "\n";
    }
    for (int cow : hungry_cows) {
        cout << cow << "\n";
    }
}
