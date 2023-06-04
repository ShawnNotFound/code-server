#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

#define mod %

const int N = 5e5 + 10;

using namespace std;

int b[N];
int a[N];
int n, m;
bool flag;
int tot;
bool finish;

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= m; i ++)
        cin >> a[i];



    for(int i = 1; i <= m; i ++)
    {
        int cnt = 0;
        int now = 0;            
        if(finish)
        {
            cout << "0 ";
            continue;
        }
        while(1)
        {

            
            if(!b[now] && (now != 0 || flag == false))
            {
                cnt ++;
                tot ++;
                if(tot == n)
                    finish = true;
            }
            
            else if(b[now] == i)
                break;

            b[now] = i;

            now = (now + a[i]) mod n;
        }

        if(b[0])
        {
            b[0] = 0;
            flag = true;
        }

        cout << cnt << " ";
    }

    cout << endl;

    return 0;
}