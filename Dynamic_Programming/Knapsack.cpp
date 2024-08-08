#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

// 0-1 Knapsack, O(n*W)
int knapsack(int n, int W, vector<int> &profits, vector<int> &weights) {
    vector<int> dp(W + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + profits[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Complete Knapsack, O(n*W)
int complete_knapsack(int n, int W, vector<int> &profits, vector<int> &weights) {
    vector<int> dp(W + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = weights[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - weights[i]] + profits[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Multiple Knapsack, O(n*W)
int multiple_knapsack(int n, int W, vector<int> &profits, vector<int> &weights, vector<int> &limits) {
    vector<int> dp(W + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < weights[i]; j++) {
            int alpha = 0;
            queue<int> q;
            deque<int> peek;
            for (int w = j; w <= W; w += weights[i]) {
                alpha += profits[i];
                int a = dp[w] - alpha;
                q.push(a);
                while (!peek.empty() && peek.back() < a) {
                    peek.pop_back();
                }
                peek.push_back(a);
                while ((int)q.size() > limits[i] + 1) {
                    if (q.front() == peek.front()) {
                        peek.pop_front();
                    }
                    q.pop();
                }
                dp[w] = peek.front() + alpha;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

void solve() {
    int n, W;
    n = 10, W = 100;

    vector<int> profits(n), weights(n), limits(n);
    for (int i = 0; i < n; i++) {
        profits[i] = rand() % n + 1;
        weights[i] = rand() % n + 1;
        limits[i] = rand() % n + 1;
        cout << i + 1 << ": " << profits[i] << ' ' << weights[i] << ' ' << limits[i] << '\n';
    }

    cout << knapsack(n, W, profits, weights) << '\n';
    cout << complete_knapsack(n, W, profits, weights) << '\n';
    cout << multiple_knapsack(n, W, profits, weights, limits) << '\n';
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
