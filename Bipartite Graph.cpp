#include <bits/stdc++.h>
using namespace std;

void color(int u, int curr, bool &bi, vector<int> &col, vector<vector<int>> &adj) {
    if (col[u] != -1 && col[u] != curr) {
        bi = false;
        return;
    }
    
    col[u] = curr;
    for (auto i : adj[u]) {
        if (col[i] == curr) {
            bi = false;
            return;
        }
        if (col[i] == -1) {
            color(i, curr ^ 1, bi, col, adj);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    bool bi = true;
    
    vector<int> col(n, -1);
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            color(i, 0, bi, col, adj);
        }
    }

    if (bi) {
        cout << "biparted";
    } else {
        cout << "not biparted";
    }

    return 0;
}
