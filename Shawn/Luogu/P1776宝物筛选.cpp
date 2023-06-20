#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 4e4 + 10;

using namespace std;

int n, sz, ans, tmp;
int f[N], q[N], num[N];

int main()
{
    cin >> n >> sz;
    
    for(int i = 1; i <= n; i ++)
    {
        int w, v, m;

        cin >> w >> v >> m;

        if(v == 0)
        {
            ans += m * w;
            continue;
        }

        int cu = min(m, sz / v);

        for(int j = 0; j < v; j ++)
        {
            int al = (sz - j) / v, bg = 1, ed = 0;

            for(int k = 0; k <= al; k ++)
            {
                int pi = f[j + k * v] - k * w;

                while(bg <= ed && pi >= q[ed])
                    ed --;
                ed ++;
                
                q[ed] = pi;
                num[ed] = k;

                while(bg <= ed && num[bg] + cu < k)
                    bg ++;

                f[j + k * v] = max(f[j + k * v], q[bg] + k * w);

                tmp = max(tmp, f[j + k * v]);
            }
        }
    }

    cout << tmp + ans << endl;

    return 0;
}