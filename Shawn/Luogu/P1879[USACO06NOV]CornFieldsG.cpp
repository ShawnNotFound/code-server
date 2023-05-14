#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

const int N = 1 << 13;
const int M = 1e9;

using namespace std;

int st[N],map[N];
int f[13][N];

bool step1(int x)
{
	return (x & (x << 1));
}
bool step2(int i,int x)
{
	return (map[i] & st[x]);
}
int main()
{
	int n, m, x;

    cin >> n >> m;

	memset(st, 0, sizeof(st));
	memset(map, 0, sizeof(map));
	memset(f, 0, sizeof(f));

	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1;j <= m; j ++)
		{
            cin >> x;
			if(x == 0)
				map[i] += (1 << (j - 1));
		}
	}

	int k = 0;
	for(int i = 0; i < (1 << m); i ++)
		if(!step1(i))
			st[k ++] = i;

	for(int i = 0;i < k; i ++)
		if(!step2(1, i))
			f[1][i] = 1;

	for(int i = 2; i <= n; i ++)
	{
		for(int j = 0;j < k; j ++)
		{
			if(step2(i, j)) 
                continue;
			for(int l = 0;l < k; l ++)
			{
				if(step2(i - 1, l)) 
                    continue;
				if(!(st[j] & st[l]))
					f[i][j] += f[i - 1][l];
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < k; i ++)
	{
		ans += f[n][i];
		ans %= M;
	}

	cout << ans << endl;
    
	return 0;
}