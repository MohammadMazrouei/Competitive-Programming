#include <bits/stdc++.h>
using namespace std;

// Treap, Max Heap
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
struct Treap {
    struct Node {
        T key;
        int prior, sz, left, right, par;

        Node (T _key) : key(_key), prior(rng()), sz(1), left(-1), right(-1), par(-1) {}
        Node (T _key, int _prior) : key(_key), prior(_prior), sz(1), left(-1), right(-1), par(-1) {}
    };

    int root;
    vector<Node> tree;

    Treap() : root(-1) {}
    Treap(int n) : root(-1) {
        tree.reserve(n);
    }
    // Construction with sorted keys, O(n)
    Treap(vector<T> &keys) {
        int n = keys.size();
        tree.reserve(n);
        root = build(keys, 0, n - 1);
    }
    // Construction with sorted keys & priors, O(n)
    Treap(vector<T> &keys, vector<int> &priors) {
        assert(keys.size() == priors.size());
        int n = keys.size();
        tree.reserve(n);
        root = build(keys, priors);
        pull_size(root);
    }

    int build(vector<T> &keys, int lo, int hi) {
        if (lo > hi) {
            return -1;
        }
        int mid = lo + (hi - lo) / 2;
        int x = new_node(keys[mid]);
        tree[x].left = build(keys, lo, mid - 1);
        tree[x].right = build(keys, mid + 1, hi);
        heapify(x);
        pull(x);
        return x;
    }

    void heapify(int x) {
        if (x == -1) {
            return;
        }
        int mx = x;
        if (tree[x].left != -1 && tree[tree[x].left].prior > tree[mx].prior) {
            mx = tree[x].left;
        }
        if (tree[x].right != -1 && tree[tree[x].right].prior > tree[mx].prior) {
            mx = tree[x].right;
        }
        if (mx != x) {
            swap(tree[x].prior, tree[mx].prior);
            heapify(mx);
        }
    }

    int build(vector<T> &keys, vector<int> &priors) {
        int n = keys.size();
        for (int i = 0; i < n; i++) {
            tree.push_back(Node(keys[i], priors[i]));
        }
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && tree[st.back()].prior < tree[i].prior) {
                st.pop_back();
            }
            if (!st.empty() && (tree[i].par == -1 || tree[tree[i].par].prior > tree[st.back()].prior)) {
                tree[i].par = st.back();
            }
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && tree[st.back()].prior < tree[i].prior) {
                st.pop_back();
            }
            if (!st.empty() && (tree[i].par == -1 || tree[tree[i].par].prior > tree[st.back()].prior)) {
                tree[i].par = st.back();
            }
            st.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (tree[i].par != -1) {
                if (tree[tree[i].par].key < tree[i].key) {
                    tree[tree[i].par].right = i;
                } 
                else {
                    tree[tree[i].par].left = i;
                }
            }
        }
        return n ? min_element(priors.begin(), priors.end()) - priors.begin() : -1;
    }

    void pull_size(int x) {
        if (x == -1) {
            return;
        }
        if (tree[x].left != -1) {
            pull_size(tree[x].left);
        }
        if (tree[x].right != -1) {
            pull_size(tree[x].right);
        }
        pull(x);
    }

    inline void pull(int x) {
        tree[x].sz = size(tree[x].left) + size(tree[x].right) + 1;
    }

    int size(int x) const {
        return (x == -1 ? 0 : tree[x].sz);
    }

    int new_node(T key, int prior = rng()) {
        int id = int(tree.size());
        tree.push_back(Node(key, prior));
        return id;
    }

    inline void add_right(int x, int right) {
        tree[x].right = right;
        if (right != -1) {
            tree[right].par = x;
        }
    }

    inline void add_left(int x, int left) {
        tree[x].left = left;
        if (left != -1) {
            tree[left].par = x;
        }
    }

    pair<int, int> split_by_key(int x, T key) {
        if (x == -1) {
            return {x, x};
        }
        if (tree[x].key <= key) {
            auto cur = split_by_key(tree[x].right, key);
            add_right(x, cur.first);
            pull(x);
            return {x, cur.second};
        } 
        else {
            auto cur = split_by_key(tree[x].left, key);
            add_left(x, cur.second);
            pull(x);
            return {cur.first, x};
        }
    }

    pair<int, int> split_by_size(int x, int n) {
        if (x == -1) {
            return {x, x};
        }
        if (size(tree[x].left) + 1 <= n) {
            auto cur = split_by_size(tree[x].right, n - size(tree[x].left) - 1);
            add_right(x, cur.first);
            pull(x);
            return {x, cur.second};
        } 
        else {
            auto cur = split_by_size(tree[x].left, n);
            add_left(x, cur.second);
            pull(x);
            return {cur.first, x};
        }
    }

    int merge(int left, int right) {
        if (left == -1 || right == -1) {
            return left != -1 ? left : right;
        }
        if (tree[left].prior > tree[right].prior) {
            add_right(left, merge(tree[left].right, right));
            pull(left);
            return left;
        } 
        else {
            add_left(right, merge(left, tree[right].left));
            pull(right);
            return right;
        }
    }
 
    int insert(int x, T key, int id) {
        if (x == -1) {
            return id;
        }
        if (tree[id].prior < tree[x].prior) {
            if (key < tree[x].key) {
                add_left(x, insert(tree[x].left, key, id));
            }
            else {
                add_right(x, insert(tree[x].right, key, id));
            }
            pull(x);
            return x;
        } 
        else {
            auto [left, right] = split_by_key(x, key);
            add_left(id, left);
            add_right(id, right);
            pull(id);
            return id;
        }
    }
 
    int erase(int x, T key) {
        if (x == -1) {
            return -1;
        }
        if (tree[x].key == key) {
            return merge(tree[x].left, tree[x].right);
        }
        if (key < tree[x].key) {
            add_left(x, erase(tree[x].left, key));
        }
        else {
            add_right(x, erase(tree[x].right, key));
        }
        pull(x);
        return x;
    }

    T at(int x, int pos) {
        if (size(tree[x].left) > pos) {
            return at(tree[x].left, pos);
        }
        pos -= size(tree[x].left);
        if (!pos) {
            return tree[x].key;
        }
        return at(tree[x].right, pos - 1);
    }

    int find(int x, T key) {
        if (x == -1) {
            return 0;
        }
        if (tree[x].key >= key) {
            return find(tree[x].left, key);
        }
        else {
            return size(tree[x].left) + 1 + find(tree[x].right, key);
        }
    }

    bool contains(int x, T key) {
        if (x == -1) {
            return false;
        }
        if (tree[x].key == key) {
            return true;
        }
        if (tree[x].key < key) {
            return contains(tree[x].right, key);
        }
        return contains(tree[x].left, key);
    }

    int unite(int l, int r) {
        if (l == -1 || r == -1)  {
            return l != -1 ? l : r;
        }
        if (tree[l].prior < tree[r].prior)  {
            swap(l, r);
        }
        auto [lt, rt] = split_by_key(r, tree[l].key);
        add_left(l, unite(tree[l].left, lt));
        add_right(l, unite(tree[l].right, rt));
        return l;
    }
 
    void insert(T key) {
        int id = new_node(key);
        root = insert(root, key, id);
    }

    void insert(T key, int prior) {
        int id = new_node(key, prior);
        root = insert(root, key, id);
    }
 
    void erase(T key) {
        root = erase(root, key);
    }
 
    int size() const {
        return size(root);
    }

    T at(int pos) {
        assert(pos >= 0 && pos < size());
        return at(root, pos);
    }

    // Return number of elements smaller than key
    int find(T key) {
        return find(root, key);
    }

    bool contains(T key) {
        return contains(root, key);
    }

    // Unite 2 Treaps, O(m*log(n / m))
    void unite(Treap<T> &t) {
        int n = size();
        for (int i = 0; i < t.size(); i++) {
            tree.push_back(t.tree[i]);
        }
        root = unite(root, n);
    }
};

void solve() {
    int n;
    cin >> n;

    // Keys must be sorted
    vector<int> keys(n), priors(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i] >> priors[i];;
    }

    Treap<int> treap1(keys);
    Treap<int> treap2(keys, priors);
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
