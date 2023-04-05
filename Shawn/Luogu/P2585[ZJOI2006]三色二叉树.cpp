#include<iostream>
#include<cstdio>
#include<cstring>

const int N = 500050;

using namespace std;

char s[N];
int f_max[N][4], f_min[N][4], cnt;
int ans1 = 1;

void dfs(int x) {
	if (s[x] == '0') 
    {
		f_min[x][0] = f_max[x][0] = 1;
		return;
	}
	dfs(++ cnt);
    //左儿子编号为x+1
	if (s[x] == '1') 
    {
		f_max[x][0] = max(f_max[x + 1][1], f_max[x + 1][2]) + 1;
		f_max[x][1] = max(f_max[x + 1][0], f_max[x + 1][2]);
		f_max[x][2] = max(f_max[x + 1][0], f_max[x + 1][1]);
        
		f_min[x][0] = min(f_min[x + 1][1], f_min[x + 1][2]) + 1;
		f_min[x][1] = min(f_min[x + 1][0], f_min[x + 1][2]);
		f_min[x][2] = min(f_min[x + 1][0], f_min[x + 1][1]);
	}
	else 
    {
		int k = ++ cnt;
		dfs(k);
		f_max[x][0] = max(f_max[x + 1][1] + f_max[k][2], f_max[x + 1][2] + f_max[k][1]) + 1;
		f_max[x][1] = max(f_max[x + 1][0] + f_max[k][2], f_max[x + 1][2] + f_max[k][0]);
		f_max[x][2] = max(f_max[x + 1][0] + f_max[k][1], f_max[x + 1][1] + f_max[k][0]);
		
		f_min[x][0] = min(f_min[x + 1][1] + f_min[k][2], f_min[x + 1][2] + f_min[k][1]) + 1;
		f_min[x][1] = min(f_min[x + 1][0] + f_min[k][2], f_min[x + 1][2] + f_min[k][0]);
		f_min[x][2] = min(f_min[x + 1][0] + f_min[k][1], f_min[x + 1][1] + f_min[k][0]);
	}
	ans1 = max(ans1, f_max[x][0]);
}


int main()
{
	cin >> s + 1;

	dfs(++ cnt);

	cout << ans1 << ' ' << min(f_min[1][0], min(f_min[1][1], f_min[1][2])) << endl;

	return 0;
}
