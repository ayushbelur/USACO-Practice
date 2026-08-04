#include <bits/stdc++.h>
using namespace std;

bool check(long long orders[101][3], long long cost, long long c_time, long long m_time, int n) {
    long long high_bound = cost;
    if (c_time - 1 < high_bound) {
        high_bound = c_time - 1;
    }
    long long low_bound = 0;
    if (cost - m_time + 1 > low_bound) {
        low_bound = cost - m_time + 1;
    }
    for (int i = 0; i < n; i++) {
        long long c_order = orders[i][0];
        long long m_order = orders[i][1];
        long long max_wait = orders[i][2];
        long long time_left = (max_wait - (c_order * c_time)) - ((m_order * m_time) - (m_order * cost)); 
        if (m_order - c_order == 0) {
            if (time_left < 0) {
                return false;
            }
        } 
        else if (m_order - c_order > 0) {
            long long value;
            if (time_left >= 0) {
                value = time_left / (m_order - c_order);
            }
            else {
                value = (time_left - m_order + c_order + 1) / (m_order - c_order);
            }
            if (value < high_bound) {
                high_bound = value;
            }
        } 
        else {
            long long value;
            if (time_left >= 0) {
                value = time_left / (m_order - c_order);
            }
            else {
                value = (time_left + (m_order - c_order) + 1) / (m_order - c_order);
            }
            
            if (value > low_bound) {
                low_bound = value;
            }
        }
    }
    if (low_bound <= high_bound) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, c_time, m_time;
        cin >> n >> c_time >> m_time;
        long long orders[101][3];
        for (int i = 0; i < n; i++) {
            cin >> orders[i][0] >> orders[i][1] >> orders[i][2];
        }
        long long low = 0;
        long long high = c_time + m_time;
        long long answer = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(orders, mid, c_time, m_time, n)) {
                answer = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        cout << answer << "\n";
    }
}
