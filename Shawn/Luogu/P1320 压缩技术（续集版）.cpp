#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int n, tot;
char tmp[1000];
char g[100000];

int main()
{
    for(int i = 0; i <= 40; i ++)
        tmp[i] = 'a';
    cin >> tmp + 1;
    // gets(tmp);

    // for(int i = 0; i <= 9; i ++)
    //     cout << tmp[i] << " ";
    // cout << endl;

    for(n = 1; tmp[n] == '0' || tmp[n] == '1'; n ++)
        g[++ tot] = tmp[n];
    n --;
    
    for(int i = 2; i <= n; i ++)
    {
        cin >> tmp + 1;
        for(int j = 1; j <= n; j ++)
            g[++ tot] = tmp[j];
    }

    // for(int i = 1; i <= n * n; i ++)
        // cout << g[i] << " ";

    // while(cin >> tmp + 1)
    // {
    //     if(tmp == EOF)
    //         break;
    //     for(int i = 1; i <= )
    // }

    cout << n << " ";

    char pre = '0';
    int sum = 0;
    for(int i = 1; i <= n * n; i ++)
    {
        if(g[i] == pre)
            sum ++;
        else
        {
            cout << sum << " ";
            sum = 1;
            pre = g[i];
        }
    }

    cout << sum << endl;

    return 0;
}