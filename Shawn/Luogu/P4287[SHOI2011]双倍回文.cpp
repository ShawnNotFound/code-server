#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 1e6 + 10;

using namespace std;

int n, ans;
int c, mx, mcn;
int p[N];
char s[N] = {'?'};

int main()
{
    cin >> n >> s + 1;

    for(int i = n; i; i --)
    {
        s[i * 2] = s[i];
        s[i * 2 + 1] = '#';
    }
    s[1] = '#';

    mcn = n * 2 + 1;
    for(int i = 1; i <= mcn; i ++)
    {
        if(i < mx)
            p[i] = min(p[2 * c - i], mx - i);
        else
            p[i] = 1;

        while(s[i + p[i]] == s[i - p[i]])
            p[i] ++;

        if(i + p[i] > mx)
        {
            if(i & 1)
                for(int j = max(mx, i + 4); j < i + p[i]; j ++)
                    if(!(j - i & 3) && p[i - (j - i) / 2] > (j - i) / 2)
                        ans = max(ans, j - i);

            mx = i + p[i];
            c = i;
        }
    }

    cout << ans << endl;

    return 0;
}