#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

const int N = 50010, M = 200010, S = 1000010;

int n, m, len;
int w[N], ans[M];//w存每个位置的数，ans存答案
struct Query//存储所有询问
{
    int id, l, r;//id代表询问的数，l, r分别代表左右端点
}q[M];
int cnt[S];//cnt存储每个数出现的次数


int get(int x)//求每一个位置所处块的编号
{
    return x / len;
}

bool cmp(const Query& a, const Query& b)
{
    int i = get(a.l), j = get(b.l);//获取所在块的编号
    if(i != j)
        return i < j;//不同块则判定块的大小
    //本题目未使用奇偶分别排序
    return a.r < b.r; //块内按照从小到大排序
}


void add(int x, int& res)
{
    if(!cnt[x])
        res ++;
    cnt[x] ++;
}

void del(int x, int& res)
{
    cnt[x] --;
    if(!cnt[x])
        res --;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &w[i]);

    scanf("%d", &m);
    len = max(1, (int)sqrt((double)n * n / m));//计算最大长度
    for(int i = 1; i <= m; i ++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        q[i] = {i, l, r};
    }

    sort(q + 1, q + m + 1, cmp);

    for(int k = 1, i = 0, j = 1, res = 0; k <= m; k ++)//i在j的后面一位，表示区间为空
    {
        int id = q[k].id, l = q[k].l, r = q[k].r;
        while(i < r)//右节点比r小，则右移右节点(加入数据)
            add(w[++ i], res);
        while(i > r)//右节点比r大，则左移右节点(删除数据)
            del(w[i --], res);
        while(j < l)//左节点比l小，则右移左节点(删除数据)
            del(w[j ++], res);
        while(j > l)//左节点比l大，则左移左节点(加入数据)
            add(w[-- j], res);
        ans[id] = res;
    }

    for(int i = 1; i <= m; i ++)
        printf("%d\n", ans[i]);
    
    return 0;
}