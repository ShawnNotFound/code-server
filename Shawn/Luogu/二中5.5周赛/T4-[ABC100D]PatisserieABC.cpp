// #include<iostream>
// #include<cmath>
// #include<cstring>
// #include<algorithm>

// #define int long long

// const int N = 1e3 + 10;

// using namespace std;

// int tot[N], sum[N], s1[N], s2[N], s3[N], sum1[N], sum2[N], sum3[N];
// int n, m, ans;

// signed main()
// {
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;
//     for(int i = 1; i <= n; i ++)
//         cin >> s1[i] >> s2[i] >> s3[i];

//     for(int i = m; i <= n; i ++)
//         for(int j = 0; j <= m - 1; j ++)
//             sum1[i] += s1[i - j];

//     for(int i = m; i <= n; i ++)
//         for(int j = 0; j <= m - 1; j ++)
//             sum2[i] += s2[i - j];

//     for(int i = m; i <= n; i ++)
//         for(int j = 0; j <= m - 1; j ++)
//             sum3[i] += s3[i - j];

//     for(int i = 1; i <= n; i ++)
//     {
//         tot[i] = abs(sum1[i]) + abs(sum2[i]) + abs(sum3[i]);
//         ans = max(ans, tot[i]);
//     }

//     for(int i = 1; i <= n; i ++)
//         cout << tot[i] << " ";
//     cout << endl;

//     // for(int i = m; i <= n; i ++)
//     // {
//     //     for(int j = 0; j <= m - 1; j ++)
//     //         sum[i] += tot[i - j];
        
//     //     ans = max(ans, sum[i]);
//     // }

//     // for(int i = 1; i <= n; i ++)
//     //     cout << sum[i] << " ";
//     // cout << endl;

//     cout << ans << endl;

//     return 0;
// }



// #include<iostream>
// #include<cmath>
// #include<cstring>
// #include<algorithm>

// #define int long long

// const int N = 1e3 + 10;

// using namespace std;

// int tot[N], sum[N];
// int n, m, ans;

// signed main()
// {
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;
//     for(int i = 1; i <= n; i ++)
//     {
//         int ts1, ts2, ts3;

//         cin >> ts1 >> ts2 >> ts3;

//         tot[i] = abs(ts1) + abs(ts2) + abs(ts3);
//     }

//     sort(tot + 1, tot + m + 1);

//     for(int i = m; i <= n; i ++)
//     {
//         for(int j = 0; j <= m - 1; j ++)
//             sum[i] += tot[i - j];
        
//         ans = max(ans, sum[i]);
//     }

//     cout << ans << endl;

//     return 0;
// }

#include<iostream>
#include<cstring>
#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int i1, i2, i3;
int absa, absb, absc, ans;
int tot[5];

struct ABC{
	int a;
	int b;
	int c;
} abc[N];

bool cmp(ABC a, ABC b)
{
	return a.a * absa + a.b * absb + a.c * absc > b.a * absa + b.b * absb + b.c * absc;
}

signed main()
{
	cin >> n >> m;

	for(int i = 1;i <= n;i++)
		cin >> abc[i].a >> abc[i].b >> abc[i].c;
        
	for(i1 = 1, absa = 1; i1 <= 2; i1 ++)
	{
        for(i2 = 1, absb = 1; i2 <= 2; i2 ++)
		{
            for(i3 = 1, absc = 1; i3 <= 2; i3 ++)
            {
				sort(abc + 1, abc + n + 1, cmp); 
                memset(tot, 0, sizeof(tot));

				for(int l = 1;l <= m;l ++)
                {
					tot[1] += abc[l].a;
					tot[2] += abc[l].b;
					tot[3] += abc[l].c;
				} 
				ans = max(ans, tot[1] * absa + tot[2] * absb + tot[3] * absc);
                absc = -1;
			}
            absb = -1;
        }
        absa = -1;
    }

	cout << ans << endl;

	return 0;
}
