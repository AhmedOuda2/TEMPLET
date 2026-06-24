class LCA {
    int n, lg;
    vector<vector<int> > adj, anc;

    void buildAncestor(int node,int par) {
        anc[node][0] = par;
        for (int i = 1; i < lg; i++) {
            int p = anc[node][i - 1];
            anc[node][i] = anc[p][i - 1];
        }
        for (int it: adj[node]) {
            if (it != par) {
                lvl[it] = lvl[node] + 1;
                buildAncestor(it, node);
            }
        }
    }

    int lca(int u,int v) {
        if (lvl[u] < lvl[v]) swap(u, v);
        u = kthAncestor(u, lvl[u] - lvl[v]);
        if (u == v) return u;
        for (int i = lg - 1; ~i; i--) {
            if (anc[u][i] == anc[v][i]) continue;
            u = anc[u][i];
            v = anc[v][i];
        }
        return anc[v][0];
    }

public:
    vector<int> lvl;

    LCA(vector<vector<int> > a,int root) {
        n = a.size();
        lg = 1;
        adj = a;

        while ((1 << lg) <= n) lg++;
        anc.assign(n, vector<int>(lg));
        lvl.assign(n, 0);

        buildAncestor(root, root);
    }

    int lowestCommonAncestor(int u,int v) {
        return lca(u, v);
    }

    int kthAncestor(int node,int k) {
        for (int i = lg - 1; ~i; i--) {
            if ((k >> i) & 1) {
                node = anc[node][i];
            }
        }
        return node;
    }


    int distance(int u,int v) {
        int l = lca(u, v);
        int dis = (lvl[u] + lvl[v]) - 2 * lvl[l];
        return dis;
    }
};
