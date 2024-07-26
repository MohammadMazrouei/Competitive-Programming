#include <bits/stdc++.h>
using namespace std;

// with global array is faster (1.9s vs 2.9s for n = 1e7)
// constexpr n = 1e7, lg = 25; int t[n][lg];
template <typename T>
struct SparseTable {
    int n, lg;
    vector<vector<T>> t;

    SparseTable() {}
    SparseTable(const vector<T> &v) {
        build(v);
    }

    inline T f(const T &a, const T &b) const {
        return min(a, b);
    }
    void build(const vector<T> &v) {
        n = v.size();
        lg = __lg(n) + 2;
        t.resize(n);
        for (int i = 0; i < n; i++) {
            t[i].resize(lg);
        }

        for (int i = 0; i < n; i++) {
            t[i][0] = v[i];
        }
        for (int k = 1; k < lg; k++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                t[i][k] = f(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    T get(int l, int r) { 
        assert(l >= 0 && l < n && r >= 0 && r < n);
        //int k = __builtin_clzll(1) - __builtin_clzll(r - l + 1);
        int k = __builtin_clz(1) - __builtin_clz(r - l + 1);
        return f(t[l][k], t[r - (1 << k) + 1][k]);
    }
};

// Suffix Array, build -> O(n*log(n)), lcp -> O(n)
// Numbrer of differents substrings = (n^2 + n) / 2 - sum(lcp)
struct SuffixArray {
    int n;
    string s;
    vector<int> sa, lcp, rnk;
    SparseTable<int> t;

    SuffixArray(const string &_s, const int char_bound = 256) {
        n = _s.size();
        s = _s;
        suffix_array(s + '$', char_bound);
        build_lcp(s, sa);
        t.build(lcp);
    }

    void suffix_array(const string &s, const int char_bound) {
        int n = s.size();
        sa.resize(n);

        if (char_bound != -1) {
            vector<int> aux(char_bound, 0);
            for (int i = 0; i < n; i++) {
                aux[s[i]]++;
            }
            int sum = 0;
            for (int i = 0; i < char_bound; i++) {
                int add = aux[i];
                aux[i] = sum;
                sum += add;
            }
            for (int i = 0; i < n; i++) {
                sa[aux[s[i]]++] = i;
            }
        } 
        else {
            iota(sa.begin(), sa.end(), 0);
            sort(sa.begin(), sa.end(), [&s](int i, int j) { 
                return s[i] < s[j]; 
            });
        }

        vector<int> sorted_by_second(n);
        vector<int> ptr_group(n);
        vector<int> new_group(n);
        vector<int> group(n);
        group[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            group[sa[i]] = group[sa[i - 1]] + (!(s[sa[i]] == s[sa[i - 1]]));
        }
        int cnt = group[sa[n - 1]] + 1;
        int step = 1;
        while (cnt < n) {
            int at = 0;
            for (int i = n - step; i < n; i++) {
                sorted_by_second[at++] = i;
            }
            for (int i = 0; i < n; i++) {
                if (sa[i] - step >= 0) {
                    sorted_by_second[at++] = sa[i] - step;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                ptr_group[group[sa[i]]] = i;
            }
            for (int i = 0; i < n; i++) {
                int x = sorted_by_second[i];
                sa[ptr_group[group[x]]++] = x;
            }
            new_group[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                if (group[sa[i]] != group[sa[i - 1]]) {
                    new_group[sa[i]] = new_group[sa[i - 1]] + 1;
                } 
                else {
                    int pre = (sa[i - 1] + step >= n ? -1 : group[sa[i - 1] + step]);
                    int cur = (sa[i] + step >= n ? -1 : group[sa[i] + step]);
                    new_group[sa[i]] = new_group[sa[i - 1]] + (pre != cur);
                }
            }
            swap(group, new_group);
            cnt = group[sa[n - 1]] + 1;
            step <<= 1;
        }
        sa.erase(sa.begin());
    }

    void build_lcp(const string &s, const vector<int> &sa) {
        int n = s.size();
        assert((int)sa.size() == n);
        lcp.resize(max(n - 1, 0));
        rnk.resize(n);

        for (int i = 0; i < n; i++) {
            rnk[sa[i]] = i;
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            k = max(k - 1, 0);
            if (rnk[i] == n - 1) {
                k = 0;
            } 
            else {
                int j = sa[rnk[i] + 1];
                while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                    k++;
                }
                lcp[rnk[i]] = k;
            }
        }
    }   

    // O(|t|*log(n))
    int lower_bound(const string &t) {
        int l = 0, h = n - 1, ind = n;
        while (l <= h) {
            int mid = (l + h) >> 1;
            bool ok = true;
            for (int i = 0; i < (int)t.size(); i++) {
                if (sa[mid] + i >= n) {
                    ok = false;
                    break;
                }
                if (s[sa[mid] + i] != t[i]) {
                    if (s[sa[mid] + i] < t[i]) {
                        ok = false;
                    }
                    break;
                }
            }
            if (ok) {
                ind = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ind;
    }

    int upper_bound(const string &t) {
        int l = 0, h = n - 1, ind = n;
        while (l <= h) {
            int mid = (l + h) >> 1;
            bool ok = false;
            for (int i = 0; i < (int)t.size(); i++) {
                if (sa[mid] + i >= n) {
                    break;
                }
                if (s[sa[mid] + i] != t[i]) {
                    if (s[sa[mid] + i] > t[i]) {
                        ok = true;
                    }
                    break;
                }
            }
            if (ok) {
                ind = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ind;
    }

    // Occurrences of s[p, ..., p + len - 1], O(log(n))
    pair<int, int> find_occurrence(int p, int len) {
        p = rnk[p];
        pair<int, int> ans = {p, p};
        int l = 0, r = p - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (t.get(mid, p - 1) >= len) {
                ans.first = mid; 
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        l = p + 1, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (t.get(p, mid - 1) >= len) {
                ans.second = mid; 
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

void solve() {
    string s;
    cin >> s;

    SuffixArray sa(s);

    int n = s.size();
    for (int i = 0; i < n; i++) {
        cout << sa.sa[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << sa.lcp[i] <<  " \n"[i == n - 2];
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;

        int num = sa.upper_bound(t) - sa.lower_bound(t);
        cout << num << '\n';
    }

    cin >> q;
    while (q--) {
        int p, len;
        cin >> p >> len;
        p--;

        pair<int, int> num = sa.find_occurrence(p, len);
        cout << num.second - num.first + 1 << '\n';
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
