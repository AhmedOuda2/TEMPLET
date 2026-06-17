struct node {
    int n, lazy;
    bool islazy;
 
    node() {
        n = lazy = islazy = 0;
    }
 
    node(int val) {
        n = val;
    }
 
    void update(int val,int l,int r) {
        n += val * (r - l);
        lazy = val;
        islazy = 1;
    }
};
 
 
class LazySegment {
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
            if (lx < arr.size()) data[ni] = node(arr[lx]);
            return;
        }
 
        int mid = (lx + rx) >> 1;
        build(arr, 2 * ni + 1, lx, mid);
        build(arr, 2 * ni + 2, mid, rx);
        data[ni] = marge(data[2 * ni + 1], data[2 * ni + 2]);
    }
 
    void propagate(int ni,int lx,int rx) {
        if (rx - lx == 1 || !data[ni].islazy) return;
        int mid = (lx + rx) >> 1;
        data[2 * ni + 1].update(data[ni].lazy, lx, mid);
        data[2 * ni + 2].update(data[ni].lazy, mid, rx);
        data[ni].lazy = data[ni].islazy = 0;
    }
 
    void update(int val,int l,int r,int ni,int lx,int rx) {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            data[ni].update(val, lx, rx);
            return;
        }
        int mid = (lx + rx) >> 1;
        update(val, l, r, 2 * ni + 1, lx, mid);
        update(val, l, r, 2 * ni + 2, mid, rx);
        data[ni] = marge(data[2 * ni + 1], data[2 * ni + 2]);
    }
 
    node query(int l,int r,int ni,int lx,int rx) {
        propagate(ni, lx, rx);
        if (lx >= l && rx <= r) return data[ni];
        if (lx >= r || rx <= l) return node();
 
        int mid = (lx + rx) >> 1;
        node lf = query(l, r, 2 * ni + 1, lx, mid);
        node rt = query(l, r, 2 * ni + 2, mid, rx);
 
        return marge(lf, rt);
    }
 
public:
    LazySegment(vector<int> &arr) {
        seg_sz = 1;
        while (seg_sz < arr.size()) seg_sz <<= 1;
        data.assign(2 * seg_sz, node());
        build(arr, 0, 0, seg_sz);
    }
 
    node query(int l,int r) {
        return query(l, r, 0, 0, seg_sz);
    }
 
    void update(int val,int l,int r) {
        update(val, l, r, 0, 0, seg_sz);
    }
};
