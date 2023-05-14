#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 985661441;
const int MAXN = 5005;

int n;
vector<int> adj[MAXN];
int sz[MAXN];
int inv[MAXN];

int quick_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = 1LL * res * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int f;
        cin >> f;
        adj[f].push_back(i);
    }

    dfs(1, 0);

    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = (ans + 1LL * (sz[i] - 1) * inv[n - 1] % MOD) % MOD;
    }

    ans = 1LL * ans * quick_pow(n, MOD - 2) % MOD;
    cout << ans << endl;

    return 0;
}