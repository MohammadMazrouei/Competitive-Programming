#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    string s1(4, 'x'), 
           s2 = "abcdefghij";
    // assign(n, char), assign(string)

    // --- Iterators ---
    // begin(), end()
    // rbegin(), rend()

    // --- Capacity ---
    // size(), empty()
    // reserve(n), capacity()

    // --- Element accessa ---
    // front(), back()
    // [index], at(index)

    // --- Modifiers ---
    // push_back(char), += char, += string
    // append(n, char), append(string)
    // insert(pos, char), insert(pos, n, char), insert(pos, initial_list)
    // insert(pos, it_first, it_last)
    // insert(index, n, char), insert(index, string), insert(index, initial_list)
    // pop_back()
    // erase(pos), erase(pos_first, pos_last), erase(index, length)
    // replace(pos_first, pos_last, n, char), replace(pos_first, pos_last, string)
    // replace(index, length, n, char), replace(index, length, string)
    // replace(pos_first, pos_last, it_first, it_last)
    // resize(n, char), clear()

    // --- Search ---
    // Return index of first & last occurrence of a string (string::npos if not found)
    // s.find(string, start_index=0), s.rfind(string, start_index=npos)
    cout << s1.find("xx") << ' ' << s1.rfind("xx") << '\n';
    
    // --- Operations ---
    // contains(string)
    // starts_with(string), ends_with(string)
    // substr(index, length)

    // --- Numeric conversions ---
    // stoi(string), stol(string), stoll(string)
    // stoul(string), stoull(string)
    // stof(string), stod(string), stold(string)
    // to_string(number)
    int n1 = stoi("1234");
    int n2 = stoi("10010", nullptr, 2);
    cout << n1 << ' ' << n2 << '\n';
    string s_int = to_string(1111);
    string s_float = to_string(2222.22);
    cout << s_int << ' ' << s_float << '\n';

    // --- Hints ---
    // assign replacing a string with new properties (size and elements). 
    // resize holding old data and expanding the new string with new elements.
    // reserve change capacity of string.
    // string s_reverse = string(s.rbegin(), s.rend());
    // getline(cin, s)
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
