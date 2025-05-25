#include <bits/stdc++.h>
using namespace std;

// Minimum Queue, O(1)
template <typename T, typename Compare = less<T>>
struct MQueue {
    stack<pair<T, T>> st1, st2;
    Compare cmp = Compare();
    
    void push(const T& x) {
        T mn = st1.empty() ? x : min(x, st1.top().second, cmp);
        st1.emplace(x, mn);
    }
    void pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                T x = st1.top().first;
                T mn = st2.empty() ? x : min(x, st2.top().second, cmp);
                st1.pop();
                st2.emplace(x, mn);
            }
        }
        st2.pop();
    }
    T front() {
        if (st2.empty()) {
            while (!st1.empty()) {
                T x = st1.top().first;
                T mn = st2.empty() ? x : min(x, st2.top().second, cmp);
                st1.pop();
                st2.emplace(x, mn);
            }
        }
        return st2.top().first;
    }
    T get() const {
        if (st1.empty() || st2.empty()) {
            return st1.empty() ? st2.top().second : st1.top().second;
        }
        return min(st1.top().second, st2.top().second, cmp);
    }
    int size() const {
        return st1.size() + st2.size();
    }
    bool empty() const {
        return st1.empty() && st2.empty();
    }
};

void solve() {
    int q;
    cin >> q;

    MQueue<int> mq;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            mq.push(x);
        } else if (op == 2) {
            mq.pop();
        } else if (op == 3) {
            cout << mq.get() << '\n';
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
