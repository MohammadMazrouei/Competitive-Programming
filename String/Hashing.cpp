#include <bits/stdc++.h>
using namespace std;

// Hash Strings, O(1)
struct Hash {
    static const uint64_t md = (1LL << 61) - 1;
    static uint64_t step;
    static vector<uint64_t> pw;

    uint64_t addmod(uint64_t a, uint64_t b) const {
        a += b;
        if (a >= md) a -= md;
        return a;
    }

    uint64_t submod(uint64_t a, uint64_t b) const {
        a += md - b;
        if (a >= md) a -= md;
        return a;
    }

    uint64_t mulmod(uint64_t a, uint64_t b) const {
        uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
        uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & md) + (ret >> 61);
        ret = (ret & md) + (ret >> 61);
        return ret - 1;
    }

    void ensure_pw(int sz) {
        int cur = pw.size();
        if (cur < sz) {
            pw.resize(sz);
            for (int i = cur; i < sz; i++) {
                pw[i] = mulmod(pw[i - 1], step);
            }
        }
    }

    int n;
    vector<uint64_t> pref;

    template<typename T>
    Hash(const T &s) {
        n = s.size();
        ensure_pw(n + 1);
        pref.resize(n + 1);
        pref[0] = 1;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
        }
    }

    inline uint64_t operator()(const int l, const int r) const {
        assert(l >= 0 && l <= r && r < n);
        return submod(pref[r + 1], mulmod(pref[l], pw[r - l + 1]));
    }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

uint64_t Hash::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> Hash::pw = vector<uint64_t>(1, 1);

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    auto h1 = Hash(s1), h2 = Hash(s2);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (h1(l, r) == h2(l, r) ? "YES\n" : "NO\n");
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
