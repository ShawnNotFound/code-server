#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

const int N = 2e5 + 10;

using namespace std;

int T, tot, cnt;
bool two, finish;
int v[N];

void init()
{
    two = false;
    finish = false;
    cnt = 0;
}

int main()
{
    cin >> T;
    while(T --)
    {
        init();
        int n, m;
        cin >> n >> m;
        
        for(int i = 1; i <= m; i ++)
        {
            int opt, x;
            cin >> opt >> x;
            if(finish)
                continue;

            if(opt == 1)
            {
                if(v[tot + x] == 0)
                {
                    v[tot + x] = 1;
                    //cout << tot + x << " added, cnt is now " << cnt << endl;
                    cnt ++;
                    if(cnt == n)
                    {
                        cout << i << endl;
                        finish = true;
                    }
                }
                
                else if(v[tot + x] == 2)
                {
                    cout << i << endl;
                    finish = true;
                }
            }
            if(opt == 2)
            {
                if(!two)
                {
                    two = true;
                    if(v[tot + x] == 1)
                    {
                        cout << i << endl;
                        finish = true;
                    }
                    else if(v[tot + x] == 0)
                        v[tot + x] = 2;
                }
                else if(two)
                {
                    if(v[tot + x] == 0)
                    {
                        cout << i << endl;
                        finish = true;
                    }
                    else if(v[tot + x] == 1)
                    {
                        cout << i << endl;
                        finish = true;
                    }
                }
            }
        }
        if(!finish)
        {
            cout << -1 << endl;
        }
        tot += n;
    }
}