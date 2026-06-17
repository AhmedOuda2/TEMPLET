struct Hashing {
    const long long mod1 = 1000000007;
    const long long mod2 = 1000000009;
    const long long base = 31;

    vector<long long> pw1, pw2;
    vector<long long> h1, h2;

    Hashing(string &s) {
        int n = s.size();

        pw1.resize(n + 1);
        pw2.resize(n + 1);

        h1.resize(n + 1);
        h2.resize(n + 1);

        pw1[0] = pw2[0] = 1;

        for (int i = 1; i <= n; i++) {
            pw1[i] = pw1[i - 1] * base % mod1;
            pw2[i] = pw2[i - 1] * base % mod2;
        }

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base + (s[i] - 'a' + 1)) % mod1;

            h2[i + 1] = (h2[i] * base + (s[i] - 'a' + 1)) % mod2;
        }
    }

    pair<long long, long long> getHash(int l,int r) {
        long long x1 = (h1[r + 1] - h1[l] * pw1[r - l + 1] % mod1 + mod1) % mod1;
        long long x2 = (h2[r + 1] - h2[l] * pw2[r - l + 1] % mod2 + mod2) % mod2;
        return {x1, x2};
    }
};
