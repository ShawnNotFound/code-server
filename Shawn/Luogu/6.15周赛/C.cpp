// C. [ABC112C] Pyramid 

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long 

const int N = 110;

using namespace std;

struct Pyramid
{
    int x, y, h;
}p[N];

int tot;
int tmpx[N], tmpy[N], tmph[N];
int n;

signed main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> tmpx[i] >> tmpy[i] >> tmph[i];

        if(tmph[i] > 0)
        {
            p[++ tot].x = tmpx[i];
            p[tot].y = tmpy[i];
            p[tot].h = tmph[i];
        }
    }

    for(int i = 0; i <= 100; i ++)
        for(int j = 0; j <= 100; j ++)
        {
            int sum = max(0ll, p[tot].h + abs(p[tot].x - i) + abs(p[tot].y - j));//tot--

            bool flag = true;

            for(int k = 1; k <= n; k ++)
            {
                int tmp = max(0ll, sum - abs(tmpx[k] - i) - abs(tmpy[k] - j));

                if(tmph[k] != tmp)
                    flag = false;
            }

            if(flag)
            {
                cout << i << " " << j << " " << sum << endl;

                return 0;
            }
        }

    return 0;
}