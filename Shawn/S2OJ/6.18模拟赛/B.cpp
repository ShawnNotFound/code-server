// B. 阶乘

#include <iostream>
#include <cstring>

const int N = 1e6 + 10;
const int BIGN = 1e7;

using namespace std;

long long m, pm, num, l, r, ans, i, n, j;
long long a[BIGN], t[BIGN], b[BIGN], p[BIGN];
bool f[BIGN];


void add(long long x) 
{
    while(x > 1) 
    {
        if(b[x] > pm) 
            pm = b[x];
        t[b[x]] ++;
        x = x / b[x];
    }
}

bool check(long long x) 
{
    for(i = 1; i <= pm; i++) 
    {
        if(f[i] == false) 
            continue;
        j = i;
        long long s = 0;
        while(j <= x) {
            s = s +(x / j);
            j = j * i;
            if(s >= t[i]) break;
        }
        if(s < t[i]) return false;
    }
    return true;
}

void init() 
{    
    f[0] = false;
    f[1] = false;
    for(i = 2; i <= N; i++) 
    {
        if(f[i] == true) 
        {
            num++;
            p[num] = i;
            b[i] = i;
        }
        for(j = 1; j <= num; j++) 
        {
            f[p[j] * i] = false;
            b[p[j] * i] = b[i];
            if(i % p[j] == 0) break;
            if(i * p[j + 1] > N) break;
        }
    }
    

}

int main() 
{

    cin >> n;

    memset(f, true, sizeof(f));

    init();

    for(i = 1; i <= n; i++) 
    {
        cin >> a[i];
        add(a[i]);
    }
    
    l = pm;
    r = BIGN;

    while(l < r) 
    {
        m = (l + r) / 2;
        if(check(m)) 
            r = m;
        else l = m + 1;
    }

    cout << l << endl;
    return 0;
}