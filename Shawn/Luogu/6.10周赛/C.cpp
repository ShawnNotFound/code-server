#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

map<string, int> p;

int n, tot;
string o[20];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        string tmp;
        cin >> tmp;
        p[tmp] = 0;
        o[++ tot] = tmp;
    }   
    for(int i = 1; i <= n; i ++)
    {
        string g;
        int m, num;

        cin >> g >> m >> num;

        int per = num ? m / num : 0;

        // p[g] -= (num ? m : 0);
        p[g] -= per * num;

        for(int j = 1; j <= num; j ++)
        {
            string tmp;
            cin >> tmp;
            p[tmp] += per;
        }


    }        
    for(int i = 1; i <= n; i ++)
        cout << o[i] << " " << p[o[i]] << endl;

    return 0;
}