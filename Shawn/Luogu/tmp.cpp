#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

char p[1000010];
char t[20];
char tmp[110];
int diff = 'A' - 'a';

bool scmp()
{
    if(strlen(t) != strlen(tmp))
        return false;
    for(int i = 0; i <= strlen(t) - 1; i ++)
    {
        if(t[i] != tmp[i] && t[i] != tmp[i] + diff && t[i] + diff != tmp[i])
            return false;
    }
    return true;
}
int ans = -1;
int main()
{
    int cnt = 0;
    int space = -1;
    // cin >> t;
    cin.getline(t, 15);
    // cout << t << endl;
        memset(tmp, 0, sizeof(tmp));
        cin.getline(p, 1001000);
        cout << p << endl;
        // if(tmp[0] == 0)
        //     break;
        // p[strlen(p) + 1] = ' ';
        int lp = strlen(p) - 1;
        cout << strlen(p) <<endl;
        cout << lp << endl;
        int tt = -1;
        int st = 0;
        for(int i = 0; i <= lp; i ++)
        {
            cout << "in here" << endl;
            if(p[i] == ' ')
            {
                cout << "reset here" << endl;
                memset(tmp, 0, sizeof(0));
                tt = -1;
                st = i + 1;
                continue;
            }
            tmp[++ tt] = p[i];
            if(tt == strlen(t) - 1)
            {
                cout << "here equal " << tt << endl;
                // for(int j = 0; j <= tt; j ++)
                    if(scmp())
                    {
                        cnt ++;
                        if(cnt == 1)
                            ans = st;
                        cout << cnt << " " <<ans << "(debug)" << endl;
                    }
            }
        }
    if(ans == -1)
        cout << -1 << endl;
    else
        cout << cnt << " " << ans << endl;

    return 0;
}