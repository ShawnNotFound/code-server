#include<iostream>
#include<cstring>

using namespace std;

int n;
int map[15][15];

int x = 1, y = 1, tot = 1;

void runx();
void runy();
void rundx();
void rundy();

void runx()
{
    // cout << "runx" << endl;
    y ++;
    if(map[x][y] != 0)
        return;
    while(map[x][y] == 0)
    {
        map[x][y ++] = ++ tot;
    }
    y --;
    runy();
}

void runy()
{
    // cout << "runy" << endl;
    x ++;
    if(map[x][y] != 0)
        return;
    while(map[x][y] == 0)
        map[x ++][y] = ++ tot;
    x --;
    rundx();
}

void rundx()
{
    // cout << "rundx" << endl;
    y --;
    if(map[x][y] != 0)
        return;
    while(map[x][y] == 0)
        map[x][y --] = ++ tot;
    y ++;
    rundy();
}

void rundy()
{
    // cout << "rundy" << endl;
    x --;
    if(map[x][y] != 0)
        return;
    while(map[x][y] == 0)
        map[x --][y] = ++ tot;
    x ++;
    runx();
}

int main()
{
    memset(map, -1, sizeof(map));

    cin >> n;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            map[i][j] = 0;

    map[1][1] = 1;


    runx();

    cout << " ";

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(map[i][j] < 10)
                cout << " ";
            cout << map[i][j] << " ";
        }
        cout << endl << " ";
    }

    return 0;
}