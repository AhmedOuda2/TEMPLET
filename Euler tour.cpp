const int N = 2e6 + 5, mod = 1e9 + 7;

struct Edge {
    int to, id;
};


vector<Edge> adj[N];
bool used[N];
vector<int> path;

void euler(int u) {
    while (!adj[u].empty()) {
        Edge e = adj[u].back();
        adj[u].pop_back();
        if (used[e.id]) continue;
        used[e.id] = true;
        euler(e.to);
    }
    path.push_back(u);
}

// reverse(all(path));
