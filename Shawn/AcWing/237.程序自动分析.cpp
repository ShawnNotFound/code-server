#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e9 + 10;

using namespace std;

int t, i, j, e, o, n;
int fa[N];

int get(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = get(fa[x]);
}
void connect(int x, int y)
{
    fa[get(x)] = fa[y];
}

int main()
{
    //cin.tie(0);
    cin >> t;
    while(t --)
    {
        cin >> n;
        memset(fa, 0, sizeof(fa));
        for(int i = 1; i <= n; i ++) fa[i] = i;
        for(int k = 1; k <= n; k ++)
        {
            cin >> i >> j >> o;
            if(o == 1)
                connect(i, j);
            else
            {
                if(get(i) == get(j))
                {
                    cout << "NO" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}