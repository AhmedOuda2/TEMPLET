vector<int> div(int n) {
    vector<int> v;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    sort(all(v));
    return v;
}
