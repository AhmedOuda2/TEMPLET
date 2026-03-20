struct segment {
private:
    int sz;
    double skip;
    vector<double> seg;

    double merge(double a, double b) {
        return a + b;
    }

    void skip_val() {
        skip = 0.0;
    }

    void build(int l, int r, int idx, vector<double> &v) {
        if (l == r) {
            if (l < v.size())
                seg[idx] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, idx * 2 + 1, v);
        build(mid + 1, r, idx * 2 + 2, v);
        seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    double query(int l, int r, int idx, int lx, int rx) {
        if (l > rx || r < lx)
            return skip;
        if (l >= lx && r <= rx)
            return seg[idx];
        int mid = (l + r) / 2;
        auto x = query(l, mid, idx * 2 + 1, lx, rx);
        auto y = query(mid + 1, r, idx * 2 + 2, lx, rx);
        return merge(x, y);
    }

    void update(int l, int r, int idx, int x, double val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid)
            update(l, mid, idx * 2 + 1, x, val);
        else
            update(mid + 1, r, idx * 2 + 2, x, val);
        seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

public:
    segment(vector<double> &v) {
        skip_val();
        sz = 1;
        while (sz < v.size()) sz *= 2;
        seg.resize(sz * 2, skip);
        build(0, sz - 1, 0, v);
    }

    double query(int l, int r) {
        return query(0, sz - 1, 0, l, r);
    }

    void update(int x, double val) {
        update(0, sz - 1, 0, x, val);
    }
};
