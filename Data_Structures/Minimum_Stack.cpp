#include <bits/stdc++.h>
using namespace std;

// Minimum Stack, O(1)
template <typename T>
struct MStack {
    stack<pair<T, T>> st;
    
    void push(const T &v) {
        T mn = st.empty() ? v : min(v, st.top().second);
        st.emplace(v, mn);
    }
    void pop() {
        st.pop();
    }
    T top() {
        return st.top().first;
    }
    T get() {
        return st.top().second;
    }
    bool empty() const {
        return st.empty();
    }
    int size() const {
        return st.size();
    }
};

void solve() {
    int q;
    cin >> q;

    MStack<int> st;
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (t == 2) {
            st.pop();
        }
        else if (t == 3) {
            cout << st.get() << '\n';
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
