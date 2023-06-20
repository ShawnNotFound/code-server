// C. 小S练跑步

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

const int N = 5e2 + 10;

using namespace std; 


char tmp[N]; 
int n, m;
int map[N][N]; 
bool v[N][N]; 

int dirx[5] = {0, 0, 1, 0, -1}, 
    diry[5] = {0, 1, 0, -1, 0};

queue<int>qx, qy, dis; 

void init()
{
	map[n][m]=-1;   

    qx.push(1); 
    qy.push(1); 
    dis.push(-1); 
}

void solve()
{
    while (qx.size())
    {
    	int xx = qx.front();
        int yy = qy.front(); 
    	
        if(map[xx][yy] == 5)
            continue;

    	for(int i = 1;i <= 4; i ++)
    	{
            for(int k = 1; 1; k ++)
            { 
                int tmpx = xx + k * dirx[i];
                int tmpy = yy + k * diry[i];

                // ---------------------------- //

                if(tmpx < 1 || tmpy < 1 || tmpx > n || tmpy > m || map[tmpx][tmpy] == 5) 
                    break; 

                if(map[tmpx - dirx[i]][tmpy - diry[i]] == i) 
                    break; 

                if(v[tmpx][tmpy]) 
                    continue;

                // ----------------------------- //
                qx.push(tmpx); 
                qy.push(tmpy); 
                dis.push(dis.front() + 1);

                v[tmpx][tmpy] = true;

                if(tmpx == n && tmpy == m) 
                {
                    cout << dis.front() + 1 << endl;
                    return; 
                }
            }
        }
        qx.pop(); 
        qy.pop(); 
        dis.pop(); 
	}

    cout << "No Solution!" << endl;

    return; 
}
int main()
{
    ios::sync_with_stdio(false);
    
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
    {
        cin >> tmp + 1;
        for(int j = 1; j <= m; j ++)
        {
            if(tmp[j] == 'R')
                map[i][j] = 1;
            if(tmp[j] == 'D')
                map[i][j] = 2;
            if(tmp[j] == 'L')
                map[i][j] = 3;
            if(tmp[j] == 'U')
                map[i][j] = 4;
            if(tmp[j] == 'S')
                map[i][j] = 5;
        }
    }

    init();

	solve();

    return 0;
}