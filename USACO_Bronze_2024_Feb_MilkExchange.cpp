#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<char> directions(n);
    bool is_right = true;
    bool is_left = true;
    for (int i = 0; i < n; i++) {
        cin >> directions[i];
        if (directions[i] == 'R' && is_left == true) {
            is_left = false;
        }
        if (directions[i] == 'L' && is_right == true) {
            is_right = false;
        }
    }
    vector<long long> capacities(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> capacities[i];
        total += capacities[i];
    }
    if (is_right || is_left) {
        cout << total;
        return 0;
    }
    vector<pair<long long, long long>> components;
    long long first_lefts = 0;
    long long index = 0;
    while (directions[index] == 'L') {
        first_lefts += capacities[index];
        index += 1;
    }
    long long curr_rights = capacities[index];
    long long curr_lefts = 0;
    for (int i = index + 1; i < n; i++) {
        if (directions[i] == 'R') {
            if (directions[i - 1] == 'R') {
                curr_rights += capacities[i];
            }
            else {
                components.push_back({curr_rights, curr_lefts});
                curr_rights = capacities[i];
                curr_lefts = 0;
            }
        }
        if (directions[i] == 'L') {
            if (directions[i - 1] == 'R') {
                curr_rights -= capacities[i - 1];
            }
            else {
                curr_lefts += capacities[i];
            }
        }
    }
    if (curr_lefts == 0) {
        if (first_lefts > 0) {
            curr_rights -= capacities[n - 1];
            first_lefts -= capacities[0];
            components.push_back({curr_rights, first_lefts});
        }
        else {
            if (components.empty()) {
                components.push_back({curr_rights, 0});
            }
            else {
                components[0].first += curr_rights;
            }
        }
    }
    else {
        curr_lefts += first_lefts;
        components.push_back({curr_rights, curr_lefts});
    }
    long long total_milk = total;
    long long subtracted = 0;
    for (int i = 0; i < components.size(); i++) {
        long long sum_rights = components[i].first;
        long long sum_lefts = components[i].second;
        long long left_sum = 0;
        long long right_sum = 0;
        left_sum = min(m, sum_lefts);
        right_sum = min(m, sum_rights);
        subtracted += left_sum;
        subtracted += right_sum;
    }
    total_milk -= subtracted;
    cout << total_milk;
}