struct node {
    int n;

    ///neutral
    node() {
        //skip
        n = 0;
    }

    /// update
    void change(int val) {
        n = val;
    }
};


class Segment {
private:
    int seg_sz;
    vector<node> data;

    node marge(node l, node r) {
        node res = node();
        res.n = l.n + r.n;
        return res;
    }

    void build(vector<int> &arr,int ni,int lx,int rx) {
        //not included r
        if (rx - lx == 1) {
            if (lx < arr.size()) data[ni].change(arr[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(arr, 2 * ni + 1, lx, mid);
        build(arr, 2 * ni + 2, mid, rx);
        data[ni] = marge(data[2 * ni + 1], data[2 * ni + 2]);
    }

    void update(int idx,int new_val,int ni,int lx, int rx) {
        if (rx - lx == 1) {
            data[ni].change(new_val);
            return;
        }

        int mid = (lx + rx) >> 1;
        if (idx < mid) update(idx, new_val, 2 * ni + 1, lx, mid);
        else update(idx, new_val, 2 * ni + 2, mid, rx);
        data[ni] = marge(data[2 * ni + 1], data[2 * ni + 2]);
    }

    node query(int l,int r,int ni,int lx,int rx) {
        if (lx >= l && rx <= r) return data[ni];
        if (lx >= r || rx <= l) return node();

        int mid = (lx + rx) >> 1;
        node lf = query(l, r, 2 * ni + 1, lx, mid);
        node rt = query(l, r, 2 * ni + 2, mid, rx);

        return marge(lf, rt);
    }

public:
    Segment(vector<int> &arr) {
        seg_sz = 1;
        while (seg_sz < arr.size()) seg_sz <<= 1;
        data.assign(2 * seg_sz, node());
        build(arr, 0, 0, seg_sz);
    }

    void update(int idx,int new_val) {
        update(idx, new_val, 0, 0, seg_sz);
    }

    int query(int l,int r) {
        return query(l, r + 1, 0, 0, seg_sz).n;
    }
};
