#include <bits/stdc++.h>
using namespace std;

// Strip String, O(n)
string strip(const string &s, const char ch = ' ') {
    int n = s.size();
    while (n > 0 && s[n - 1] == ch) {
        n--;
    }

    string res = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == ch) {
            continue;
        }
        while (i < n) {
            res += s[i];
            i++;
        }
    }
    return res;
}

void solve() {
    string s;
    getline(cin, s);

    s = strip(s);
    cout << s << '\n';
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
