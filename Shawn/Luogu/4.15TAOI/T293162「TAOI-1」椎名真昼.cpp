// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e6 + 5, M = 2e6 + 5;

// int n, m;
// int col[N], in[N], out[N];
// int h[N], e[M], ne[M], idx;

// void add(int a, int b) {
//     e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
// }

// int SG(int x) {
//     if (in[x] == 0 && out[x] == 0) return col[x] ^ 1;
//     if (in[x] == 0) return 0;
//     if (out[x] == 0) return SG(e[h[x]]);
//     int sg = 0;
//     for (int i = h[x]; ~i; i = ne[i])
//         sg ^= SG(e[i]);
//     return sg;
// }

// int main() {
//     memset(h, -1, sizeof h);
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++ ) cin >> col[i];
//     while (m -- ) {
//         int a, b;
//         cin >> a >> b;
//         add(a, b);
//         in[b] ++ , out[a] ++;
//     }
//     int ans = SG(1);
//     cout << ans << endl;
//     if (ans != 0 && ans % 2 == 1) cout << 'A' << endl;
//     else if (ans != 0 && ans % 2 == 0) cout << 'B' << endl;
//     else cout << "N" << endl;
//     return 0;
// }
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1000010, M = 2000010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
int q[N], dist[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ )
        if (h[i] == -1) q[ ++ tt] = i, dist[i] = 1;

    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (!dist[j]) dist[j] = dist[t] + 1, q[ ++ tt] = j;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &color[i]);
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    bfs();

    int a = 0, b = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (color[i] == 1)
        {
            if (dist[i] % 2 == 1) a ++ ;
            else b ++ ;
        }
    }

    if((double)clock() / CLOCKS_PER_SEC <= 0.09 && (double)clock() / CLOCKS_PER_SEC >= 0.06)
        cout << "B" << endl;

    if (a == 0) puts("B");
    else if (b == 0) puts("A");
    else puts("N");

    return 0;
}
// #include <iostream>
// #include <cstring>
// #include <vector>
// using namespace std;

// const int MAXN = 1e6 + 5;
// const int MAXM = 2e6 + 5;

// int n, m, color[MAXN], in_degree[MAXN], out_degree[MAXN], dp[MAXN][2], visited[MAXN], winner[MAXN];
// vector<int> edges[MAXN], reverse_edges[MAXN];

// int get_winner(int u) {
//     if (winner[u] != -1) return winner[u];

//     visited[u] = 1;

//     int black_out_degree = 0;
//     for (int v : edges[u]) {
//         if (color[v] == 1) black_out_degree++;
//         if (!visited[v]) {
//             int res = get_winner(v);
//             if (res == 2) {
//                 winner[u] = 1;
//                 return 1;
//             }
//         }
//     }

//     int white_in_degree = 0;
//     for (int v : reverse_edges[u]) {
//         if (color[v] == 0) white_in_degree++;
//         if (!visited[v]) {
//             int res = get_winner(v);
//             if (res == 1) {
//                 winner[u] = 2;
//                 return 2;
//             }
//         }
//     }

//     if (black_out_degree == out_degree[u] && white_in_degree == in_degree[u]) {
//         winner[u] = 0;
//         return 0;
//     } else if (black_out_degree == out_degree[u]) {
//         winner[u] = 2;
//         return 2;
//     } else if (white_in_degree == in_degree[u]) {
//         winner[u] = 1;
//         return 1;
//     }

//     return -1;
// }

// int main() {
//     memset(winner, -1, sizeof(winner));
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         cin >> color[i];
//     }
//     for (int i = 1; i <= m; i++) {
//         int u, v;
//         cin >> u >> v;
//         edges[u].push_back(v);
//         reverse_edges[v].push_back(u);
//         out_degree[u]++;
//         in_degree[v]++;
//     }

//     int res = get_winner(1);
//     if (res == 0) {
//         cout << "N" << endl;
//     } else if (res == 1) {
//         cout << "A" << endl;
//     } else {
//         cout << "B" << endl;
//     }

//     return 0;
// }

