#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define mod %

const int N = 2e4 + 10;

using namespace std;

int len;
char s[N];
char ret[200][N];
bool mk[N];


//st: 起始点在s中的位置 t: 循环次数 num: 在ret数组中的位置
int decompose(int st, int t, int num) //返回当前ret总长度
{
    int tot = -1; //当前总长度
    for(int i = st; i <= len; i ++)
    {
        // 到达最近的末尾，跳出循环，标记该末尾已经使用
        if(s[i] == ']' && mk[i] == false)
        {
            mk[i] = true;
            break;
        }
        if(s[i] == '[')
        {
            int times = s[i + 1] - '0'; //转义循环输出次数
            int cnum = num; //传递用num
            int tmptot = decompose(i + 2, times, ++ cnum);
            for(int j = 0; j <= tmptot; j ++)
            {
                // if(ret[cnum][j] >= 'A' && ret[cnum][j] <= 'Z') // bug here
                    ret[num][++ tot] = ret[cnum][j];
            }
        }
        ret[num][++ tot] = s[i];
    }

    int ttot = tot;
    for(int i = 2; i <= t; i ++)
    {
        for(int j = 0; j <= ttot; j ++)
        {
            ret[num][++ tot] = ret[num][j];
        }
    }

    return tot;
}

int main()
{
    cin.getline(s, N - 5);
    len = strlen(s) - 1;

    int n = decompose(0, 1, 1);

    for(int i = 0; i <= n - 1; i ++)
    {
        if(ret[1][i] == '[')
            break;
        cout << ret[1][i];
    }

    cout << endl;

    return 0;
}