int Fpower(int n,int p,int MOD) {
    if (!p) return 1;
    int ans = Fpower(n, p / 2, MOD) % MOD;
    ans *= ans;
    ans %= MOD;
    if (p & 1)ans = (ans * (n % MOD)) % MOD;
    return ans;
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
