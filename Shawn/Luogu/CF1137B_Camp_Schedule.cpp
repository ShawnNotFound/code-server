#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 5e5 + 10;

using namespace std;

int n, a, b;
int f[N];
char s[N],p[N];

int main()
{
    while(cin >> s)
    {
        cin >> p;
        n = strlen(p);

        f[0] = -1;
        for(int i = 1; i < n; i ++)
        {
            for(int j = f[i - 1]; ; j = f[j])
            { 
                if(p[i] == p[j + 1])
                {
                    f[i] = j + 1;
                    break;
                }
                else if(j == -1)
                {
                    f[i] = -1;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i ++)
            f[i] ++;

        a = b = 0;

        int si = strlen(s);

        for(int i = 0; i < si; i ++)
        {
            if(s[i] == '0')
                a ++;
            else
                b ++;
        }
        
        int xx = 0, yy = 0;
        
        for(int i = 0; i < f[n - 1]; i ++)
        {
            if(p[i] == '0')
                xx ++;
            else
                yy ++;
        }
        
        if(a >= xx && b > yy)
        {
            for(int i = 0; i < f[n - 1]; i ++)
                cout << p[i];
            
            a -= xx;
            b -= yy;
            
            int tx = 0, ty = 0;
            for(int i = f[n - 1]; i < n; i ++)
            {
                if(p[i] == '0')
                    tx ++;
                else
                    ty ++;
            }
            
            int flag = 0;
            while(a > 0 && b > 0)
            {
                if(a < tx || b < ty)
                    break;
                for(int i = f[n - 1]; i < n; i ++)
                    cout << p[i];
                
                a -= tx;
                b -= ty;
            }
            
            while(a > 0)
            {
                cout << 0;
                a --;
            }
            while(b > 0)
            {
                cout << 1;
                b --;
            }
        }
        else
            cout << s << endl;
    }
   
    return 0;
}