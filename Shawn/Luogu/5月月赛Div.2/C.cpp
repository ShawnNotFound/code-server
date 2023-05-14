#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 300010;
int T, n, k, a[MAXN], pos[MAXN], L[MAXN], R[MAXN];
bool vis[MAXN];

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

void get_support(int d, int &x, int &y) {
    for (int i = 1; i <= n; i++) {
        if (gcd(a[i], a[i % n + 1]) == d) {
            if (!x) x = i;
            y = i;
        }
    }
}

void get_chain(int x, int d) {
    for (int i = x; ; i += d) {
        if (vis[i]) break;
        vis[i] = true;
        R[L[i]] = i;
        L[R[i]] = i;
    }
}

bool check(int d) {
    fill(vis + 1, vis + n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(a[i], a[i % n + 1]) == d && !vis[i]) {
            cnt++;
            int x = 0, y = 0;
            get_support(d, x, y);
            get_chain((i - x % d + d) % d + x, d);
            get_chain((y - x % d + d) % d + x, d);
        }
    }
    return cnt >= k;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) pos[a[i]] = i;
        for (int d = n; d >= 1; d--) {
            if (check(d)) {
                puts("Yes");
                int cur = 0;
                for (int i = 1; i <= n; i++) {
                    if (!cur) cur = R[0];
                    printf("%d ", a[cur]);
                    cur = R[cur];
                }
                puts("");
                goto END;
            }
        }
        puts("No");
        END:;
    }
    return 0;
}
