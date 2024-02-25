#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> map;
vector<int> c, v;

void init()
{
    map.resize(n + 1);
    c.assign(m + 1, -1);
    v.assign(n + 1, 0);
}

void dfs(int uu, int cc) 
{
    v[uu] = 1;
    for (int i = 0; i < map[uu].size(); i++) 
    {
        int ver = map[uu][i].first;
        int edgeIndex = map[uu][i].second;
        if (!v[ver]) 
        {
            c[edgeIndex] = cc;
            dfs(ver, cc ^ 1);
        }
    }
}

int main() 
{
    cin >> n >> m;

    init();

    for (int i = 1; i <= m; i++) 
    {
        int st, ed;
        cin >> st >> ed;

        map[st].emplace_back(ed, i);
        map[ed].emplace_back(st, i);
    }

    for (int i = 1; i <= n; i ++)
        if (v[i] == false) 
            dfs(i, 0);

    for (int i = 1; i <= m; i ++) 
    {
        if(c[i] == -1)
            cout << 'G';
        else if(c[i] == 0)
            cout << 'B';
        else
            cout << 'R';
    }

    cout << endl;

    return 0;
}