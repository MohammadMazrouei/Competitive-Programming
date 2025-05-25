#include <bits/stdc++.h>
using namespace std;

// Minimum Stack, O(1)
template <typename T, typename Compare = less<T>>
struct MStack {
    stack<pair<T, T>> st;
    Compare cmp = Compare();
    
    void push(const T& x) {
        T mn = st.empty() ? x : min(x, st.top().second, cmp);
        st.emplace(x, mn);
    }
    void pop() {
        st.pop();
    }
    T top() const {
        return st.top().first;
    }
    T get() const {
        return st.top().second;
    }
    int size() const {
        return st.size();
    }
    bool empty() const {
        return st.empty();
    }
};

void solve() {
    int q;
    cin >> q;

    MStack<int> mst;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            mst.push(x);
        } else if (op == 2) {
            mst.pop();
        } else if (op == 3) {
            cout << mst.get() << '\n';
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
