#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

#define MAX_N 205
#define MAX_M 205

using namespace std;

typedef long long ll;

int n, m, ans;
ll a[MAX_N][MAX_M], s[MAX_N][MAX_M], t[MAX_M];

inline ll read() {
    ll x = 0;
    bool w = true;
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') c = getchar(), w = false;
    while (isdigit(c)) {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return w ? x : -x;
}

// 检查是否存在长度为 len 的子序列满足要求
inline bool check(int len) {
    ll res = 0;
    for (int i = len; i <= m; i++) {
        res = min(res, t[i - len]);
        if (t[i] > res) return true;
    }
    return false;
}

// 获取最长子序列长度
inline int getLen() {
    int left = 1, right = m, len = 0;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {
            len = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + (a[i][j] = read());
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                t[k] = t[k - 1] + s[j][k] - s[i - 1][k];
            }
            ans = max(ans, (j - i + 1) * getLen());
        }
    }

    cout << ans << '\n';
    return 0;
}
