#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

#define mod %
#define int long long 

const int M = 1e9 + 7;
const int N = 1e6 + 5;

using namespace std;

int n, t;
int s[N + 10], fact[N + 10], finv[N + 10], res;
int tot, klen;

namespace Math
{
    int qpow(int a, int k, int p)
    {
        int res = 1 mod p;

        while(k)
        {
            if(k & 1)
                res = res * a mod p;
            
            a = a * a mod p;

            k >>= 1;
        }

        return res;
    }
}
using namespace Math;

int get_k(int l)
{
    return l / klen;
}

struct Query
{
    int l, r;
    int id, res;

    friend bool operator <(Query x, Query y)
    {
        if(get_k(x.l) != get_k(y.l))
            return get_k(x.l) < get_k(y.l);
        else
            return x.r < y.r;
    }
}q[N];

bool cmp(Query x, Query y)
{
    return x.id < y.id;
}

int ms(int res)
{
    return (res mod M + M) mod M;
}

// void add_l(int& l, int r)
// {
//     res = (res * 2 - (fact[l] * finv[r] mod M * finv[l - r] mod M));
//     res = ms(res);

//     l ++;
// }

// void add_r(int l, int& r)
// {
//     r ++;
//     res = ms(res + fact[l] * finv[r] mod M * finv[l - r] mod M);
// }

// void del_l(int& l, int r)
// {
//     l --;
//     // res = ms(fact[l] * finv[r] mod M * finv[l - r] mod M)
//     res = ((res - fact[l] * finv[r] mod M * finv[l - r] mod M) mod M) * ((M + 1) >> 1) mod M;
// }

// void del_r(int l, int& r)
// {
//     res = ms(res + fact[l] * finv[r] mod M * finv[l - r] mod M);
//     r --;
// }

int binom(int x, int y) {
    // cout << x << ' ' << y << ' ' << fact[x] << ' ' << finv[y] << ' ' << finv[x-y] << endl;
    return fact[x] * finv[y] % M * finv[x - y] % M;
}

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
    res *= ((M + 1) >> 1);
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

void init()
{
    fact[0] = 1;

    for(int i = 1; i <= N; i ++)
        fact[i] = (fact[i - 1] * i) mod M;
    
    finv[N] = qpow(fact[N], 1e9 + 5, M);

    for(int i = N; i >= 1; i --)
        finv[i - 1] = (finv[i] * i) mod M;
}

signed main()
{
    init();

    cin >> n >> t;

    for(int i = 1; i <= n; i ++)
    {
        int tmp;
        cin >> tmp;

        s[i] = s[i - 1] + tmp;
    }

    for(int i = 1; i <= n; i ++)
    {
        int rem = t - s[i];

        if(rem < 0)
            break;
        else if(rem >= i)
            ++ res;
        else
            q[++ tot] = {i, rem, i};
    }

    int l = 1, r = 0;
    klen = sqrt(tot);

    sort(q + 1, q + tot + 1);

    for(int i = 1; i <= tot; i ++)
    {
        int ll = q[i].l, rr = q[i].r, ii = q[i].id;

        while(l < ll) add_l(l, r);
        while(l > ll) del_l(l, r);
        while(r < rr) add_r(l, r);
        while(r > rr) del_r(l, r);

        q[i].res = res;
    }
    sort(q + 1, q + tot + 1, cmp);

    for(int i = 1; i <= tot; i ++)
    {
        res += q[i].res * qpow(2, q[i].id * (M - 2) mod M, M) mod M;
        ms(res);
    }

    cout << res << endl;

    return 0;
}