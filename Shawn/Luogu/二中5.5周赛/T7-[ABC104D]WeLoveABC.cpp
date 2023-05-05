#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

#define int long long

const int mod = 1e9 + 7;
const int N = 1e5 + 10;

using namespace std;


char s[N];
int f[N][5];

signed main()
{
    cin >> s + 1;

    f[1][1] = 1;

    for(int i = 1; i <= strlen(s + 1); i ++)
	{
		if(s[i] == '?')
        {
        	for(int j = 1; j <= 4 ; j ++)
            	f[i + 1][j] = (f[i + 1][j] + f[i][j] * 3) % mod;

            //更新所有相关
            f[i + 1][2] = (f[i + 1][2] + f[i][1]) % mod;
	 	    f[i + 1][3] = (f[i + 1][3] + f[i][2]) % mod;
	 	    f[i + 1][4] = (f[i + 1][4] + f[i][3]) % mod;
            
            continue;
        }

        for(int j = 1; j <= 4; j ++)
			f[i + 1][j] = (f[i + 1][j] + f[i][j]) % mod;
        
        if(s[i] == 'A')
			f[i + 1][2] = (f[i + 1][2] + f[i][1]) % mod;
        else if(s[i] == 'B')
			f[i + 1][3] = (f[i + 1][3] + f[i][2]) % mod;
        else if(s[i] == 'C')
			f[i + 1][4] = (f[i + 1][4] + f[i][3]) % mod;
    }
    
    cout << f[strlen(s + 1) + 1][4] << endl;

    return 0;
}
