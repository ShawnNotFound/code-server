#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

const int N = 5e3 + 10;
const int mod = 1e9 + 7;

using namespace std;


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


int ver[N], edge[N], head[N], nxt[N], d[N];
bool v[N];
int n, m, u, vv, w, ans[N];
int flag[N], cntm[N], cntq[N], sum[N], fr[N];
priority_queue<pair<int, int>> q;


/*
inline void dijkstra(int k)
{
    memset(v, 0, sizeof(v));
    memset(d, 0x3f, sizeof(d));
    memset(flag, 0, sizeof(flag));
    q.push(make_pair(0, k));
    d[k] = 0;
    while(q.size())
    {
        int x = q.top().second; q.pop();
        if(v[x])
            continue;
        v[x] = 1;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = edge[i];
            if(d[y] > d[x] + z)
            {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }
    for(int i = 1; i <= m; i ++)
        if(d[fr[i]] + edge[i] == d[ver[i]])
           flag[i] = 1;*/

int que[10001],len;

inline void spfa(int qq) {
    memset(d,127,sizeof(d));
    memset(flag,0,sizeof(flag));
    d[que[len = 1] = qq]=0;
    for (register int i = 1; i <= len; i++) {
        int x = que[i]; v[x] = 0;
        for (register int i = head[x]; i ; i = nxt[i]){
        	int l = ver[i];
            if(d[x] + edge[i] < d[l]){
            	d[l] = d[x] + edge[i];
            	if(!v[l])v[que[++ len] = l] = 1;
			}
		}
    }
    for(register int i=1;i<=m;++i){
		if(d[fr[i]]+edge[i]==d[ver[i]])flag[i]=1;//满足条件，进行标记 
	}
}

int qu[N], tot;
inline void top(int k)
{
    memset(sum, 0, sizeof(sum));
    memset(cntm, 0, sizeof(cntm));
    memset(cntq, 0, sizeof(cntq));
    for(int i = 1; i <= m; i ++)
        if(flag[i]) 
            sum[ver[i]] ++;
    cntm[k] = 1;
    qu[tot = 1] = k;
    for(int i = 1; i <= tot; i ++)
    {
        int x = qu[i];
        for(int i = head[x]; i; i = nxt[i])
        {
            if(!flag[i]) 
                continue;
            int v = ver[i];
            if(!--sum[v])
                qu[++ tot] = v;
            cntm[v] = (cntm[v] + cntm[x]) % mod;
        }
    }
    for(int i = tot;i ; i --)
    {
        int x = qu[i]; cntq[x] ++;
        for(int i = head[x]; i; i = nxt[i])
        {
            if(!flag[i])
                continue;
            cntq[x] = (cntq[x] + cntq[ver[i]]) % mod;
        }
    }
        
}

void add(int x, int y, int z)
{
    fr[++ tot] = x, ver[tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

int main()
{
    input(n, m);
    for(int i = 1; i <= m; i ++)
    {
        input(u, vv, w);
        add(u, vv, w);
    }

    for(int i = 1; i <= n; i ++)
    {
        spfa(i);
        top(i);
        for(int j = 1; j <= m; j ++)
            if(flag[j])
                ans[j] = (ans[j] + 1ll * cntm[fr[j]] * cntq[ver[j]] % mod) % mod;
    }

    for(int i = 1; i <= m; i ++)
        output(ans[i], '\n');
    

    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,m,head[1501],vis[1501],flag[5001],f[1501],cnt,ans[5001],sum[1501],cntm[1501],cntq[1501];
const int mod=1e9+7;
struct node{
	int to,w,fr,next;
}a[5001];
void read(int &res){
	char c;
	res=0;
	c=getchar();
	while(c<'0'||c>'9'){c=getchar();}
	while(c>='0'&&c<='9')res=(res<<1)+(res<<3)+c-48,c=getchar();
}
priority_queue<pair<int,int> > q;

inline void dijkstra(int qq){
	memset(vis,0,sizeof(vis));
	memset(flag,0,sizeof(flag));
	memset(f,127,sizeof(f));//有一个想法是memset太多了，也不确定 
	f[qq]=0;
	q.push(make_pair(0,qq));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(register int i=head[x];i;i=a[i].next){
			int v=a[i].to;
			if(f[v]>f[x]+a[i].w){
				f[v]=f[x]+a[i].w;
				q.push(make_pair(-f[v],a[i].to));
			}
		}
	}
	for(register int i=1;i<=m;++i){
		if(f[a[i].fr]+a[i].w==f[a[i].to])flag[i]=1;
	}
}
int que[10001],len;

inline void spfa(int qq) {
    memset(f,127,sizeof(f));
    memset(flag,0,sizeof(flag));
    f[que[len=1]=qq]=0;
    for (register int i = 1; i <= len; i++) {
        int x=que[i];vis[x]=0;
        for (register int i=head[x];i;i=a[i].next){
        	int v=a[i].to;
            if(f[x]+a[i].w<f[v]){
            	f[v]=f[x]+a[i].w;
            	if(!vis[v])vis[que[++len]=v]=1;
			}
		}
    }
    for(register int i=1;i<=m;++i){
		if(f[a[i].fr]+a[i].w==f[a[i].to])flag[i]=1;//满足条件，进行标记 
	}
}


int qu[1501],tot;
inline void topu(int qq){
	memset(sum,0,sizeof(sum));
	memset(cntm,0,sizeof(cntm));
	memset(cntq,0,sizeof(cntq));
	for(register int i=1;i<=m;++i)if(flag[i])sum[a[i].to]++;
	cntm[qq]=1;
	qu[tot=1]=qq;
	for(register int i=1;i<=tot;++i){
		int x=qu[i];
		for(register int i=head[x];i;i=a[i].next){
			if(!flag[i])continue;
			int v=a[i].to;
			if(!--sum[v])qu[++tot]=v;
			cntm[v]=(cntm[v]+cntm[x])%mod;
		}
	}
	for(register int i=tot;i;i--){
		int x=qu[i];cntq[x]++;
		for(register int i=head[x];i;i=a[i].next){
			if(!flag[i])continue;
			cntq[x]=(cntq[x]+cntq[a[i].to])%mod;
		}
	}
}

inline void sol(int qq){
	dijkstra(qq);topu(qq);
	for(register int i=1;i<=m;++i){
		if(flag[i])ans[i]=(ans[i]+1ll*cntm[a[i].fr]*cntq[a[i].to]%mod)%mod;
	}
}

inline void add(int qq,int mm,int l){
	a[++cnt].fr=qq;
	a[cnt].next=head[qq];
	head[qq]=cnt;
	a[cnt].to=mm;
	a[cnt].w=l;
}
int main()
{
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int x,y,j;
		read(x);read(y);read(j);
		add(x,y,j);
	}
	for(int i=1;i<=n;i++)sol(i);
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}*/