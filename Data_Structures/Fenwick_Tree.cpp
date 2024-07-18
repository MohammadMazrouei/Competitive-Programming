#include <bits/stdc++.h>
using namespace std;

// Point_Update & Range_Query, O(log(n))
template <typename T>
struct FenwickTree {
    int n;
    vector<T> f;
    
    FenwickTree() {}
    FenwickTree(int _n) : n(_n) {
        f.assign(n, T{});
    }
    // O(n) Construction
    FenwickTree(const vector<T> &v) {
        n = v.size();
        f.assign(n, T{});
        for (int i = 0; i < n; i++) {
            f[i] += v[i];
            int r = i | (i + 1);
            if (r < n) {
                f[r] += f[i];
            }
        }
    }
    
    void add(int x, const T &v) {
        assert(x >= 0 && x < n);
        for (int i = x; i < n; i = i | (i + 1)) {
            f[i] += v;
        }
    }
    T get(int x) {
        T ans{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            ans += f[i];
        }
        return ans;
    }
    T get(int l, int r) {
        assert(l >= 0 && l < n && r >= 0 && r < n);
        return get(r) - get(l - 1);
    }
    // Return kth largest element
    int select(const T &k) {
        int x = (1 << (__lg(n) + 1)) - 1;
        T sum{};
        for (int i = 1 << __lg(n); i; i >>= 1) {
            if (x >= n || sum + f[x] >= k) {
                x -= i;
            }
            else if (x + i < n && sum + f[x] + f[x + i] < k) {
                sum += f[x];
                x += i;
            }
        }
        if (sum + f[x] < k) {
            x++;
        }
        return x;
    }
};

// Range_Update & Point_Query, O(log(n))
template <typename T>
struct FenwickTree2 { 
    int n;
    vector<T> f;
    
    FenwickTree2() {}
    FenwickTree2(int _n) : n(_n) {
        f.assign(n, T{});
    }
    FenwickTree2(const vector<T> &v) {
        n = v.size();
        f.assign(n, T{});
        for (int i = 0; i < n; i++) {
            add(i, i, v[i]);
        }
    }

    void add(int x, T v) {
        for (int i = x; i < n; i = i | (i + 1)) {
            f[i] += v;
        }
    }
    void add(int l, int r, T v) {
        assert(l >= 0 && l < n && r >= 0 && r < n);
        add(l, v);
        add(r + 1, -v);
    }
    T get(int x) {
        assert(x >= 0 && x < n);
        T ans = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            ans += f[i];
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    FenwickTree<int> fen(a);
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, v;
            cin >> x >> v;
            x--;
            fen.add(x, v);
        }
        else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << fen.get(l, r) << '\n';
        }
    }
}

void solve2() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    FenwickTree2<int> fen(a);
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            fen.add(l, r, v);
        }
        else if (t == 2) {
            int x;
            cin >> x;
            x--;
            cout << fen.get(x) << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
