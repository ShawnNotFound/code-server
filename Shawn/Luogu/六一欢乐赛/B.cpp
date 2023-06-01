#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e5 + 10;
const int INF = 1 << 29;

#define tmp1 abs(map[i]) + abs(map[i] - map[i + m])
#define tmp2 abs(map[i]) + abs(map[i] - map[i - m])

using namespace std;

int n, m, ans = INF;
int map[N];

inline int min(int a, int b, int c)
{
    return min(a, min(b, c));
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        cin >> map[i];
    
    m --;
    for(int i = 1; i <= n; i ++)
    {

        if((i + m <= n) && (i - m > 0))
            ans = min(ans, tmp1, tmp2);

        else if(i + m <= n)
            ans = min(ans, tmp1);
        
        else if(i - m > 0)
            ans = min(ans, tmp2);

    }

    cout << ans << endl;

    return 0;    

}