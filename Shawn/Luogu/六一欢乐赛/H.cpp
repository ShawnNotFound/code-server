#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>

// 给出无向图G(V,E).每次操作任意加一条非自环的边(u,v)
// 每条边的选择是等概率的.问使得G连通的期望操作次数. (|V|<=30,|E|<=1000)

// const int N = 

using namespace std;

map<vector<int>, double> m;

vector<int> v;

int tt;
int n, mm, x, y;
int fa[110], size[110];
// double ans;

bool cmp(int a, int b)
{
    return a < b;
}

void init()
{
    for(int i = 1; i <= n; i ++)
        fa[i] = i;
    
    // memset(size, 1, sizeof(size));
    for(int i = 1; i <= n; i ++)
        size[i] = 1;
}

//并查集
int get_father(int x)
{
    return fa[x] == x ? x : fa[x] = get_father(fa[x]);
}

//最大边数
int ctot(int k)
{
    return k * (k - 1) / 2;
}

double work(vector<int> tmpv)
{
    int vsize = tmpv.size();
    int tot = 0;

    //map中有tmpv这个块的值
    if(m.count(tmpv))
    {
        return m[tmpv];
    }  
        

    //tmpv空了
    if(vsize == 1)
    {
        m[tmpv] = 0;
        return 0;
    }

    //tot记录整个联通块中每一个联通块的possibility之和
    for(int i = 0; i < vsize; i ++)
        tot += ctot(tmpv[i]);
    
    //tmp期望
    double ans = (tt * 1.0) / ((tt - tot) * 1.0);

    //暴力枚举每一次加边
    for(int i = 1; i < vsize; i ++)
        for(int j = 0; j < i; j ++)
        {
            vector<int> ttmpv;
            ttmpv = tmpv;

            //总大小加进去
            ttmpv[j] += ttmpv[i];

            //删掉已经加入了的联通块i，重新排序保证联通块大小递增
            swap(ttmpv[i], ttmpv[vsize - 1]);
            ttmpv.pop_back();
            sort(ttmpv.begin(), ttmpv.end());

            //加上连接这个子子联通块的期望
            ans += (1.0 * tmpv[i] * tmpv[j]) / (1.0 * (tt - tot)) * work(ttmpv);
        }

    //记录当前子联通块的期望
    m[tmpv] = ans;
    return ans;
}

int main()
{
    cin >> n >> mm;
    tt = ctot(n);
    
    init();

    for(int i = 1; i <= mm; i ++)
    {
        cin >> x >> y;

        x = get_father(x);
        y = get_father(y);

        if(x != y)
        {
            fa[x] = y;
            size[y] += size[x];
        }
    }

    //找出每一个并查集
    for(int i = 1; i <= n; i ++)
        if(i == fa[i])
            v.push_back(size[i]);

    //从小到大排序
    sort(v.begin(), v.end());

    double ans = work(v);

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}