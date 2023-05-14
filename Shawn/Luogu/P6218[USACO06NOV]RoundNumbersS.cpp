#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int a[50], f[50][65], vis[50][65];
int len, l, r;

int dp(bool limit, bool lead, int pos, int diff) 
{
	if(pos == 0)    
        return diff >= 30;

	if(!limit && !lead && vis[pos][diff]) 
        return f[pos][diff];

	int res = 0;
	int up = limit ? a[pos] : 1;

	for(int i = 0;i <= up; i ++) 
    {
		res += dp(limit & (i == a[pos]), lead & (i == 0), pos - 1, diff + (i == 0 ? (lead ? 0 : 1) : -1));
	}

	if(!limit && !lead)
    {
        vis[pos][diff] = 1;
        f[pos][diff] = res;
    }

	return res;
}
int solve(int x) {
	len = 0;

	while(x) 
    {
		a[++ len] = x % 2;
		x /= 2;
	}

	return dp(1, 1, len, 30);
}
int main() {
    cin >> l >> r;

	cout << solve(r) - solve(l - 1) << endl;

    return 0;
}