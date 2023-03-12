#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 50 + 5;
const int M = 1e3 + 5; 

using namespace std;

int map[N][N];

int main()
{
    int n, m, k, a, b, t;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a >> b >> t;
        map[a][b] = t;
    }
    
    return 0;
}