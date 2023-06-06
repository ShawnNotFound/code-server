#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define mod %

const int N = 1e6 + 10;
const int M = 1e9 + 7;

using namespace std;

int T;
int fail[N], ans[N];
long long cnt;
char a[N];

int main()
{
    cin >> T;

    while(T --)
    {
        cin >> a;
        int l = strlen(a);
        memset(fail, 0, sizeof(fail));

        int j = 0;
        ans[0] = 0;
        ans[1] = 1;

        for(int i = 1; i < l; i ++)
        {
            while(j && a[i] != a[j])
                j = fail[j];

            if(a[i] == a[j])
                j ++;
            
            fail[i + 1] = j;
            ans[i + 1] = ans[j] + 1;
        }

        j = 0;
        cnt = 1;

        for(int i = 1; i < l; i ++)
        {
            while(j && (a[i] != a[j]))  
                j = fail[j];

            if(a[i] == a[j])
                j ++;

            while((j << 1) > (i + 1))
                j = fail[j];

            cnt = (cnt * (long long)(ans[j] + 1)) mod M;
        }

        cout << cnt << endl;
    }    

    return 0;
}