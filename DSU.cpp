class DSU {
private:
    vector<int> p, sz;

public:
    DSU(int n) : p(n + 1), sz(n + 1, 1) {
        iota(all(p), 0);
    }

    int get(int x) {
        if (x == p[x]) return x;
        return p[x] = get(p[x]);
    }

    int get_sz(int x) {
        return sz[get(x)];
    }


    bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return 0;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        p[y] = x;
        return 1;
    }
};
