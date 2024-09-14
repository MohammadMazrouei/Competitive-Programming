#include <bits/stdc++.h>
using namespace std;

// Minimum Queue, O(1)
template <typename T>
struct MQueue {
    stack<pair<T, T>> st1, st2;
    
    void push(const T &v) {
        T mn = st1.empty() ? v : min(v, st1.top().second);
        st1.emplace(v, mn);
    }
    void pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                T v = st1.top().first;
                T mn = st2.empty() ? v : min(v, st2.top().second);
                st1.pop();
                st2.emplace(v, mn);
            }
        }
        st2.pop();
    }
    T front() {
        if (st2.empty()) {
            while (!st1.empty()) {
                T v = st1.top().first;
                T mn = st2.empty() ? v : min(v, st2.top().second);
                st1.pop();
                st2.emplace(v, mn);
            }
        }
        return st2.top().first;
    }
    T get() {
        if (st1.empty() || st2.empty()) {
            return st1.empty() ? st2.top().second : st1.top().second;
        }
        return min(st1.top().second, st2.top().second);
    }
    bool empty() const {
        return st1.empty() && st2.empty();
    }
    int size() const {
        return st1.size() + st2.size();
    }
};

void solve() {
    int q;
    cin >> q;

    MQueue<int> qu;
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;
            qu.push(x);
        }
        else if (t == 2) {
            qu.pop();
        }
        else if (t == 3) {
            cout << qu.get() << '\n';
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
