#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int,int> PII;

const int N = 50010;

int n;
int f[N];
PII p[N];

void init()
{
    for(int i = 1; i <= n; i ++)
        f[i] = 1;
}

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i ++) 
        cin >> p[i].x >> p[i].y;
    
    sort(p + 1, p + n + 1);
    
    init();
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= i; j ++)
        {
            if (p[j].y < p[i].y) f[i] = max(f[i], f[j] + 1);
        }
    }
    int res = 1;
    
    for (int i = 1; i <= n; i ++) 
        res = max(res, f[i]);
        
    cout << res << endl;
    
    return 0;
}