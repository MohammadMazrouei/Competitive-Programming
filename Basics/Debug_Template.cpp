#include <bits/stdc++.h>
using namespace std;

#define dbg(...) cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgarr(...) cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)

namespace __DEBUG_UTIL__ {
    bool colored_output = false; 
    string white = colored_output ? "\033[0;m" : "";
    string outer = colored_output ? "\033[0;31m" : "";     // red
    string var_name = colored_output ? "\033[1;34m" : "";  // blue
    string var_value = colored_output ? "\033[1;32m" : ""; // green

    template <typename T>
    concept is_iterable = requires(T &&x) { begin(x); } && !is_same_v<remove_cvref_t<T>, string>;

    void print(const char *x) { 
        cerr << x; 
    }
    void print(char x) { 
        cerr << "\'" << x << "\'"; 
    }
    void print(bool x) { 
        cerr << (x ? "T" : "F"); 
    }
    void print(string x) { 
        cerr << "\"" << x << "\"";
    }

    void print(vector<bool> &&v) { 
        /* Overloaded this because stl optimizes vector<bool> by using
         _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v) {
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        }
        cerr << "}";
    }

    template <typename T>
    void print(T &&x) {
        if constexpr (is_iterable<T>) {
            if (size(x) && is_iterable<decltype(*(begin(x)))>) { 
                /* Iterable inside Iterable */
                int f = 0;
                cerr << "\n~~~~~\n";
                int w = max(0, (int)log10(size(x) - 1)) + 2;
                for (auto &&i : x) {
                    cerr << setw(w) << left << f++, print(i), cerr << "\n";
                }
                cerr << "~~~~~\n";
            }
            else { 
                /* Normal Iterable */
                int f = 0;
                cerr << "{";
                for (auto &&i : x) {
                    cerr << (f++ ? "," : ""), print(i);
                }
                cerr << "}";
            }
        }
        else if constexpr (requires { x.pop(); }) {
            /* Stacks, Priority Queues, Queues */
            auto temp = x;
            int f = 0;
            cerr << "{";
            if constexpr (requires { x.top(); }) {
                while (!temp.empty()) {
                    cerr << (f++ ? "," : ""), print(temp.top()), temp.pop();
                }
            }
            else {
                while (!temp.empty()) {
                    cerr << (f++ ? "," : ""), print(temp.front()), temp.pop();
                }
            }
            cerr << "}";
        }
        else if constexpr (requires { x.first; x.second; }) {
            /* Pair */
            cerr << '(', print(x.first), cerr << ',', print(x.second), cerr << ')';
        }
        else if constexpr (requires { get<0>(x); }) {
            /* Tuple */
            int f = 0;
            cerr << '(', apply([&f](auto... args) {
                              ((cerr << (f++ ? "," : ""), print(args)), ...);
                         }, x);
            cerr << ')';
        }
        else {
            cerr << x;
        }
    }

    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++) {
            if (names[i] == '(' or names[i] == '<' or names[i] == '{') {
                bracket++;
            }
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}') {
                bracket--;
            }
        }
        cerr << var_name;
        cerr.write(names, i) << outer << " = " << var_value;
        print(head);
        if constexpr (sizeof...(tail)) {
            cerr << outer << " ||", printer(names + i + 1, tail...);
        }
        else {
            cerr << outer << "]\n" << white;
        }
    }

    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail) {
        size_t i = 0;
        cerr << var_name;
        for (; names[i] and names[i] != ','; i++) {
            cerr << names[i];
        }
        for (i++; names[i] and names[i] != ','; i++);
        cerr << outer << " = " << var_value << "{";
        for (size_t ind = 0; ind < N; ind++) {
            cerr << (ind ? "," : ""), print(arr[ind]);
        }
        cerr << "}";
        if constexpr (sizeof...(tail)) {
            cerr << outer << " ||", printerArr(names + i + 1, tail...);
        }
        else {
            cerr << outer << "]\n" << white;
        }
    }
}

void solve() {
    pair<int, bool> x1 = {1, 2};
    pair<char, string> x2 = {'a', "mmd"};
    dbg(x1, x2);

    vector<int> v = {1, 2, 3, 4};
    dbg(v);

    int arr[100] = {12, 13};
    dbgarr(arr, 10);

    queue<int> q;
    stack<int> s;
    q.push(100);
    q.push(200);
    s.push(100);
    s.push(200);
    dbg(q, s);
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
