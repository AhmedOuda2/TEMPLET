const int N = 1e6+5;
vector<int> sp(N);
void spf() {
    for (int i = 0; i < N; i++) { sp[i] = i; }
    for (int i = 2; i < N / i; i++) {
        if (sp[i] == i) {
            for (int j = i * i; j < N; j += i) {
                sp[j] = min(sp[j], i);
            }
        }
    }
}
vector<int> factors(int n) {
    vector<int> v;
    while (n != 1) {
        int x = sp[n];
        v.push_back(x);
        n /= x;
    }
    return v;
}
