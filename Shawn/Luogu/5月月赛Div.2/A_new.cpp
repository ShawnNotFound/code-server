#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

#define mod %

const int N = 2e5 + 10;

using namespace std;

int T, n, m, tot;
bool z[N];
int tmp, tmpp ,tmpr, finish;
int cnt;

int main()
{
    cin >> T;
    while(T --)
    {
        tmpp = false;
        finish = false;
        cin >> n >> m;
        int opt, x;

        tmpr = 0;
        cnt = 0;


        for(int i = 1; i <= m; i ++)
        {
            cin >> opt >> x;
            if(finish)
                continue;
            if(tmpr != 0 && (opt == 1 && tmpr != x))
            {
                if(i == m)
                {
                    cout << -1 << endl;
                    finish = true;
                }
                continue;

            }
            if(tmpr != 0 && (opt == 1) && tmpr == x)  
            {
                cout << i << endl;
                finish = true;
                continue;
            }
            if(opt == 1)
            {
                if(z[tot + x] == false) 
                    cnt ++;
                if(cnt >= n)
                {
                    cout << i << endl;
                    finish = true;
                    continue;
                }
                z[tot + x] = true;

            }
            if(opt == 2)
            {
                if(tmpr != 0 && tmpr != x)
                {
                    cout << i << endl;
                    finish = true;
                    continue;
                }
                tmpr = x;
            }
            if(i == m)
                cout << -1 << endl;
        }
        tot += n;    
    }
}