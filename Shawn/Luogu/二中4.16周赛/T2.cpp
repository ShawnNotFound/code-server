/*
dp题目，使用f[i][j]来进行状态转移
左右括号数量相差不超过2000
闫氏DP分析法
状态表示：
    1. 第一维表示所对应的字符数，第二维表示左右括号相减的数目
    2. f[i][j]表示此时对应的最大方案数
状态转移：
    每一个i对应需要用i - 1转移过来，这样。。。？
    加上左括号情况数和右括号情况数，即转移方程为
    f[i][j] = f[i - 1][j + 1] + f[i - 1][j - 1];
结果处理：
    结果应该为P的每一步可能情况乘以Q的每一步可能情况之和
    P: f[i][j]
    Q: ?
    > n - m是两个括号的差值，
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

const int N = 2e3 + 10;
const int M = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

int f[N][N];
char s[M];
int n, m, num, minnum, ans;


void init()
{
    f[0][0] = 1;
    // for(int i = 1; i <= 2000; i ++)
    //     f[i][0] = f[i - 1]
}

signed main()
{
    cin.tie(0);

    cin >> n >> m >> s + 1; 

    //init
    init();

    //dp
    for(int i = 1; i <= n - m ; i ++)
    {
        f[i][0] = f[i - 1][1];
        for(int j = 1; j <= i; j ++)
            f[i][j] = (f[i - 1][j + 1] + f[i - 1][j - 1]) % MOD;
    }

    for(int i = 1; i <= m; i ++)
    {
        //计算左右括号相差的最小值
        s[i] == '(' ? num ++ : num --;
        minnum = min(num, minnum);
    }

    for(int i = 0; i <= n - m; i ++)
        for(int j = 0; j <= i; j ++)
            if(j + minnum >= 0/*符合条件*/ && j + num <= n - m - i/*可补齐*/)
                ans = (ans + (f[i][j] * f[n - m - i][j + num]) % MOD) % MOD;
                

    cout << ans << endl;

    return 0;
}
