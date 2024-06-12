#include <bits/stdc++.h>
using namespace std;

string strip(string s, char ch = ' ') {
    while (!s.empty() && s.back() == ch) {
        s.pop_back();
    }

    int n = s.size();
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
    cin >> s;

    s = string(s);
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
