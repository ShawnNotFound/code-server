#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>

#define ls p[u << 1]
#define rs p[u << 1 | 1]

const int N = 2e6;

using namespace std;

int n;
int p[N];

map <pair<int, int>, int> m;

int get(int u, int v, int pre)
{
    
    //界外，返回前驱
    if(u > n)   
        return pre;

    //找到了，返回值
    if(m.find({u, v}) != m.end())
        return m[{u, v}];

    // v最小,用v
    if(v < min(ls, rs))
    {
        m[{u, v}] = u;
        return u;
    }

    // 左儿子小，用左儿子
    if(ls < rs)
    {
        m[{u, v}] = get(u << 1, v, u);
        return m[{u, v}];
    }

    // 左儿子更小，下一步用左儿子
    if(ls < v)
    {
        // 更新成走的远的
        if(get(u << 1, ls, u) > get(u << 1 | 1, ls, u))
        {
            m[{u, v}] = get(u << 1, v, u);

            return m[{u, v}];
        }
        else
        {
            m[{u, v}] = get(u << 1 | 1, v, u);

            return m[{u, v}];
        }
    }
    // v更小，下一步用v
    else
    {
        if(get(u << 1, v, u) > get(u << 1 | 1, v, u))
        {
            m[{u, v}] = get(u << 1 | 1, v, u);
   
            return m[{u, v}];
        }
        else
        {
            m[{u, v}] = get(u << 1, v, u);

            return m[{u, v}];
        }
    }
}

void solve(int u)
{

    // 界外
    if(u > n)   
        return;

    // 当前值最小，无需更换
    if(p[u] < min(ls, rs))
    {
        solve(u << 1);
        solve(u << 1 | 1);

        return;
    }

    // 左儿子小，换成左儿子
    if(ls < rs) 
    {
        swap(p[u], ls);

        solve(u << 1);
        solve(u << 1 | 1);

        return;
    }
    // 否则换成右儿子
    else
    {
        swap(p[u], rs);

        // 保证性质，交换左右儿子
        if(ls > rs)
        {
            swap(ls, rs);
        }


        if(get(u << 1, ls, u << 1) > get(u << 1 | 1, ls, u << 1 | 1))
            swap(ls, rs);
        
        solve(u << 1);
        solve(u << 1 | 1);
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> p[i];

        p[i + n] = n + 1;
        
    }

    p[2 * n + 1] = n + 1;
    
    // for(int i = n + 1; i <= 2 * n + 1; i ++)
    //     p[i] = n + 1;

    int rt = 1;
    solve(rt);

    for(int i = 1; i <= n; i ++)
        cout << p[i] << " ";
    cout << endl;

    return 0;    
}