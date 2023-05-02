#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>

#define int __int128


#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif

using namespace std;
 
template <typename T> void input(T &x)
{
    x = 0; char c = getchar(); bool f = false;
    while (c < '0' or c > '9')
    	f |= (c == '-'), c = getchar();
    while  (c >= '0' and c <= '9')
    	x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    x = f ? -x : x;
}

template <typename T, typename... Args>
void input(T &x, Args&... args)
{
    input(x), input(args...);
}

template <typename T>
void output(T x, char ed = ' ')
{
	if (x < 0) putchar('-'), x = -x;
    static short st[64], top;
    top = 0;
    do st[top ++] = x % 10, x /= 10; while (x);
    while (top --) putchar(st[top] ^ '0');
    putchar(ed);
}
template <typename T, typename ...Args>
void output(T x, char ch = ' ', Args... args) {
    output(x, ch);
    output(args...);
}

// namespace BSGS
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

//     int bsgs(int y, int z, int p)
//     {
//         map<int, int> hash;
//         z %= p;
//         int t = sqrt(p) + 1;

//         for(int i = 0; i < t; i ++)
//             hash[z * qpow(y, i, p) % p] = i;
        
//         y = qpow(y, t, p);

//         if(!y)
//             return z == 0 ? 1 : -1;

//         for(int i = 1; i <= t; i ++)
//         {
//             int val = qpow(y, i, p);

//             if(hash.count(val))
//             {
//                 int j = hash[val];
//                 if(i * t - j >= 0)  
//                     return i * t - j;
//             }
//         }

//         return -1;
//     }

// }

namespace BSGS
{
    int qpow(int m, int k, int p)
    {
        int res = 1 % p, t = m;

        while(k)
        {
            if(k & 1)
                res = res * t % p;
            t = t * t % p;
            k >>= 1;
        }

        return res;
    }

    int bsgs(int y, int z, int p) 
    {
        map<int, int> hash;
        z %= p;
        int t = ceil(sqrt((double)p)) + 1;

        for (int i = 0; i < t; i ++)
            hash[z * qpow(y, i, p) % p] = i;

        y = qpow(y, t, p);

        if(!y)
            return z == 0 ? 1 : -1;

        for (int i = 1; i <= t; i ++) 
        {
            int val = qpow(y, i, p);

            if (hash.count(val)) 
            {
                int j = hash[val];
                if (i * t - j >= 0) return i * t - j;
            }
        }

        return -1;
    }
}

using namespace BSGS;

signed main()
{
    int z, p;

    //cin >> z >> p;
    input(z, p);

    z = z * 9 + 1;

    z %= p;

    int ans = bsgs(10, z, p);

    //cout << ans << endl;
    output(ans, '\n');

    return 0;    
}