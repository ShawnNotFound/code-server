#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

struct node
{
    int num;
    int type;
}

queue<node> q;

struct trie
{
    int word;
    int map[N][30], end[N];
    int fa[N], fail[N], dis[N];

    int insert(int p, char c)
    {
        if(map[p][c - 'a' + 1] != 0)
            return map[p][c - 'a' + 1];

        map[]
    }

}