template<typename T>
struct Matrix {
    int n, m;
    vector<vector<T> > vec;

    Matrix(int n, int m) : n(n), m(m) {
        vec = vector<vector<T> >(n, vector<T>(m, 0));
    }

    vector<T> &operator[](int i) {
        return vec[i];
    }

    Matrix operator*(Matrix &a) {
        int r = n, c = a.m, s = m;
        Matrix res(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < s; k++) {
                    res[i][j] += vec[i][k] % mod * (a[k][j] % mod) % mod;
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    }

    static Matrix identity(int n) {
        Matrix I(n, n);
        for (int i = 0; i < n; i++)
            I[i][i] = 1;
        return I;
    }

    static Matrix power(Matrix a, int p) {
        Matrix res = identity(a.n);
        while (p > 0) {
            if (p & 1) res = res * a;
            a = a * a;
            p >>= 1;
        }
        return res;
    }
};
