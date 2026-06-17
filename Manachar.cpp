struct Manacher {
    string s;
    vector<int> d1, d2;

    Manacher(string t) {
        s = t;
        build();
    }

    void build() {
        int n = s.size();

        d1.assign(n, 0);
        int l = 0, r = -1;

        for (int i = 0; i < n; i++) {
            int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        d2.assign(n, 0);
        l = 0, r = -1;

        for (int i = 0; i < n; i++) {
            int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
    }

    bool is_palindrome(int l, int r) {
        int len = r - l + 1;

        if (len & 1) {
            int mid = (l + r) / 2;
            return d1[mid] >= (len + 1) / 2;
        } else {
            int mid = (l + r + 1) / 2;
            return d2[mid] >= len / 2;
        }
    }
};
