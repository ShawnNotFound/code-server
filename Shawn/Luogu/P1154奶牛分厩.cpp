#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 5e3 + 10;

using namespace std;

int s[N];
int n;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> s[i];

    for(int ans = 1; 1; ans ++)
    {
        int tmp = s[1];
        for(int i = 2; i <= n; i ++)
        {
            int tmpp = (s[i] % ans) ? ans : (s[i] % ans);
            tmp = gcd(tmp, tmpp);
            cout << tmp << " ";
            if(tmp == 1)
            {
                cout << ans << endl;
                return 0;
            }
        }
        cout << endl;
    }
}
//1   
//4 6 1 2 5