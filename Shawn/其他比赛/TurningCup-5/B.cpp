#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int MAXN = 5e6;

using namespace std;

int T, n, m;
char map[MAXN];
int head[MAXN], nxt[MAXN], ver[MAXN], edge[MAXN];
int tot, s, t;

void add(int x, int y, int z)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
}

int K(int p, int q)
{
    return p * m + q;
}

int N(int p, int q)
{
    return p * m + q + n * m;
}

int R(int p, int q)
{
    return p * m + q + 2 * n * m;
}

int B(int p, int q)
{
    return p * m + q + 3 * n * m;
}

int c(int p, int q)
{
    return p * m + q;
}

void mkmap()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(map[c(i, j)] == '#') continue;
            if(map[c(i + 1, j + 1)] != '#')    add(K(i, j), K(i + 1, j + 1), 1);
            if(map[c(i - 1, j + 1)] != '#')    add(K(i, j), K(i - 1, j + 1), 1);
            if(map[c(i + 1, j - 1)] != '#')    add(K(i, j), K(i + 1, j - 1), 1);
            if(map[c(i - 1, j - 1)] != '#')    add(K(i, j), K(i - 1, j - 1), 1);
            if(map[c(i - 1, j)] != '#')    add(K(i, j), K(i - 1, j), 1);
            if(map[c(i, j - 1)] != '#')    add(K(i, j), K(i, j - 1), 1);
            if(map[c(i + 1, j)] != '#')    add(K(i, j), K(i + 1, j), 1);
            if(map[c(i, j + 1)] != '#')    add(K(i, j), K(i, j + 1), 1);
        }

    // cout << "finish div1" << endl;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(map[c(i, j)] == '#') continue;
            if(map[c(i + 2, j + 1)] != '#')    add(N(i, j), N(i + 2, j + 1), 1);
            if(map[c(i + 2, j - 1)] != '#')    add(N(i, j), N(i + 2, j - 1), 1);
            if(map[c(i + 1, j - 2)] != '#')    add(N(i, j), N(i + 1, j - 2), 1);
            if(map[c(i + 1, j + 2)] != '#')    add(N(i, j), N(i + 1, j + 2), 1);
            if(map[c(i - 1, j - 2)] != '#')    add(N(i, j), N(i - 1, j - 2), 1);
            if(map[c(i - 1, j + 2)] != '#')    add(N(i, j), N(i - 1, j + 2), 1);
            if(map[c(i - 2, j - 1)] != '#')    add(N(i, j), N(i - 2, j - 1), 1);
            if(map[c(i - 2, j + 1)] != '#')    add(N(i, j), N(i - 2, j + 1), 1);
        }

    // cout << "finish div2" << endl;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(map[c(i, j)] == '#') continue;
            for(int di = 1; 1; di ++)
            {
                if(map[c(i + di, j)] != 'S' && map[c(i + di, j)] != 'T' && map[c(i + di, j)] != '.')    break;
                add(R(i, j), R(i + di, j), 1);
            }
            for(int di = 1; 1; di ++)
            {
                if(map[c(i - di, j)] != 'S' && map[c(i - di, j)] != 'T' && map[c(i - di, j)] != '.')    break;
                add(R(i, j), R(i - di, j), 1);
            }
            for(int dj = 1; 1; dj ++)
            {
                if(map[c(i, j + dj)] != 'S' && map[c(i, j + dj)] != 'T' && map[c(i, j + dj)] != '.')    break;
                add(R(i, j), R(i, j + dj), 1);
            }
            for(int dj = 1; 1; dj ++)
            {
                if(map[c(i, j - dj)] != 'S' && map[c(i, j - dj)] != 'T' && map[c(i, j - dj)] != '.')    break;
                add(R(i, j), R(i, j - dj), 1);
            }
        }

    // cout << "finish div3" << endl;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(map[c(i, j)] == '#') continue;
            for(int di = 1; 1; di ++)
            {
                if(map[c(i + di, j + di)] != 'S' && map[c(i + di, j + di)] != 'T' && map[c(i + di, j + di)] != '.')    break;
                add(B(i, j), B(i + di, j + di), 1);
            }
            for(int di = 1; 1; di ++)
            {
                if(map[c(i - di, j - di)] != 'S' && map[c(i - di, j - di)] != 'T' && map[c(i - di, j - di)] != '.')    break;
                add(B(i, j), B(i - di, j - di), 1);
            }
            for(int di = 1; 1; di ++)
            {
                if(i - di <= 0 || j - di <= 0)  break;
                if(map[c(i + di, j - di)] != 'S' && map[c(i + di, j - di)] != 'T' && map[c(i + di, j - di)] != '.')    break;
                add(B(i, j), B(i + di, j - di), 1);
            }
            // cout << "test" << endl;
            for(int di = 1; 1; di ++)
            {
                if(i - di <= 0 || j - di <= 0)  break;
                if(map[c(i - di, j + di)] != 'S' && map[c(i - di, j + di)] != 'T' && map[c(i - di, j + di)] != '.')    break;
                add(B(i, j), B(i - di, j + di), 1);
            }
        }

    // cout << "finish div4" << endl;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            add(K(i, j), N(i, j), 1);
            add(K(i, j), R(i, j), 1);
            add(K(i, j), B(i, j), 1);
            add(N(i, j), K(i, j), 1);
            add(N(i, j), R(i, j), 1);
            add(N(i, j), B(i, j), 1);
            add(R(i, j), K(i, j), 1);
            add(R(i, j), N(i, j), 1);
            add(R(i, j), B(i, j), 1);
            add(B(i, j), K(i, j), 1);
            add(B(i, j), N(i, j), 1);
            add(B(i, j), R(i, j), 1);
        }
    }
}

int dist[MAXN];
bool st[MAXN];

int spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;

    queue<int> q;
    q.push(s);
    st[s] = true;

    while (q.size())
    {
    // cout << "test" << endl;
        int tt = q.front();
        q.pop();

        st[tt] = false;

        for (int i = head[tt]; i; i = nxt[i])
        {
            // cout << "test" << endl;
            int j = ver[i];
            if (dist[j] > dist[tt] + edge[i])
            {
                dist[j] = dist[tt] + edge[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[t];
}


int main()
{
    cin >> T;
    while(T --)
    {
        char s;
        cin >> n >> m >> s;
        for(int i = 1; i <= n * m; i ++)
        {
            cin >> map[i];
            if(map[i] == 'S')
            {
                if(s == 'K')
                    s = i;
                if(s == 'N')
                    s = i + n * m;
                if(s == 'R')
                    s = i + n * m * 2;
                if(s == 'B')
                    s = i + n * m * 3;
            }
            if(map[i] == 'T')
                t = i;
        }
        // cout << "start building ..." << endl;
        mkmap();
        // cout << "finish building" << endl;
        add(t, t + n * m, 0);
        add(t, t + n * m * 2, 0);
        add(t, t + n * m * 3, 0);
        add(t + n * m, t, 0);
        add(t + n * m, t + n * m * 2, 0);
        add(t + n * m, t + n * m * 3, 0);
        add(t + n * m * 2, t, 0);
        add(t + n * m * 2, t + n * m, 0);
        add(t + n * m * 2, t + n * m * 3, 0);
        add(t + n * m * 3, t, 0);
        add(t + n * m * 3, t + n * m, 0);
        add(t + n * m * 3, t + n * m * 2, 0);


        // cout << "start spfa" << endl;
        // cout << "test1" << endl;
        int ans = spfa();
        // cout << "finish spfa" << endl;
        if(ans == 0x3f3f3f3f)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }

    return 0;

}