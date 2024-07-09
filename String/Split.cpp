#include <bits/stdc++.h>
using namespace std;

// Split String, O(n)
vector<string> split(const string &s, const char ch = ' ') {
    int n = s.size();
    vector<string> sp;

    string tmp = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != ch) {
            tmp += s[i];
        }
        else if (tmp != "") {
            sp.push_back(tmp);
            tmp = "";
        }
    }
    if (tmp != "") {
        sp.push_back(tmp);
    }
    return sp;
}

void solve() {
    string s;
    getline(cin, s);

    vector<string> sp = split(s);
    for (string &str : sp) {
        cout << str << '\n';
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
