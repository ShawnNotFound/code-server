#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e3 + 10;

using namespace std;

int f[N], map[N];
bool tiu[N];
int n = 1, maxn = 1, maxi, ans = 1;

struct noooooooo
{
    int dat;
    bool iu[N];
}a[N];

void init()
{
    for(int i = 1; i <= n; i ++)
        f[i] = 1;
}

void inita()
{
    maxn = 1;
    for(int i = 1; i <= n; i ++)
    {
        a[i].dat = 1;
        for(int j = 1; j <= n; j ++)
            a[i].iu[j] = false;
    }    
}

void solve2()
{
    inita();
    for(int i = 1; i <= n; i ++)
    {
        if(!tiu[i]) continue;
        for(int j = i; j >= 1; j --)
        {
            if(!tiu[j]) continue;
            if(map[i] < map[j])
            {
                if(a[i].dat < a[j].dat + 1)
                {
                    a[i].dat = a[j].dat + 1;
                    for(int k = 1; k <= n; k ++)
                        a[i].iu[k] |= a[j].iu[k]; 
                }
                if(a[i].dat > maxn)
                {
                    maxn = a[i].dat;
                    maxi = i;
                }
            }
        }
    }

    for(int i = 1; i <= n; i ++)
        tiu[N] |= a[maxi].iu[i];

    for(int i = 1; i <= n; i ++)
        if(!tiu[i]) 
        {
            solve2();
            ans ++;
        }

    return;
}

int main()
{
    while(cin >> map[n]) n ++;
    n --;
    
    init();
    for(int i = 1; i <= n; i ++)
        for(int j = i; j >= 1; j --)
        {
            if(map[i] < map[j])
            {
                f[i] = max(f[i], f[j] + 1);
                maxn = max(maxn, f[i]);
            }
        }
        
    // for(int i = 1; i <= n; i ++)
    //     cout << f[i] << " ";
    // cout << endl;

    cout << maxn << endl;

    solve2();

    cout << ans << endl;

    return 0;
}

// #include<iostream>
// #include<cmath>
// #include<algorithm>
// #include<cstring>

// const int N = 1e3 + 10;

// using namespace std;

// int f[N], map[N];
// bool tiu[N];
// int n = 1, maxn = 1, maxi, ans = 0, cnt = 0, g[N];

// // struct noooooooo
// // {
// //     int dat;
// //     bool iu[N];
// // }a[N];

// void init()
// {
//     for(int i = 1; i <= n; i ++)
//         f[i] = 1;
// }

// // void inita()
// // {
// //     maxn = 1;
// //     for(int i = 1; i <= n; i ++)
// //     {
// //         a[i].dat = 1;
// //         for(int j = 1; j <= n; j ++)
// //             a[i].iu[j] = false;
// //         a[i].iu[i] = true;
// //     }    
// // }

// // void solve2()
// // {
// //     inita();
// //     for(int i = 1; i <= n; i ++)
// //     {
// //         if(tiu[i]) continue;
// //         for(int j = i; j >= 1; j --)
// //         {
// //             if(tiu[j]) continue;
// //             if(map[i] < map[j])
// //             {
// //                 if(a[i].dat < a[j].dat + 1)
// //                 {
// //                     a[i].dat = a[j].dat + 1;
// //                     for(int k = 1; k <= n; k ++)
// //                         a[i].iu[k] |= a[j].iu[k]; 
// //                 }
// //                 if(a[i].dat > maxn)
// //                 {
// //                     maxn = a[i].dat;
// //                     maxi = i;
// //                 }
// //             }
// //         }
// //     }

// //     // for(int i = 1; i <= n; i ++)
// //     //     cout << a[maxi].iu[i] << " ";
// //     // cout << endl;

// //     for(int i = 1; i <= n; i ++)
// //         tiu[i] |= a[maxi].iu[i];

// //     for(int i = 1; i <= n; i ++)
// //         if(!tiu[i]) 
// //         {
// //             solve2();
// //             ans ++;
// //             break;
// //         }
        
// //     // for(int i = 1; i <= n; i ++)
// //     //     cout << tiu[i] << " ";
        
// //     // cout << endl;

// //     return;
// // }

// int main()
// {
//     while(cin >> map[n]) n ++;
//     n --;
    
//     //init();
//     for(int i = 1; i <= n; i ++)
//     {
//         f[i] = 1;
//         for(int j = 1; j <= i; j ++)
//         {
//             if(map[i] < map[j])
//             {
//                 f[i] = max(f[i], f[j] + 1);
//             }
//             maxn = max(maxn, f[i]);
//             int p = lower_bound(g, g + cnt, map[i]) - g;
//             if(p == cnt)
//                 g[cnt ++] = map[i];
//             else g[p] = map[i];
//         }
//     }
        
//     for(int i = 1; i <= n; i ++)
//         cout << f[i] << " ";
//     cout << endl;

//     cout << maxn << endl;

//     // solve2();

//     cout << cnt << endl;

//     return 0;
// }
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1005;
int n = 1, a[maxn];
int f[maxn], g[maxn];

int main()
{
    while(cin >> a[n]) n ++;
    int ans1 = 0;
    int ans2 = 0;
    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        g[i] = 1;
        for(int j = 1; j <= i; j ++)
        {
            if(a[i] <= a[j]) f[i] = max(f[i], f[j] + 1);
            else g[i] = max(g[i], g[j] + 1);
        }
        ans1 = max(ans1, f[i]);
        ans2 = max(ans2, g[i]);
    }
    
    for(int i = 1; i <= n; i ++)
        cout << f[i] << " ";
    cout << endl;
    
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}