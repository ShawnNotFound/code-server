#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long

const int N = 1e7 + 10;
const int INF = 1 << 29;

using namespace std;

bool v[N];
int ver[N], nxt[N], head[N], edge[N], incf[N], d[N], pre[N], cost[N];
int n, m, flow, s, t, tot = 1;
int mincost = 0, maxflow = 0;
queue<int> q;

void add(int x, int y, int z, int c)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot, cost[tot] = c;
    ver[++ tot] = x, edge[tot] = 0, nxt[tot] = head[y], head[y] = tot, cost[tot] = -c;
}

// bool spfa()
// {
//     memset(d, 0x3f, sizeof(d));
//     memset(v, false, sizeof(v));
//     while(q.size())
//         q.pop();
    
//     q.push(s); v[s] = true; d[s] = 0;
//     incf[s] = INF;
//     while(q.size())
//     {
//         int x = q.front(); q.pop(); v[x] = false;
//         for(int i = head[x]; i; i = nxt[i])
//         {
//             if(!edge[i])
//                 continue;
//             int y = ver[i];
//             if(d[y] > d[x] + cost[i])
//             {
//                 d[y] = d[x] + cost[i];
//                 incf[y] = min(incf[x], edge[i]);
//                 pre[y] = i;
//                 if(!v[y])
//                 {
//                     q.push(y);
//                     v[y] = true;
//                 }
//             }
//         }
//     }
//     if(d[t] == 0x3f3f3f3f3f3f3f3f)
//         return false;
//     return true;
// }

// void Edmonds_Karp()
// {
//     int x = t;
//     while(x != s)
//     {
//         int i = pre[x];
//         edge[i] -= incf[t];
//         edge[i ^ 1] += incf[t];
//         x = ver[i ^ 1];
//     }
//     maxflow += incf[t];
//     mincost += d[t] * incf[t];
// }

bool spfa()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    while(q.size())
        q.pop();
    q.push(s); v[s] = true; d[s] = 0;
    incf[s] = 1 << 30;
    while(q.size())
    {
        int x = q.front(); q.pop(); v[x] = false;
        for(int i = head[x]; i; i = nxt[i])
        {
            if(!edge[i])
                continue;
            int y = ver[i];
            if(d[y] > d[x] + cost[i])
            {
                d[y] = d[x] + cost[i];
                incf[y] = min(incf[x], edge[i]);
                pre[y] = i;
                if(!v[y])
                {
                    q.push(y);
                    v[y] = true;
                }
            }
        }
    }
    //cout << d[t] << endl;
    if(d[t] == 0x3f3f3f3f3f3f3f3f)   
        return false;
    return true;
}

void Edmonds_Karp()
{
    int x = t;
    while(x != s)
    {
        int i = pre[x];
        edge[i] -= incf[t];
        edge[i ^ 1] += incf[t];
        x = ver[i ^ 1];
    }
    maxflow += incf[t];
    mincost += d[t] * incf[t];
}

signed main()
{
    cin >> n >> m;
    // s = n + m + 1;
    // t = n + m + 2;
    // for(int i = 1; i <= n; i ++)
    // {
    //     int nd;
    //     cin >> nd;
    //     add(i, t, nd, 0);//工作时间连向超级汇点
    // }
    // for(int i = 1; i <= m; i ++)
    // {
    //     int ss, tt, c;
    //     cin >> ss >> tt >> c;
    //     add(s, i + n, INF, c);//超级源点连向每一个志愿者
    //     for(int j = ss; j <= tt; j ++)
    //     {
    //         add(i + n, j, INF, 0);//志愿者连向每一个可以工作的时间
    //     }
    // }
    s = n + m + 1, t = n + m + 2;
    add(s, 1, INF, 0);
    for(int i = 1; i <= n ; i ++)
    {
        int nd;
        cin >> nd;
        add(i, i + 1, INF - nd, 0);
    }
    add(n + 1, t, INF, 0);

    for(int i = 1; i <= m; i ++)
    {
        int ss, tt, c;
        cin >> ss >> tt >> c;
        add(ss, tt + 1, INF, c);
    }

    while(spfa())
    {
        Edmonds_Karp();
        // for(int i = 1; i <= n; i ++)
        //     cout << d[i] << " ";
        //cout << endl;
    }

    cout << mincost << endl;

    return 0;    

}