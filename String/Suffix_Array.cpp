#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    int n;
    string s;
    vector<int> sa, lcp, rnk;
    //vector<int> lg;
    //vector<vector<int>> t;

    SuffixArray(const string &_s, const int char_bound = 256) {
        n = _s.size();
        s = _s;
        suffix_array(s + '$', char_bound);
        build_lcp(s, sa);
    }

    void suffix_array(const string &s, const int char_bound) {
        int n = s.size();
        sa.resize(n);
        if (n == 0) {
            return;
        }

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
            sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
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

    /*
    void build() {
        int LG = 20;
    int sz = n - 1;
    t.resize(sz);
    for (int i = 0; i < sz; i++) {
      t[i].resize(LG);
      t[i][0] = lcp[i];
    }
    for (int k = 1; k < LG; ++k) {
      for (int i = 0; i + (1 << k) - 1 < sz; ++i) {
        t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
      }
    }
  }
    void prec() {
        lg.resize(n, 0);
        for (int i = 2; i < n; i++) lg[i] = lg[i / 2] + 1;
    }

    int query(int l, int r) { // minimum of lcp[l], ..., lcp[r]
        int k = lg[r - l + 1];
        return min(t[l][k], t[r - (1 << k) + 1][k]);
    }

    // occurrences of s[p, ..., p + len - 1]
    pair<int, int> find_occurrence(int p, int len) {
        p = rnk[p];
        pair<int, int> ans = {p, p};
        int l = 0, r = p - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(mid, p - 1) >= len) ans.first = mid, r = mid - 1;
            else l = mid + 1;
        }
        l = p + 1, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(p, mid - 1) >= len) ans.second = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
    */
};

void solve() {
    string s;
    cin >> s;

    SuffixArray sa(s);

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;

        int num = sa.upper_bound(t) - sa.lower_bound(t);
        cout << num << '\n';
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
