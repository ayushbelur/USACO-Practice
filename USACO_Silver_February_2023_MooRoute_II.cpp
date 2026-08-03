#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<long long, pair<long long, long long>>>> adj_list(n + 1);
    for (int i = 0; i < m; i++) {
        long long cj, rj, dj, sj;
        cin >> cj >> rj >> dj >> sj;
        adj_list[cj].push_back({rj, {dj, sj}});
    }
    vector<long long> layovers(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> layovers[i];
    }
    for (int i = 1; i <= n; i++) {
        for (auto &flight : adj_list[i]) {
            flight.first -= layovers[i];
        }
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    queue<pair<long long, pair<long long, long long>>> q;
    vector<long long> times_arrived(n + 2, 1e16);
    times_arrived[1] = 0;
    while (!adj_list[1].empty()) { 
        if (adj_list[1].back().first + layovers[1] >= 0) {
            auto flight = adj_list[1].back();
            adj_list[1].pop_back();
            q.push(flight);
        }
        else {
            break;
        }
    }
    while (!q.empty()) {
        auto curr_flight = q.front();
        q.pop();
        long long depart = curr_flight.first;
        long long new_airport = curr_flight.second.first;
        long long arrive_time = curr_flight.second.second;
        if (arrive_time < times_arrived[new_airport]) {
            times_arrived[new_airport] = arrive_time;
        }
        else {
            continue;
        }
        while (!adj_list[new_airport].empty()) {
            if (adj_list[new_airport].back().first >= arrive_time) {
                auto new_flight = adj_list[new_airport].back();
                adj_list[new_airport].pop_back();
                q.push(new_flight);
            }
            else {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (times_arrived[i] < 1e16) {
            cout << times_arrived[i] << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}