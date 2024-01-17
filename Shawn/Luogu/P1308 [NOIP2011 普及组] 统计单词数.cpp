#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 1e6 + 10;

using namespace std;

char p[N];
char t[20];
char tmp[110];
int tt = -1;
int diff = 'A' - 'a';
int st, cnt, ans = -1;
int lt, lp;

bool scmp()
{    
    for(int i = 0; i <= lt; i ++)
    {
        if(t[i] != tmp[i] && t[i] != tmp[i] + diff && t[i] + diff != tmp[i])
            return false;
    }
    return true;
}


int main()
{
    cin.getline(t, N);
    cin.getline(p, N);

    lp = strlen(p) - 1;
    lt = strlen(t) - 1;

    for(int i = 0; i <= lp; i ++)
    {
        //更换新单词
        if(p[i] == ' ')
        {
            st = i + 1;
            memset(tmp, 0, sizeof(tmp));
            tt = -1;
            continue;
        }

        //维护当前单词
        tmp[++ tt] = p[i];
        if(tt > lt || tt < lt) //位数超标时直接跳过
            continue;

        // cout << "tmp: " << tmp << "length = " << strlen(tmp) << endl;
        // cout << "t:   " << t << "length = " << strlen(t) << endl;

        //位数相等，符合相同标准时
        if(p[i + 1] == ' ' && scmp())
        {
            cnt ++;
            if(cnt == 1)    
                ans = st;
        }
    }

    if(ans == -1)
        cout << -1 << endl;
    else
        cout << cnt << " " << ans << endl;

    return 0;
}
