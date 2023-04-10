#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int L = 3e5 + 5, LM = 1e5 + 5;
char s[L], t[LM];
int l, lm, n, m, dif[L];
ll base = 131, has[L], po[L], ans;

ll get(int l, int r) {
    return has[r] - has[l - 1] * po[r - l + 1];
}

int check(int x) {
    int res = 0;
    for (int i = 1; i <= x; ++i) {
        memset(dif, 0, sizeof(dif));
        for (int j = 1; j <= l; ++j) {
            if (s[j] != t[(j - i) % x + 1]) {
                dif[j] = 1;
            }
        }
        for (int j = 1; j <= l; ++j) {
            dif[j] += dif[j - 1];
        }
        int ok = 0;
        for (int j = 0; j < x; ++j) {
            if (dif[j + l - x] - dif[j] <= m) {
                ok = 1;
                break;
            }
        }
        res += ok;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> lm >> n >> m;
    for (int i = 1; i <= l; ++i) {
        cin >> s[i];
        has[i] = has[i - 1] * base + s[i];
    }
    po[0] = 1;
    for (int i = 1; i <= l; ++i) {
        po[i] = po[i - 1] * base;
    }

    for (int i = 1; i <= lm; ++i) {
        ans = ans * base + 'a';
    }

    for (int i = 1; i <= lm; ++i) {
        for (int j = 1; j <= i; ++j) {
            t[j] = s[j];
        }
        if (check(i)) {
            ans = min(ans, get(1, i));
        }
    }

    cout << ans << '\n';
    return 0;
}