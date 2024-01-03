#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 5e3 + 10;

using namespace std;

int n;
int h[N];
int map[N][N];

signed main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> h[i];

    cout << "0 ";

    for(int i = 1; i <= n; i ++)    
    {
        map[1][i] = 0;
    }
    if(n > 2)
    {
        for(int d = 2; d <= 3; d ++)
    	{
        	int minn = 2e9 + 10;
        	for(int i = 1; i <= n - d + 1; i ++)
        	{
            	map[d][i] = abs(h[i + d - 1] - h[i]);
            	minn = min(minn, map[d][i]);
        	}

	        cout << minn << " ";
    	}	
	}
	
	if(n == 2)
	{
		int d = 2;
		int minn = 2e9 + 10;
    	for(int i = 1; i <= n - d + 1; i ++)
    	{
        	map[d][i] = abs(h[i + d - 1] - h[i]);
            minn = min(minn, map[d][i]);
        }

	    cout << minn << " ";
	}


    for(int d = 4; d <= n; d ++)
    {
        int minn = 2e9 + 10;

        for(int i = 1; i <= n - d + 1; i ++)
        {
            map[d][i] = map[d - 2][i + 1] + abs(h[i + d - 1] - h[i]);
            minn = min(minn, map[d][i]);
        }

        cout << minn << " ";
    }


    return 0;
}