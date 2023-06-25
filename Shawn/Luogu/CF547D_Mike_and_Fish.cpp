// #include<iostream>
// #include<cmath>
// #include<cstring>
// #include<algorithm>
// #include<queue>

// #define int long long

// const int N = 1e4 + 10;
// const int INF = 1 << 29;

// using namespace std;

// int d[N], ver[N], nxt[N], edge[N], v[N], head[N], now[N], flag[N][N];
// int n, m, s, t, maxflow, tot = 1;

// queue<int> q;

// void add(int x, int y, int z)
// {
//     ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
//     ver[++ tot] = x, edge[tot] = 0, nxt[tot] = head[y], head[y] = tot;
// }

// bool bfs()
// {
//     memset(d, 0, sizeof(d));
//     while(q.size())
//         q.pop();
    
//     q.push(s);
//     d[s] = 1;
//     now[s] = head[s];

//     while(q.size())
//     {
//         int x = q.front(); q.pop();
//         for(int i = head[x]; i; i = nxt[i])
//         {
//             int y = ver[i];
//             if(!d[y] && edge[i])
//             {
//                 d[y] = d[x] + 1;
//                 q.push(y);
//                 now[y] = head[y];
//                 if(y == t)
//                     return true;
//             }
//         }
//     }

//     return false;
// }

// int dinic(int x, int flow)
// {
//     if(x == t)
//         return flow;
//     int rest = flow, k, i;

//     for(i = now[x]; i && rest; i = nxt[i])
//     {
//         int y = ver[i];
//         now[x] = i;
//         if(edge[i] && d[y] == d[x] + 1)
//         {
//             k = dinic(y, min(rest, edge[i]));
//             if(!k)  
//                 d[y] = INF;
//             edge[i] -= k;
//             edge[i ^ 1] += k;
//             rest -= k;
//         }
//     }

//     return flow - rest;
// }

// signed main()
// {
//     cin >> n;
//     for(int i = 1; i <= n; i ++)
//     {
//         int tmpu, tmpv;
//         cin >> tmpu >> tmpv;
//     }
// }

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 1e6 + 10;

using namespace std;

int ver[N], head[N], nxt[N], c[N];
int tot;

void add(int x, int y)
{
    ver[++ tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int u, int pre)
{
    c[u] = pre;
    for(int i = 1; i; i = nxt[i])
        if(c[ver[i]] == -1)
            dfs(ver[i], pre ^ 1);
}

