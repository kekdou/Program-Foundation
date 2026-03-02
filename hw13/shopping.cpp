// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// #define ll long long

// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<ll> val(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> val[i];
//     }
//     vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
//     for (int i = 1; i <= n; i++) {
//         ll max_prev = 0;
//         for (int j = 0; j <= k; j++) {
//             max_prev = max(max_prev, dp[i - 1][j]);
//         }
//         dp[i][0] = max_prev;
//         for (int j = 1; j <= k; j++) {
//             dp[i][j] = dp[i - 1][j - 1] + val[i];
//         }
//     }
//     ll res = 0;
//     for (int i = 0; i <= k; i++) {
//         res = max(res, dp[n][i]);
//     }
//     cout << res << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), S(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S[i] = S[i - 1] + a[i];
    }
    vector<ll> dp(n + 2, 0);
    deque<int> q;
    auto getValue = [&](int j) { return dp[j] - S[j]; };
    q.push_back(0);
    for (int i = 1; i <= n + 1; i++) {
        if (!q.empty() && q.front() < i - k - 1) {
            q.pop_front();
        }
        dp[i] = S[i - 1] + getValue(q.front());
        if (i <= n) {
            while (!q.empty() && getValue(q.back()) <= getValue(i)) {
                q.pop_back();
            }
            q.push_back(i);
        }
    }
    cout << dp[n + 1] << endl;
    return 0;
}