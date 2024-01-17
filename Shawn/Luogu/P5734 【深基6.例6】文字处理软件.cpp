#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int q, opt;
char trans[1010];
char map[1010];

void fextend()
{
    for(int i = 0; i <= strlen(trans) - 1; i ++)
    {
        map[strlen(map)] = trans[i];
    }

    for(int i = 0; i <= strlen(map) - 1; i ++)
        cout << map[i];
    cout << endl;
    // cout << strlen(map) << endl;
}

void fsubstr(int a, int b)
{
    char tmp[1010];
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i <= b - 1; i ++)
    {
        tmp[i] = map[a + i];
    }
    memset(map, 0, sizeof(map));
    for(int i = 0; i <= strlen(tmp) - 1; i ++)
    {
        // cout << "Debug: " << i << endl;
        map[i] = tmp[i];
    }

    // cout << "Debug:" << strlen(tmp) << endl;
    for(int i = 0; i <= strlen(map) - 1; i ++)
    {
        cout << map[i];
    }
    cout << endl;
}

void finsert(int a)
{
    char ttmp[1010];
    memset(ttmp, 0, sizeof(ttmp));

    int lmap = strlen(map);
    
    for(int i = a; i <= lmap - 1; i ++)
    {
        ttmp[i] = map[i];
    }
    for(int i = a; i <= lmap - 1; i ++)
    {
        map[i + strlen(trans)] = ttmp[i];
    }

    for(int i = 0; i <= strlen(trans) - 1; i ++)
    {
        map[a + i] = trans[i];
    }

    for(int i = 0; i <= strlen(map) - 1; i ++)
        cout << map[i];
    cout << endl;
}

void ffind()
{
    int ans = -1;
    for(int i = 0; i <= strlen(map) - 1; i ++)
    {
        bool flag = true;
        for(int j = 0; j <= strlen(trans) - 1; j ++)
        {
            ans = i;
            if(map[i + j] != trans[j])
            {
                ans = -1;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << ans << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main()
{
    int ta, tb;
    cin >> q;
    cin >> map;
    // cout << "debug: " << strlen(map) << endl;
    for(int i = 1; i <= q; i ++)
    {
        cin >> opt;
        if(opt == 1)
        {
            cin >> trans;
            fextend();
        }
        else if(opt == 2)
        {
            cin >> ta >> tb;
            fsubstr(ta, tb);
        }
        else if(opt == 3)
        {
            cin >> ta >> trans;
            finsert(ta);
        }
        else if(opt == 4)
        {
            cin >> trans;
            ffind();
        }
    }
}