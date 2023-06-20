#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 2e2 + 10;

using namespace std;

int n, m, sx, sy, K, ans;
int f[N][N];
int dx[5] = {0, -1, 1, 0, 0}, 
    dy[5] = {0, 0, 0, -1, 1}; 

char map[N][N];

struct node
{
    int dp, p;
}q[N];


void work(int x, int y, int len, int d) 
{
	int head = 1, tail = 0;
	for(int i = 1; x >= 1 && x <= n && y >= 1 && y <= m; i++)
    {
		if(map[x][y] == 'x') 
        {
            head = 1;
            tail = 0;

            x += dx[d];
            y += dy[d];

            continue;
        }

		while(head <= tail && q[tail].dp + i - q[tail].p < f[x][y]) 
            tail--;

		q[++tail] = node{f[x][y], i};
		if(q[tail].p - q[head].p > len) 
            head++;

		f[x][y] = q[head].dp + i - q[head].p;
		
        ans = max(ans, f[x][y]);
            
        x += dx[d];
        y += dy[d];
    }
}


int main()
{
	memset(f, 0xf3, sizeof(f));

    cin >> n >> m >> sx >> sy >> K;

	f[sx][sy] = 0;

	for(int i = 1; i <= n; i++) 
        cin >> map[i] + 1;

	for(int k = 1; k <= K; k++)
	{
        int s, t, d;
        cin >> s >> t >> d;

		int len = t - s + 1;

		if(d == 1) 
            for(int i = 1; i <= m; i++) 
                work(n, i, len, d);

		if(d == 2) 
            for(int i = 1; i <= m; i++) 
                work(1, i, len, d);

		if(d == 3)  
            for(int i = 1; i <= n; i++) 
                work(i, m, len, d);

		if(d == 4) 
            for(int i = 1; i <= n; i++) 
                work(i, 1, len, d);

	}
    
    cout << ans << endl;

    return 0;

}