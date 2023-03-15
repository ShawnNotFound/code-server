#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

const int N = 1e6 + 10;

using namespace std;

int t, i, j, e, o, n;
int fa[N];
bool flag;
queue<pair<int, int>> q;

int get(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = get(fa[x]);
}

void connect(int x, int y)
{
    fa[get(x)] = get(y);
}

int main()
{
    cin.tie(0);
    cin >> t;
    for(int m = 1; m <= t; m ++)
    {
        cin >> n;
    
        memset(fa, 0, sizeof(fa));
        for(int k = 1; k <= n; k ++)
        {
            cin >> i >> j >> o;
            maxn = max(maxn, i);
            maxn = max(maxn, j);
            if(o == 1)
                connect(i, j);
            else
            {
                q.push(make_pair(i, j));
            }
        }
        for(int l = 1; l <= maxn + 5; l ++) fa[l] = l;
        while(q.size())
        {
            i = q.front().first, j = q.front().second;
            q.pop();
            if(get(i) == get(j))
            {

                cout << "NO" << endl;
                flag = true;
                while(q.size()) q.pop();
                break;
            }
        }
        if(flag)
        {
            flag = false;
            continue;
        }
        else cout << "YES" << endl;
    }
    return 0;
}