int Fpower(int n,int p,int MOD) {
    int res = 1;
    while (p) {
        if (p & 1) res = res % MOD * (n % MOD) % MOD;
        n = n % MOD * (n % MOD) % MOD;
        p >>= 1;
    }
    return res;
}

int inverse(int n) {
    return Fpower(n % mod, mod - 2, mod);
}

int fact[N], invfact[N];

void pre() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;

    invfact[N - 1] = inverse(fact[N - 1]);
    for (int i = N - 2; ~i; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }
}

int P(int n,int r) {
    return fact[n] * invfact[n - r] % mod;
}

int C(int n,int r) {
    return fact[n] * invfact[n - r] % mod * invfact[r] % mod;
}

int nCr(int n, int r) {
    // without modulo
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    int result = 1;
    for (int i = 1; i <= r; ++i) {
        result = result * (n - r + i) / i;
    }
    return result;
}
