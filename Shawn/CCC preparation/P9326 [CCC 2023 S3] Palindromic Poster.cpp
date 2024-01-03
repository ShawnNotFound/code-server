#include<iostream>
#include<cstring>
#include<cmath>

#define mod %

const int N = 2e3 + 10;

using namespace std;

char map[N][N];    
char rowa[N], rowb[N];    
int n, m, r, c, rr, cc;

void setrowa(int n)
{
    for(int i = 1; i <= m; i ++)
    {
        map[i][n] = rowa[i];
    }
}

void setrowb(int n)
{
    for(int i = 1; i <= m; i ++)
    {
        map[i][n] = rowb[i];
    }
}


void construct()
{
    // if(n mod 2 == 1 && m mod 2 == 1)
    // {
    //     for(int i = 1; i <= n; i ++)
    //     {
    //         for(int j = 1; j <= m; j ++)
    //         {
    //             map[i][j] = ((i + j) mod 2 == 0) ? 'a' : 'b';
    //         }
    //     }
    // }

    // if(n mod 2 == 0 && m mod 2 == 1)
    // {
    //     for(int i = 1; )
    // }

    //row a

    if(n mod 2 == 1)
        for(int i = 1; i <= n; i ++)
        {
            rowa[i] = (i mod 2 == 1) ? 'a' : 'b';
        }
    if(n mod 2 == 0)
    {
        for(int i = 1; i <= n / 2; i ++)
        {
            rowa[i] = (i mod 2 == 1) ? 'a' : 'b';
            rowa[n - i + 1] = rowa[i];
        }
    }

    //row b

    if(n mod 2 == 1)
        for(int i = 1; i <= n; i ++)
        {
            rowb[i] = (i mod 2 == 0) ? 'a' : 'b';
        }
    if(n mod 2 == 0)
    {
        for(int i = 1; i <= n / 2; i ++)
        {
            rowb[i] = (i mod 2 == 0) ? 'a' : 'b';
            rowb[n - i + 1] = rowb[i];
        }
    }    

    // construct final

    if(m mod 2 == 1)
    {
        for(int i = 1; i <= m; i ++)
        {
            i mod 2 == 1 ? setrowa(i) : setrowb(i);
        }
    }

    if(m mod 2 == 0)
    {
        for(int i = 1; i <= m / 2; i ++)
        {
            if(i mod 2 == 1)
            {
                setrowa(i);
                setrowa(m - i + 1);
            }
            else
            {
                setrowb(i);
                setrowb(m - i + 1);
            }
        }
    }
}

void finish()
{
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
            cout << map[i][j];
        cout << endl;
    }
}

int main()
{
    cin >> n >> m >> rr >> cc;
    
    r = n - rr;
    c = m - cc;

    construct();

    finish();
    cout << endl;

    if(r == n)
    {
        if(c mod 2 == 1)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        for(int i = 1; i <= c / 2; i ++)
        {
            map[n][1] = 'e';
            map[n - i + 1][1] = 'e';
        }

        finish();
        
        return 0;
    }

    if(c == m)
    {
        if(r mod 2 == 1)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        for(int i = 1; i <= r / 2; i ++)
        {
            map[1][i] = 'e';
            map[1][m - i + 1] = 'e';
        }

        finish();

        return 0;
    }

    if(r == 0)
        c += 1;
    if(c == 0)
        r += 1;

    for(int i = 1; i <= c - 1; i ++)
        map[n][i] = 'e';
    for(int i = 1; i <= r - 1; i ++)
        map[i][m] = 'e';


    bool flag = true;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(map[i][j] == 'e')
            {
                flag = false;
            }
        }
    }
    
    if(!flag)
        finish();
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}