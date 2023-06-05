#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 8e5 + 10;

using namespace std;

int n, q;
int son[N], rt[N];
bool b[N];

void flip(int x)
{
    b[x] = !b[x];
}

void query(int x)
{
    for(int i = x; i; i = son[i])
    {
        if(b[i])
        {
            cout << x << endl;
            return;
        }
    }    
    
    for(int i = rt[x]; i; i = rt[i])
    {
        if(b[i])
        {
            cout << i << endl;
            return;
        }
    }

    cout << 0 << endl;
    
    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    
    // freopen("C.out", "w", stdout);

    rt[1] = 0;

    cin >> n >> q;
    for(int i = 2; i <= n; i ++)
    {
        int tmp;
        cin >> tmp;

        rt[i] = tmp;
        son[tmp] = i;
    } 

    for(int i = 1; i <= q; i ++)
    {
        int x;
        cin >> x;
        
        if(x > 0)
        {
            flip(x);
        }
        if(x <= 0)
        {
            query(-x);
        }
    }

    return 0;
}

