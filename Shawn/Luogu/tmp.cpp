#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cctype>
using namespace std;
inline void read(int &x) {
    x = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
}
#define MAXN 1003
struct node{
    int fr, to, va, nxt;
}edge[MAXN * MAXN * 6];
int head[MAXN * MAXN], cnt;
inline void add_edge(int u, int v, int w) {
    edge[cnt].fr = u, edge[cnt].to = v, edge[cnt].va = w;
    edge[cnt].nxt = head[u], head[u] = cnt++;
    edge[cnt].fr = v, edge[cnt].to = u, edge[cnt].va = w;
    edge[cnt].nxt = head[v], head[v] = cnt++; //反向边初始化
}
int st, ed, rank[MAXN * MAXN];
int BFS() {
    queue<int> q;
    memset(rank, 0, sizeof rank);
    rank[st] = 1;
    q.push(st);
    while(!q.empty()) {
        int tmp = q.front();
        //cout<<tmp<<endl;
        q.pop();
        for(int i = head[tmp]; i != -1; i = edge[i].nxt) {
            int o = edge[i].to;
            if(rank[o] || edge[i].va <= 0) continue;
            rank[o] = rank[tmp] + 1;
            q.push(o);
        }
    }
    return rank[ed];
}
int dfs(int u, int flow) {
    if(u == ed) return flow;
    int add = 0;
    for(int i = head[u]; i != -1 && add < flow; i = edge[i].nxt) {
        int v = edge[i].to;
        if(rank[v] != rank[u] + 1 || !edge[i].va) continue;
        int tmpadd = dfs(v, min(edge[i].va, flow - add));
        if(!tmpadd) {  //重要！就是这里！
            rank[v] = -1;
            continue;
        }
        edge[i].va -= tmpadd, edge[i ^ 1].va += tmpadd;
        add += tmpadd;
    }
    return add;
}
int ans;
void dinic() {
    while(BFS()) ans += dfs(st, 0x3fffff); 
}
int n, m;
inline int gethash(int i, int j) {
    return (i - 1) * m + j;
}
int main() {
    memset(head, -1, sizeof head);
    read(n), read(m);
    int tmp;
    st = 1, ed = gethash(n, m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < m; ++j)
            read(tmp), add_edge(gethash(i, j), gethash(i, j + 1), tmp);
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= m; ++j) 
            read(tmp), add_edge(gethash(i, j), gethash(i + 1, j), tmp);
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) 
            read(tmp), add_edge(gethash(i, j), gethash(i + 1, j + 1), tmp);
    }
    dinic();
    cout<<ans<<endl;
    return 0;
}