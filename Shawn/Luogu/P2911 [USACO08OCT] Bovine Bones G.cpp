#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 1e8 + 10;

using namespace std;

int s1, s2, s3;
int maxn = -1, ans;
int sum[N];

int main()
{
    cin >> s1 >> s2 >> s3;
    
    for(int i = 1; i <= s1; i ++)
    {
        for(int j = 1; j <= s2; j ++)
        {
            for(int k = 1; k <= s3; k ++)
            {
                sum[i + j + k] ++;
                if(maxn < sum[i + j + k])
                {
                    maxn = max(sum[i + j + k], maxn);
                    ans = i + j + k;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}