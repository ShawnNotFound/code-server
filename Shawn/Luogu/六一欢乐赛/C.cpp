#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 1e6 + 10;
const int M = 2e3 + 10;
const int INF = 1 << 29;

using namespace std;

int nn, mm;
int m[M], n[N], need;
int l = 1;
int cnt, ll, rr;
int len = INF;

int main()
{
    memset(m, -1, sizeof(m));

    cin >> nn >> mm;
    for(int i = 1; i <= nn; i ++)
        cin >> n[i];
    
    for(int i = 1; i <= nn; i ++)
    {
        if(m[n[i]] == -1)
            cnt ++;

        m[n[i]] = i;

        while(l != i && l < m[n[l]])
            l ++;
        
        if(cnt == mm & i - l + 1 < len)
        {
            len = i - l + 1;
            ll = l;
            rr = i;
        }
    }

    cout << ll << " " << rr << endl;

    return 0;
}