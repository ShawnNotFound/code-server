#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAXN = 100001;

ll qpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    int n, p, q, s;
    cin >> n >> p >> q >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll q_inv = qpow(q, MOD - 2);
    ll p_q_inv = (ll)p * q_inv % MOD;
    ll q_pow_n_inv = qpow(1 - p_q_inv + MOD, MOD - 2);

    ll ans = 0;
    if (p * (p + s) % q != 0) {
        int first_output_way = 1;
        cout << first_output_way << endl;
        double ans_exp = 0;
        for (int i = 0; i < n; ++i) {
            ans_exp += a[i];
        }
        for (int i = 1; i < p + s; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = p * i - p + q;
                int down = q * (p + s);
                double e = (double)up / down;
                ans_exp += (double)p * a[j] / down + a[j] * qpow((1 - e + MOD) % MOD, -1) % MOD;
            }
        }
        cout << fixed << setprecision(10) << ans_exp << endl;
    } else {
        int second_output_way = 2;
        cout << second_output_way << endl;
        for (int i = 0; i < n; ++i) {
            ans = (ans + a[i] * (1 + q_pow_n_inv) % MOD) % MOD;
        }
        for (int i = 1; i < p + s; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = p * i - p + q;
                int down = q * (p + s);
                double e = (double)up / down;
                ans = (ans + p * a[j] % down + a[j] * qpow((1 - e + MOD) % MOD, -1) % MOD) % MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
