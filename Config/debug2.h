#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#define dbgarr(x, s) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print_(x, s); cerr << "\e[39m" << endl;
#define LINE cerr << "\e[91m" << "____________________" << "\e[39m" << endl << endl;
#define TIME cerr << "\e[91m" << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << "\e[39m" << endl;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned int x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? 'T' : 'F'); } 

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{'; 
    __print(x.first); 
    cerr << ", "; 
    __print(x.second); 
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0; 
    cerr << '{'; 
    for (auto &i: x) {
        cerr << (f++ ? ", " : ""); 
        __print(i); 
    }
    cerr << '}';

}

void _print() {
    cerr << "]\n";
}

template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t); 
    if (sizeof...(v)) {
        cerr << ", "; 
    }
    _print(v...);
}

template <typename T>
void _print_(const T &x, int s) {
    int f = 0; 
    cerr << '{'; 
    while (s--) {
        cerr << (f++ ? ", " : ""); 
        cerr << x[f - 1]; 
    }
    cerr << '}'; 
    _print(); 
}
