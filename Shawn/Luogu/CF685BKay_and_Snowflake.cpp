#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 300000 + 10;

using namespace std;

int ver[N], head[N], nxt[N];
int tot = 1;

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, nxt[tot] = head[y], head[y] = tot;
}

int main()
{

}