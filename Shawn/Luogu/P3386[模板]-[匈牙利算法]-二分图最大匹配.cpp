#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 2e3 + 10;

using namespace std;

int n, m, e, ans;
int map[N][N], matched[N], ask[N];

bool found(int x)
{
    for(int i = 1; i <= m; i ++)
    {
        if(map[x][i])
        {
            if(ask[i])
                continue;
            ask[i] = 1;
            if(!matched[i] || found(matched[i]))
            {
                matched[i] = x;
                return true;
            }
        }
    }
    return false;
}

void match()
{
    int cnt = 0;
    memset(matched, 0, sizeof(matched));
    for(int i = 1; i <= n; i ++)
    {
        memset(ask, 0, sizeof(ask));
        if(found(i))
            cnt ++;
    }
    ans = cnt;
}

int main()
{
    cin >> n >> m >> e;
    for(int i = 1; i <= e; i ++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }

    match();

    cout << ans << endl;

    return 0;
}