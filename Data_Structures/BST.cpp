#include <bits/stdc++.h>
using namespace std;

// TODO: comparator, iterator
// Binary Search Tree, Ω(log(n)), O(n)
template <typename T>
struct BST {
    struct Node {
        T key;
        Node *left, *right, *par;

        Node() : left(nullptr), right(nullptr), par(nullptr) {}
        Node(T _key) : key(_key), left(nullptr), right(nullptr), par(nullptr) {}

        void set_left(Node *node) {
            left = node;
            node->par = this;
        }
        void set_right(Node *node) {
            right = node;
            node->par = this;
        }
    };

    Node *root;

    BST() : root(nullptr) {}
    BST(const vector<T> &v) : root(nullptr) {
        for (auto x : v) {
            insert(x);
        }
    }

    Node* insert(Node *node, const T &_key) {
        if (node == nullptr) {
            return new Node(_key);
        }
        if (_key < node->key) {
            node->set_left(insert(node->left, _key));
        }
        else {
            node->set_right(insert(node->right, _key));
        }
        return node;
    }

    Node* erase(Node *node, const T &_key) {
        if (node == nullptr) {
            return node;
        }
        if (_key < node->key) {
            node->set_left(erase(node->left, _key));
        }
        else if (_key > node->key) {
            node->set_right(erase(node->right, _key));
        }
        else {
            if (node->left == nullptr) {
                Node *tmp = node->right;
                free(node);
                return tmp;
            }
            if (node->right == nullptr) {
                Node *tmp = node->left;
                free(node);
                return tmp;
            }
            Node *tmp = node->right;
            while (tmp != nullptr && tmp->left != nullptr) {
                tmp = tmp->left;
            }
            node->key = tmp->key;
            node->set_right(erase(node->right, tmp->key));
        }
        return node;
    }

    Node* find(Node *node, const T &_key) {
        if (node == nullptr) {
            return node;
        }
        if (_key < node->key) {
            return find(node->left, _key);
        }
        if (_key > node->key) {
            return find(node->right, _key);
        }
        return node;
    }

    int count(Node *node, const T &_key) {
        if (node == nullptr) {
            return 0;
        }
        if (_key < node->key) {
            return count(node->left, _key);
        }
        if (_key > node->key) {
            return count(node->right, _key);
        }
        return count(node->left, _key) + count(node->right, _key) + 1;
    }

    void insert(const T &_key) {
        root = insert(root, _key);
    }

    void erase(const T &_key) {
        root = erase(root, _key); 
    }
    
    Node* find(const T &_key) {
        return find(root, _key);
    }

    bool contains(const T &_key) {
        return find(_key) != nullptr;
    }
    
    int count(const T &_key) {
        return count(root, _key);
    }
};

void solve() {
    vector<int> v = {1, 2, 10, 20, 11, 12};        
    BST bst(v);
    bst.insert(100);
    bst.erase(1);
    cout << bst.contains(100) << ' ' << bst.contains(1) << '\n';
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
