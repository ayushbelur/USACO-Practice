#include <bits/stdc++.h> 
using namespace std; 

int id(char c) { 
    if (c >= 'a' && c <= 'z') { 
        return c - 'a'; 
    } else { 
        return c - 'A' + 26; 
    } 
} 

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t; 
    for (int x = 0; x < t; x++) { 
        vector<int> adj_list(52, -1); 
        string input, output; 
        cin >> input; 
        cin >> output; 
        bool possible = true; 
        set<int> unique; 
        for (int i = 0; i < input.size(); i++) { 
            if (adj_list[id(input[i])] == id(output[i]) || adj_list[id(input[i])] == -1) { 
                adj_list[id(input[i])] = id(output[i]); 
                if (input[i] != output[i]) {
                    unique.insert(id(output[i]));
                }
            } else { 
                possible = false; 
            } 
        } 

        int keystrokes = 0; 
        int cycles = 0; 

        if (possible) { 
            for (int i = 0; i < 52; i++) { 
                if (adj_list[i] != -1 && adj_list[i] != i) { 
                    keystrokes += 1; 
                } 
            } 
            
            vector<int> visited(52, 0); 
            for (int i = 0; i < 52; i++) { 
                if (visited[i] == 0 && adj_list[i] != -1 && adj_list[i] != i) { 
                    int curr = i; 
                    
                    while (curr != -1 && visited[curr] == 0) { 
                        visited[curr] = i + 1; 
                        curr = adj_list[curr]; 
                    } 
                    
                    if (curr != -1 && adj_list[curr] != curr && visited[curr] == i + 1) { 
                        cycles += 1; 
                    } 
                } 
            } 
        } 

        if (possible && unique.size() == 52 && cycles > 0) { 
            possible = false; 
        } 

        if (possible) { 
            cout << keystrokes + cycles << "\n"; 
        } else { 
            cout << -1 << "\n"; 
        } 
    } 
    return 0;
}
