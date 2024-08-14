#include <bits/stdc++.h>
using namespace std;

// cin/cout + unsync + '\n' -> 0.41s
// fread/fwrite + '\n' -> 0.17s
inline namespace Input {
    const int BUF_SZ = 1 << 15;
    char buf[BUF_SZ];
    int pos, len;

    char next_char() {
        if (pos == len) {
            pos = 0;
            len = (int)fread(buf, 1, BUF_SZ, stdin);
            if (!len) { 
                return EOF; 
            }
        }
        return buf[pos++];
    }

    int read_int() {
        char ch;
        int x, sgn = 1;
        while (!isdigit(ch = next_char())) {
            if (ch == '-') { 
                sgn *= -1; 
            }
        }
        x = ch - '0';
        while (isdigit(ch = next_char())) { 
            x = x * 10 + (ch - '0'); 
        }
        return x * sgn;
    }
}
inline namespace Output {
    const int BUF_SZ = 1 << 15;
    char buf[BUF_SZ];
    int pos;

    void flush_out() {
        fwrite(buf, 1, pos, stdout);
        pos = 0;
    }

    void write_char(char c) {
        if (pos == BUF_SZ) { 
            flush_out(); 
        }
        buf[pos++] = c;
    }

    void write_int(int x) {
        static char num_buf[100];
        if (x < 0) {
            write_char('-');
            x *= -1;
        }
        int len = 0;
        for (; x >= 10; x /= 10) { 
            num_buf[len++] = (char)('0' + (x % 10)); 
        }
        write_char((char)('0' + x));
        while (len) { 
            write_char(num_buf[--len]); 
        }
    }

    // auto-flush output when program exits
    void init_output() { 
        assert(atexit(flush_out) == 0); 
    }
}

void solve() {
    int n = read_int();
    for (int i = 0; i < n; i++) {
        int a = read_int();
        write_int(a);
        write_char('\n');
    }
}

int32_t main() {
    init_output();

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
