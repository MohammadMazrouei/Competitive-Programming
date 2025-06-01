#include <bits/stdc++.h>
using namespace std;

struct SegmentTree2D {
    struct node {
        int64_t sum = 0;
        int mn = 0;
        int cnt = 1;

        void apply(int v) {
            mn = v;
            sum = v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.cnt = (res.mn == a.mn ? a.cnt : 0) + (res.mn == b.mn ? b.cnt : 0);
        return res;
    }

    inline void pull_x(int x, int y) {
        tree[x][y] = unite(tree[x * 2][y], tree[x * 2 + 1][y]);
    }

    inline void pull_y(int x, int y) {
        tree[x][y] = unite(tree[x][y * 2], tree[x][y * 2 + 1]);
    }

    int n, m;
    vector<vector<node>> tree;

    void build_y(int x, int lx, int rx, int y, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx) {
                return;
            }
            else {
                pull_x(x, y);
            }
            return;
        } 
        int my = (ly + ry) / 2;
        build_y(x, lx, rx, y * 2, ly, my);
        build_y(x, lx, rx, y * 2 + 1, my + 1, ry);
        pull_y(x, y);
    }

    void build_x(int x, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(x * 2, lx, mx);
            build_x(x * 2 + 1, mx + 1, rx);
        }
        build_y(x, lx, rx, 1, 0, m - 1);
    }

    template <typename M>
    void build_y(int x, int lx, int rx, int y, int ly, int ry, const vector<vector<M>> &v) {
        if (ly == ry) {
            if (lx == rx) {
                tree[x][y].apply(v[lx][ly]);
            }
            else {
                pull_x(x, y);
            }
            return;
        } 
        int my = (ly + ry) / 2;
        build_y(x, lx, rx, y * 2, ly, my, v);
        build_y(x, lx, rx, y * 2 + 1, my + 1, ry, v);
        pull_y(x, y);
    }

    template <typename M>
    void build_x(int x, int lx, int rx, const vector<vector<M>> &v) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(x * 2, lx, mx, v);
            build_x(x * 2 + 1, mx + 1, rx, v);
        }
        build_y(x, lx, rx, 1, 0, m - 1, v);
    }

    void modify_y(int x, int lx, int rx, int y, int ly, int ry, int px, int py, const int v) {
        if (ly == ry) {
            if (lx == rx) {
                tree[x][y].apply(v);
            }
            else {
                pull_x(x, y);
            }
        } 
        else {
            int my = (ly + ry) / 2;
            if (py <= my) {
                modify_y(x, lx, rx, y * 2, ly, my, px, py, v);
            }
            else {
                modify_y(x, lx, rx, y * 2 + 1, my + 1, ry, px, py, v);
            }
            pull_y(x, y);
        }
    }

    void modify_x(int x, int lx, int rx, int px, int py, const int v) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (px <= mx) {
                modify_x(x * 2, lx, mx, px, py, v);
            }
            else {
                modify_x(x * 2 + 1, mx + 1, rx, px, py, v);
            }
        }
        modify_y(x, lx, rx, 1, 0, m - 1, px, py, v);
    }

    node get_y(int x, int y, int ly, int ry, int lly, int rry) {
        if (lly <= ly && ry <= rry) {
            return tree[x][y];
        }
        int my = (ly + ry) / 2;
        if (my >= rry) {
            return get_y(x, y * 2, ly, my, lly, rry);
        }
        else if (my < lly) {
            return get_y(x, y * 2 + 1, my + 1, ry, lly, rry);
        }
        return unite(get_y(x, y * 2, ly, my, lly, rry), get_y(x, y * 2 + 1, my + 1, ry, lly, rry));
    }

    node get_x(int x, int lx, int rx, int llx, int rrx, int lly, int rry) {
        if (llx <= lx && rx <= rrx) {
            return get_y(x, 1, 0, m - 1, lly, rry);
        }
        int mx = (lx + rx) / 2;
        if (mx >= rrx) {
            return  get_x(x * 2, lx, mx, llx, rrx, lly, rry);
        }
        else if (mx < llx) {
            return get_x(x * 2 + 1, mx + 1, rx, llx, rrx, lly, rry);
        }
        return unite(get_x(x * 2, lx, mx, llx, rrx, lly, rry), get_x(x * 2 + 1, mx + 1, rx, llx, rrx, lly, rry));
    }

    SegmentTree2D(int _n, int _m) : n(_n), m(_m) {
        assert(n > 0 && m > 0);
        tree.assign(4 * n, vector<node>(4 * m));
        build_x(1, 0, n - 1);
    }

    template <typename M>
    SegmentTree2D(const vector<M> &v) {
        n = v.size();
        m = v[0].size();
        assert(n > 0 && m > 0);
        tree.assign(4 * n, vector<node>(4 * m));
        build_x(1, 0, n - 1, v);
    }

    node get(int llx, int rrx, int lly, int rry) {
        assert(0 <= llx && llx <= rrx && rrx <= n - 1);
        assert(0 <= lly && lly <= rry && rry <= m - 1);
        return get_x(1, 0, n - 1, llx, rrx, lly, rry);
    }

    node get(int px, int py) {
        assert(0 <= px && px <= n - 1);
        assert(0 <= py && py <= m - 1);
        return get_x(1, 0, n - 1, px, px, py, py);
    }

    void modify(int px, int py, const int v) {
        assert(px >= 0 && px <= n - 1);
        assert(py >= 0 && py <= m - 1);
        modify_x(1, 0, n - 1, px, py, v);
    }
};

void solve() {
        
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
