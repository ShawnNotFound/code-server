#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int M = 1e9 + 7, i2 = (M + 1) >> 1;
int n, t, sum[1000010], fact[1000010], finv[1000010], res;

int qp(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, (x *= x) %= M)
        if (y & 1)
            (res *= x) %= M;
    return res;
}

int binom(int x, int y) {
    // cout << x << ' ' << y << ' ' << fact[x] << ' ' << finv[y] << ' ' << finv[x-y] << endl;
    return fact[x] * finv[y] % M * finv[x - y] % M;
}

namespace Mo {
int res = 1, klen;
struct Qry {
    int l, r, id, res;
    // C(l, r)
    friend bool operator<(Qry x, Qry y) { return x.l / klen != y.l / klen ? x.l / klen < y.l / klen : x.r < y.r; }
};
bool re_sort_cmp(Qry x, Qry y) { return x.id < y.id; }
vector<Qry> qry;
void add_l(int& l, int r) {
    // cout << l << ' ' << r << ' ' << res << endl;
    res *= 2;
    res -= binom(l, r);
    (res += M) %= M;
    ++l;
}
void del_l(int& l, int r) {
    // cout << l << ' ' << r << ' ' << res << endl;
    --l;
    res += binom(l, r);
    res %= M;
    res *= i2;
    res %= M;
}
void add_r(int l, int& r) {
    // cout << l << ' ' << r << ' ' << res << endl;
    res += binom(l, ++r);
    res %= M;
}
void del_r(int l, int& r) {
    // cout << l << ' ' << r << ' ' << res << endl;
    res -= binom(l, r--);
    res %= M;
    res += M;
    res %= M;
}
void add_q(int l, int r, int id) { qry.push_back({ l, r, id }); }
void solve() {
    int l = 1, r = 0;
    klen = sqrt(qry.size());
    sort(qry.begin(), qry.end());
    for (auto& v : qry) {
        int L = v.l, R = v.r, ID = v.id;
        while (l < L) add_l(l, r);
        while (l > L) del_l(l, r);
        while (r < R) add_r(l, r);
        while (r > R) del_r(l, r);
        v.res = res;
    }
    sort(qry.begin(), qry.end(), re_sort_cmp);
}
}  // namespace Mo

signed main() {
    fact[0] = 1;
    for (int i = 1; i <= 1000005; i++) fact[i] = fact[i - 1] * i % M;
    finv[1000005] = qp(fact[1000005], 1e9 + 5);
    for (int i = 1000005; i >= 1; i--) finv[i - 1] = finv[i] * i % M;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    for (int i = 1; i <= n; i++) {
        int rem = t - sum[i];
        if (rem < 0)
            break;
        else if (rem >= i)
            ++res;
        else {
            Mo::add_q(i, rem, i);
        }
    }
    Mo::solve();
    for (const auto& ott : Mo::qry) (res += ott.res * qp(2, ott.id * (M - 2)) % M) %= M;
    cout << res << endl;
}