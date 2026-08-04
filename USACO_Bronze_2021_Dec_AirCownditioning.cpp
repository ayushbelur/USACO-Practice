#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> start(n + 2);
    vector<int> end(n + 2);
    vector<int> needed(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> start[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> end[i];
    }
    for (int i = 1; i <= n; i++) {
        needed[i] = end[i] - start[i];
    }
    int min_commands = 0;
    for (int i = 0; i <= n; i++) {
        min_commands += abs(needed[i + 1] - needed[i]);
    }
    min_commands /= 2;
    cout << min_commands;
}
