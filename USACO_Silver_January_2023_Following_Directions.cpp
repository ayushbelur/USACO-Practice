#include <bits/stdc++.h>
using namespace std;

int field_counts[1502][1502];

int main() {
    vector<string> directions(1501);
    vector<int> bottom_costs(1501);
    vector<int> right_costs(1501);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field_counts[i][j] = 1;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        if (i < n) {
            string s;
            cin >> s;
            int cost;
            cin >> cost;
            directions[i] = s;
            right_costs[i] = cost;
        }
        else {
            for (int i = 0; i < n; i++) {
                cin >> bottom_costs[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (directions[i][j] == 'R') {
                field_counts[i][j + 1] += field_counts[i][j];
            }
            else {
                field_counts[i + 1][j] += field_counts[i][j];
            }
        }
    }
    long long total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += field_counts[i][n] * right_costs[i];
        total_cost += field_counts[n][i] * bottom_costs[i];
    }
    cout << total_cost << "\n";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        int subtract = field_counts[x][y];
        int add = subtract;
        int curr_x = x, curr_y = y;
        if (directions[curr_x][curr_y] == 'R') {
            curr_y += 1;
        }
        else {
            curr_x += 1;
        }
        while (curr_x < n && curr_y < n) {
            field_counts[curr_x][curr_y] -= subtract;
            if (directions[curr_x][curr_y] == 'R') {
                curr_y += 1;
            }
            else {
                curr_x += 1;
            }
        }
        field_counts[curr_x][curr_y] -= subtract;
        if (curr_x == n) {
            total_cost -= subtract * bottom_costs[curr_y];
        }
        else {
            total_cost -= subtract * right_costs[curr_x];
        }
        if (directions[x][y] == 'R') {
            directions[x][y] = 'D';
        }
        else {
            directions[x][y] = 'R';
        }
        curr_x = x;
        curr_y = y;
        if (directions[curr_x][curr_y] == 'R') {
            curr_y += 1;
        }
        else {
            curr_x += 1;
        }
        while (curr_x < n && curr_y < n) {
            field_counts[curr_x][curr_y] += add;
            if (directions[curr_x][curr_y] == 'R') {
                curr_y += 1;
            }
            else {
                curr_x += 1;
            }
        }
        field_counts[curr_x][curr_y] += add;
        if (curr_x == n) {
            total_cost += add * bottom_costs[curr_y];
        }
        else {
            total_cost += add * right_costs[curr_x];
        }
        cout << total_cost << "\n";
    }
}