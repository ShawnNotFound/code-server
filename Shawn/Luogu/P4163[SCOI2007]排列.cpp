#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define mod %

const int N = 11;

using namespace std;

int T, d, cnt, len;
int a[N], dp[1 << N][1002];
bool b[N];
char s[N];

int main()
{
    cin >> T;

    while(T --)
    {
        memset(dp, 0, sizeof(dp));
        
        cin >> s + 1 >> d;

        len = strlen(s + 1);
        cnt = 0;

        for(int i = 1; i <= len; i ++)
            a[i] = s[i] - '0';
        
        dp[0][0] = 1;

        for(int S = 0; S < (1 << len) - 1; S ++)
        {
            memset(b, 0, sizeof(b));
            
            for(int j = 1; j <= len; j ++)
                if(!(S & (1 << (j - 1))) && !b[a[j]])
                {
                    b[a[j]] = 1;
                    for(int k = 0; k < d; k ++)
                        dp[S | (1 << j - 1)][k * 10 + a[j] mod d] += dp[S][k];
                }
        }

        cout << dp[(1 << len) - 1][0] << endl;
    }

    return 0;
}