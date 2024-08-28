#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s = "abcdefgbc", s2(10, 'x');
    string reverse_s = string(s.rbegin(), s.rend());

    // begin, end, rbegin, rend
    // front, back, [], at
    // size, empty, clear
    // push_back, s.pop_back, +=
    // getline(cin, s)

    // insert(pos, str), insert(pos, n, char), insert(pos, it_begin, it_end)
    // erase(pos), erase(pos_begin, pos_end)
    // append(str), append(n, char)

    // replace(start_index, length, str), replace(start_index, length, n, char)
    // replace(pos_begin, pos_end, str), replace(pos_begin, pos_end, n, char)
    // replace(pos_begin, pos_end, it_begin, it_end)

    // Assign replacing a string with new properties (size and elements). 
    // Resize holding old data and expanding the new string with new elements.
    // Reserve change capacity of string.
    s.assign(4, 'a');
    s.resize(10, 'b');
    s.reserve(100);
    cout << s << '\n';

    // Return index of first & last occurrence of a string (s.npos if not found)
    // s.find(str, start_index=0), s.rfind(str, start_index=0)
    cout << s.find("aa") << ' ' << s.rfind("aa") << '\n';
    cout << s.contains("aabb") << ' ' << s.starts_with("aa") << ' ' << s.ends_with("aa") << '\n';

    // s.substr(strat_index, length)
    cout << s.substr(2, 4) << '\n';

    // stoi, stol, stoll, stoul, stoull, stof, stod, stold
    int n1 = stoi("1234"), n2 = stoi("10010", nullptr, 2);
    cout << n1 << ' ' << n2 << '\n';

    // to_string
    string s_int = to_string(1111);
    string s_float = to_string(2222.22);
    cout << s_int << ' ' << s_float << '\n';
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
