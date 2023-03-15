#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

const int N = 2e5 + 10;

using namespace std;

queue<int> q;
int edge[N], ver[N], head[N], nxt[N];
bool v[N];

void spfa()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    q.push(1); d[1] = 0; v[1] = true;
    while(q.size())
    {
        int x = q.front(); q.pop();
        v[x] = false;
        if(used[x]) continue;
        used[x] = true;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = -1;
            if(d[y] > d[x] + z)
            {
                d[y] = d[x] + z;
                if(!v[y]) q.push(y), v[y] = true;
            }
        }
    }
}

int main()
{

}