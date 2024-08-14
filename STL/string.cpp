#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s = "abcdefgbc";
    string reverse_s = string(s.rbegin(), s.rend());

    // s.begin(), s.end(), s.rbegin(), s.rend()
    // s.front(), s.back()
    // s.size(), s.empty(), s.clear()
    // s.push_back('a'), s.pop_back()

    string s2(10, 'y');
    s2.assign(10, 'x');

    // s.substr(strat_index, length);
    getline(cin, s2);
    cout << s2.substr(0, 4) << '\n';

    // return index of first & last occurrence
    cout << s.find("bc") << '\n';
    cout << s.rfind("bc") << '\n';

    s.erase(s.begin());
    s.erase(s.begin(), s.end());
    s.insert(s.begin(), 'z');
    cout << s << '\n';

    cout << s.starts_with("bc") << '\n';
    cout << s.ends_with("z") << '\n';
    //s.contains("text"); //c++23

    // stoi, stol, stoll, stoul, stoull, stof, stod, stold
    int64_t n1 = stoll("1234567890000");
    int n2 = stoi("10010", nullptr, 2);
    cout << n1 << '\n' << n2 << '\n';

    // to_string
    string s_int = to_string(1234);
    string s_float = to_string(1234.1234);
    cout << s_int << '\n' << s_float << '\n';
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
