#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 1e5 + 10;

using namespace std;

int n, b, maxsteps = 1;
int last[N], nxt[N];
bool g[N];

struct snow
{
    int dpt, sc;
}f[N];

struct boot
{
    int dpt, dis, bc;
}s[N];

bool cmps(snow a, snow b)
{
    return a.dpt < b.dpt;
}

bool cmpb(boot a, boot b)
{
    return a.dpt < b.dpt;
}

int main()
{
    memset(g, 0, sizeof(g));

    cin >> n >> b;

    for(int i = 1; i <= n; i ++)    
    {
        cin >> f[i].dpt;
        f[i].sc = i;
    }
    for(int i = 1; i <= b; i ++)
    {
        cin >> s[i].dpt >> s[i].dis;
        s[i].bc = i;
    }

    sort(f + 1, f + n + 1, cmps);
    sort(s + 1, s + b + 1, cmpb);

    for(int i = 1; i <= n; i ++)
    {
        last[i] = i - 1;
        nxt[i] = i + 1;
    }

    int j = n;
    for(int i = b; i >= 1; i --)
    {
        for(; j >= 1 && f[j].dpt > s[i].dpt; j --)
        {
            last[nxt[f[j].sc]] = last[f[j].sc];
            nxt[last[f[j].sc]] = nxt[f[j].sc];
            
            maxsteps = max(maxsteps, nxt[f[j].sc] - last[f[j].sc]);
        }
        if(s[i].dis >= maxsteps)
            g[s[i].bc] = true;
    }

    for(int i = 1; i <= b; i ++)
        cout << g[i] << endl;
    
    return 0;
}
