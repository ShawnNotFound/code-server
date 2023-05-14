// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<cmath>

// #define int long long
// #define mod %

// const int M = 1e9 + 7;

// using namespace std;

// namespace LUCAS
// {
//     int qpow(int m, int k, int p)
//     {
//         int res = 1 % p, t = m;

//         while(k)
//         {
//             if(k & 1)
//                 res = res * t % p;
//             t = t * t % p;
//             k >>= 1;
//         }

//         return res;
//     }

//     int C(int a, int b, int p)
//     {
//         if(a < b)   
//             return 0;

//         int x = 1, y = 1;

//         for(int i = a, j = 1; j <= b; i --, j ++)
//         {
//             x = x * j % p;
//             y = y * j % p;
//         }

//         return x * qpow(y, p - 2, p) % p;
//     }

//     int Lucas(int a, int b, int p)
//     {
//         if(a < p && b < p)
//             return C(a, b, p);

//         return C(a mod p, b mod p, p) * (a / p, b / p, p) mod p;
//     }
// }

// using namespace LUCAS;

// signed main()
// {
//     int T;
//     cin >> T;

//     while(T --)
//     {
//         int n, k, ans = 0, sum = 0;

//         cin >> n >> k;

//         for(int i = 0; i < n; i += 2)
//             sum = (sum + C(n, i, M)) mod M;
        
//         if(n & 1)
//             ans = (ans + qpow(sum + 1, k, M)) mod M;
//         else
//         {
//             for(int i = 0; i < k; i ++)
//                 ans = (ans + qpow(sum, i, M) * qpow(qpow(2, n, M), k - i - 1, M) mod M) mod M;
            
//             ans = (ans + qpow(sum, k, M)) % M;
//         }

//         cout << ans << endl;
//     }
//     return 0;

// }

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int N = 2e5 + 10;

int fac[N];
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
}
int quick_pow(int a, int k, int p) {
	int res = 1;
	a %= p;
	while (k) {
		if (k & 1) res = res * a % p;
		a = a * a % p;
		k >>= 1;
	}
	return res;
}
int inv(int x, int p) 
{
    return quick_pow(x, p - 2, p);
}
int getC(int n, int m, int p) 
{
    return fac[n] * inv(fac[n - m] * fac[m] % p, p) % p;
}

signed main() 
{
	init(N);

	int T;
    cin >> T;

	while (T--) 
    {
		int n, k, ans = 0, sum = 0;

        cin >> n >> k;

		for (int i = 0; i < n; i += 2) 
            sum = (sum + getC(n, i, mod)) % mod;

		if (n & 1) 
            ans = (ans + quick_pow(sum + 1, k, mod)) % mod;
		else 
        {
			for (int i = 0; i < k; i++) 
                ans = (ans + quick_pow(sum, i, mod) * quick_pow(quick_pow(2, n, mod), k - i - 1, mod) % mod) % mod;
			ans = (ans + quick_pow(sum, k, mod)) % mod;
		}
		cout << ans << endl;
	}

	return 0;
}