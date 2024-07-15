#include <bits/stdc++.h>
using namespace std;

// Minimum Stack, O(1)
template <typename T>
struct MStack {
    stack<pair<T, T>> st;
    
    void push(T v) {
        T mn = st.empty() ? v : min(v, st.top().second);
        st.push({v, mn});
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
    bool empty() {
        return st.empty();
    }
    int size() {
        return st.size();
    }
};

void solve() {
    int q;
    cin >> q;

    MStack<int> s;
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (t == 2) {
            s.pop();
        }
        else if (t == 3) {
            cout << s.get() << '\n';
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
