#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 1e7 + 10;

using namespace std;

int n, m;
int a[N];
int q1[N], q2[N];

void work_min()
{
    int h = 1, t = 0;

    for(int i = 1; i <= n; i ++)
    {
        while(h <= t && q1[h] + m <= i)
            h ++;
        while(h <= t && a[i] < a[q1[t]])
            t --;
        
        q1[++ t] = i;

        if(i >= m)
            cout << a[q1[h]] << " ";
    }

    cout << endl;
}

void work_max()
{
    int h = 1, t = 0;

    for(int i = 1; i <= n; i ++)
    {
        while(h <= t && q2[h] + m <= i)
            h ++;
        while(h <= t && a[i] > a[q2[t]])
            t --;
        
        q2[++ t] = i;

        if(i >= m)
            cout << a[q2[h]] << " ";
    }

    cout << endl;
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    work_min();

    work_max();

    return 0;
}