#include<iostream>
#include<cstring>

using namespace std;

int n;
char target[15][15];
char map[15][15];
char map90[15][15], map180[15][15], map270[15][15];
char mapr[15][15];
char mapr90[15][15], mapr180[15][15], mapr270[15][15];

void generate_map90()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            map90[i][j] = map[n - j + 1][i];
}

void generate_map180()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            map180[i][j] = map90[n - j + 1][i];
}

void generate_map270()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            map270[i][j] = map180[n - j + 1][i];
}

void generate_mapr()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            mapr[i][j] = map[i][n - j + 1];
}

void generate_mapr90()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            mapr90[i][j] = mapr[n - j + 1][i];
}

void generate_mapr180()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            mapr180[i][j] = mapr90[n - j + 1][i];
}

void generate_mapr270()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            mapr270[i][j] = mapr180[n - j + 1][i];
}


int main()
{
    cin >> n;
    char tmp[15];
    for(int i = 1; i <= n; i ++)
    {
        cin >> tmp + 1;
        for(int j = 1; j <= n; j ++)
            map[i][j] = tmp[j];
    }
    for(int i = 1; i <= n; i ++)
    {
        cin >> tmp + 1;
        for(int j = 1; j <= n; j ++)
            target[i][j] = tmp[j];
    }

    generate_map90();
    bool flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(map90[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 1 << endl;
        return 0;
    }

    generate_map180();
    flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(map180[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 2 << endl;
        return 0;
    }

    generate_map270();
    flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(map270[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 3 << endl;
        return 0;
    }

    generate_mapr();
    flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(mapr[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 4 << endl;
        return 0;
    }

    generate_mapr90();
    flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(mapr90[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 5 << endl;
        return 0;
    }

    generate_mapr180();
    flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(mapr180[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 5 << endl;
        return 0;
    }

    generate_mapr270();
    flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(mapr270[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 5 << endl;
        return 0;
    }

    //original graph
    flag = true;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(map[i][j] != target[i][j])
            {
                flag = false;
                break;
            }
    if(flag)
    {
        cout << 6 << endl;
        return 0;
    }

    cout << 7 << endl;

    return 0;

}