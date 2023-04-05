#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

#define x first
#define y second

const int N = 55;

using namespace std;

typedef pair<int, int> PII;

PII q[N];

int n, m, ans;

int calc()
{
    int res = 0;
    for(int i = 1; i <= m; i ++)
    {
        res += q[i].x + q[i].y;
        if(i <= n)
        {
            if(q[i].x == 10)
                res += q[i + 1].x + q[i + 1].y;
            else if(q[i].x + q[i].y == 10)
                res += q[i + 1].x;
        }
    }
    ans = max(ans, res);
    return res;
}

void simulate_anneal()
{
    for(double t = 1e4; t > 1e-4; t *= 0.99)
    {
        int a = rand() % m + 1, b = rand() % m + 1;
        int x = calc();
        swap(q[a], q[b]);
        if(n + (q[n].x == 10) == m)
        {
            int y = calc();
            int delta = y - x;
            if(exp(delta / t) < (double)rand() / RAND_MAX)  
                swap(q[a], q[b]);
        }
        else
            swap(q[a], q[b]);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)    
        cin >> q[i].x >> q[i].y;
    
    if(q[n].x == 10)
    {
        m = n + 1;
        cin >> q[m].x >> q[m].y;
    }
    else
        m = n;
    
    while((double)clock() / CLOCKS_PER_SEC < 0.8)
        simulate_anneal();

    cout << ans << endl;

    return 0;
}

