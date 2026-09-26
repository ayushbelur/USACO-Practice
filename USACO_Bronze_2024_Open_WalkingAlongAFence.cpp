#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001];

int main() {
    int n, p;
    cin >> n >> p;
    int distance = 0;
    int first_x, first_y;
    cin >> first_x >> first_y;
    int before_x = first_x;
    int before_y = first_y;
    for (int i = 1; i < p; i++) {
        int x, y;
        cin >> x >> y;
        if (x == before_x) {
            if (before_y < y) {
                for (int j = before_y; j < y; j++) {
                    grid[x][j] = distance;
                    distance += 1;
                }
            }
            else if (before_y > y) {
                for (int j = before_y; j > y; j--) {
                    grid[x][j] = distance;
                    distance += 1;
                }
            }
        }
        if (y == before_y) {
            if (before_x < x) {
                for (int j = before_x; j < x; j++) {
                    grid[j][y] = distance;
                    distance += 1;
                }
            }
            else if (before_x > x) {
                for (int j = before_x; j > x; j--) {
                    grid[j][y] = distance;
                    distance += 1;
                }
            }
        }
        before_x = x;
        before_y = y;
    }
    if (before_x == first_x) {
        if (before_y < first_y) {
            for (int j = before_y; j < first_y; j++) {
                grid[first_x][j] = distance;
                distance += 1;
            }
        }
        else if (before_y > first_y) {
            for (int j = before_y; j > first_y; j--) {
                grid[first_x][j] = distance;
                distance += 1;
            }
        }
    }
    else if (before_y == first_y) {
        if (before_x < first_x) {
            for (int j = before_x; j < first_x; j++) {
                grid[j][first_y] = distance;
                distance += 1;
            }
        }
        else if (before_x > first_x) {
            for (int j = before_x; j > first_x; j--) {
                grid[j][first_y] = distance;
                distance += 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int distance1 = grid[x1][y1];
        int distance2 = grid[x2][y2];
        int option1 = abs(distance2 - distance1);
        int option2 = distance - option1;       
        cout << min(option1, option2) << "\n";
    }
}