#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;
    long long current_haybales = 0;
    long long haybales_eaten = 0;
    long long prev_day = 1;
    for (int i = 0; i < n; i++) {
        long long day, haybales;
        cin >> day >> haybales;
        long long days_passed = day - prev_day;
        long long eaten = min(current_haybales, days_passed);
        haybales_eaten += eaten;
        if (current_haybales > eaten) {
            current_haybales -= eaten;
        }
        else {
            current_haybales = 0;
        }
        current_haybales += haybales;
        prev_day = day;
    }
    long long final_eaten = min(t - prev_day + 1, current_haybales);
    haybales_eaten += final_eaten;
    cout << haybales_eaten;
}