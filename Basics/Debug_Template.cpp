#include <bits/stdc++.h>
using namespace std;

#define dbg(...) cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", \
                 __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__), \
                 cerr << __DEBUG_UTIL__::outer << "]\n" << __DEBUG_UTIL__::reset

namespace __DEBUG_UTIL__ {
    const string WHITE = "\033[0;m";
    const string RED = "\033[0;31m";
    const string BLUE = "\033[0;34m";
    const string GREEN = "\033[0;32m";

    bool colored_output = isatty(fileno(stderr)); 
    string reset = colored_output ? WHITE : "";
    string outer = colored_output ? RED : "";
    string var_name = colored_output ? BLUE : "";
    string var_value = colored_output ? GREEN : "";

    template <typename T>
    concept is_iterable = requires(T &&x) { begin(x); } && !is_same_v<remove_cvref_t<T>, string>;

    template <typename T>
    void print(T *p);

    void print(const char *x) { cerr << x; }
    void print(char x) { cerr << "\'" << x << "\'"; }
    void print(bool x) { cerr << (x ? "true" : "false"); }
    void print(string x) { cerr << "\"" << x << "\""; }

    void print(vector<bool> &&v) { 
        // Vector<bool>, stl optimizes this by using _Bit_reference
        int f = 0;
        cerr << "{";
        for (auto &&i : v) {
            cerr << (f++ ? ", " : "") << (i ? "true" : "false");
        }
        cerr << "}";
    }

    template <typename T>
    void print(T &&x) {
        if constexpr (is_iterable<T>) {
            if (size(x) && is_iterable<decltype(*(begin(x)))>) { 
                // Iterable inside Iterable
                int f = 0;
                int w = max(0, (int)log10(size(x) - 1)) + 2;
                cerr << "\n~~~~~~~~\n";
                for (auto &&i : x) {
                    cerr << setw(w) << left << f++, print(i), cerr << "\n";
                }
                cerr << "~~~~~~~~\n";
            } 
            else { 
                // Normal Iterable
                int f = 0;
                cerr << "{";
                for (auto &&i : x) {
                    cerr << (f++ ? ", " : ""), print(i);
                }
                cerr << "}";
            }
        } 
        else if constexpr (requires { x.pop(); }) {
            auto temp = x;
            int f = 0;
            cerr << "{";
            if constexpr (requires { x.top(); }) {
                // Stack, Priority Queue
                while (!temp.empty()) {
                    cerr << (f++ ? ", " : ""), print(temp.top()), temp.pop();
                }
            } 
            else {
                // Queue
                while (!temp.empty()) {
                    cerr << (f++ ? ", " : ""), print(temp.front()), temp.pop();
                }
            }
            cerr << "}";
        } 
        else if constexpr (requires { x.first; x.second; }) {
            // Pair
            cerr << "(", print(x.first), cerr << ", ", print(x.second), cerr << ")";
        } 
        else if constexpr (requires { get<0>(x); }) {
            // Tuple
            int f = 0;
            cerr << "("; 
            apply([&f](auto... args) {
                ((cerr << (f++ ? ", " : ""), print(args)), ...);
            }, x);
            cerr << ")";
        } 
        else {
            cerr << x;
        }
    }

    template <typename T>
    void print(T *p) {
        // Pointers: address and, if not null, pointed value
        if (!p) {
            cerr << "(nullptr)";
        } 
        else {
            cerr << "(" << p << ") -> ";
            print(*p);
        }
    }

    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
        int i = 0;
        for (int bracket = 0; names[i] != '\0' && (names[i] != ',' || bracket != 0); i++) {
            if (names[i] == '(' || names[i] == '<' || names[i] == '{') {
                bracket++;
            }
            else if (names[i] == ')' || names[i] == '>' || names[i] == '}') {
                bracket--;
            }
        }
        cerr << var_name;
        cerr.write(names, i) << outer << " = " << var_value;
        print(head);
        if constexpr (sizeof...(tail)) {
            cerr << outer << " ||";
            printer(names + i + 1, tail...);
        }
    }
}

void solve() {
    pair<int, bool> x1 = {1, false};
    pair<char, string> x2 = {'a', "mmd"};
    vector<int> v = {1, 2, 3, 4};
    dbg(x1, x2, v);

    int a = 100;
    int *p = &a;
    int **pp = &p;
    dbg(p, pp);

    vector<vector<vector<int>>> vv;
    vv = {{{111, 112}, {121, 122}}, {{211, 212}, {221, 222}}};
    dbg(vv);
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
