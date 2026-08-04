#include <bits/stdc++.h>
using namespace std;

struct Position {
    long long x;
    long long y;
    int num_instructions;
    bool operator < (const Position& other) const {
        if (num_instructions != other.num_instructions) {
            return num_instructions < other.num_instructions;
        }
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

int n;
vector<pair<long long, long long>> instructions(41);
vector<Position> first_half_states;
long long target_x;
long long target_y;
vector<long long> answers(42, 0);

void generate_first_half(int index, long long curr_x, long long curr_y, int ins_taken) {
    if (index == n / 2) {
        first_half_states.push_back({curr_x, curr_y, ins_taken});
        return;
    }
    generate_first_half(index + 1, curr_x, curr_y, ins_taken);
    generate_first_half(index + 1, curr_x + instructions[index].first, curr_y + instructions[index].second, ins_taken + 1);
}

void generate_second_half(int index, long long curr_x, long long curr_y, int ins_taken) {
    if (index == n) {
        long long needed_x = target_x - curr_x;
        long long needed_y = target_y - curr_y;
        for (int first_half_cost = 0; first_half_cost <= n / 2; first_half_cost++) {
            Position target = {needed_x, needed_y, first_half_cost};
            auto range = equal_range(first_half_states.begin(), first_half_states.end(), target);
            answers[ins_taken + first_half_cost] += (range.second - range.first);
        }
        return;
    }
    generate_second_half(index + 1, curr_x, curr_y, ins_taken);
    generate_second_half(index + 1, curr_x + instructions[index].first, curr_y + instructions[index].second, ins_taken + 1);
}


int main() {
    cin >> n;
    cin >> target_x >> target_y;
    for (int i = 0; i < n; i++) {
        cin >> instructions[i].first >> instructions[i].second;
    }
    int half = n / 2;
    generate_first_half(0, 0, 0, 0);
    sort(first_half_states.begin(), first_half_states.end());
    generate_second_half(half, 0, 0, 0);
    for (int k = 1; k <= n; k++) {
        cout << answers[k] << "\n";
    }
}
