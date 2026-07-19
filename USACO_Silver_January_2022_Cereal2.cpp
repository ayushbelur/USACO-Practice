#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int fav, next_fav;
};

vector<int> parents(200001);
vector<Cow> cows(200001);
vector<bool> visited(200001);
vector<vector<int>> components(200001);

int find(int i) {
    if (parents[i] == i) {
        return i;
    }
    else {
        return parents[i] = find(parents[i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 200001; i++) {
        parents[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> cows[i].fav >> cows[i].next_fav;
    }
}
