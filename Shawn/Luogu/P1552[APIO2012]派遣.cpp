#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

struct node
{
    int fa, cost, lead;
}R[N << 2];

int n, m;
long long ans;
int size[N], root[N], dis[N], ls[N], rs[N];
long long sum[N];

void build(int now)
{
    size[now] =  1;
    root[now] = now;
    sum[now] = R[now].cost;
}

int merge(int A, int B)
{
    
}

int main()
{
    
}