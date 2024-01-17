#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int ans = 0;

char map[30] = {            1, 2, 3,    1, 2, 3, 
                1, 2, 3,    1, 2, 3,    1, 2, 3,
             1, 2, 3, 4,    1, 2, 3,    1, 2, 3, 4};
char s[510];

int main()
{
    cin.getline(s, 300);
    int ls = strlen(s);
    for(int i = 0; i <= ls - 1; i ++)
    {
        if(s[i] == ' ')
        {
            ans += 1;
            continue;
        }
        ans += map[s[i] - 'a'];
    }

    cout << ans << endl;

    return 0;
}