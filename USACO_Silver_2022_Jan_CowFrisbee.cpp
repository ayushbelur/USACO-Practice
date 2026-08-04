#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    long long sum = 0;  
    vector<int> heights(300002);
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!s.empty()) {
            if (heights[i] > heights[s.top()]) {
                int index = s.top();
                s.pop();
                sum += (i - index + 1);
    
            }
            else {
                break;
            }
        }
        if (!s.empty()) {
            sum += (i - s.top() + 1);
        }
        s.push(i);
    }
    cout << sum;
}  