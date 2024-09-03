#include <bits/stdc++.h>
using namespace std;

// MEX with Update, build -> O(n*log(n)), update -> O(log(n))
template <typename T>
struct Mex {
    vector<T> arr;
    map<T, int> frequency;
    set<T> missing_numbers;

    Mex(const vector<T> &_arr) : arr(_arr) {
        for (int i = 0; i <= (int)arr.size(); i++) {
            missing_numbers.insert(i);
        }
        for (auto v : arr) {
            frequency[v]++;
            missing_numbers.erase(v);
        }
    }

    void modify(int x, const T &v) {
        assert(x < (int)arr.size());
        if (--frequency[arr[x]] == 0) {
            missing_numbers.insert(arr[x]);
        }
        arr[x] = v;
        frequency[v]++;
        missing_numbers.erase(v);
    }
    T get() {
        return *missing_numbers.begin();
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Mex mex(a);
    while (q--) {
        int ind, x;
        cin >> ind >> x;
        ind--;
        mex.modify(ind, x);
        cout << mex.get() << '\n';
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
