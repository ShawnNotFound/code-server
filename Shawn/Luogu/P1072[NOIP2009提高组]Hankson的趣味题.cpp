#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int a0, a1, b0, b1, n;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    cin >> n;

    while(n --)
    {
        int ans = 0;
        cin >> a0 >> a1 >> b0 >> b1;

        int da = a0 / a1, db = b1 / b0;

        for(int x = 1; x * x <= b1; x ++)
        {
            //cout << "debug:" << b1 << " " << x << endl;
            if(!(b1 % x))
            {
                if((!(x % a1)) && (gcd(x / a1, da) == 1) && (gcd(b1 / x, db) == 1))
                //cout << gcd(x, da) << " " << gcd(x / db, db) << endl;
                //if((gcd(x, da) == 1) && (gcd(x / db, db) == 1))
                    ans ++;
                int y = b1 / x;
                if(y == x)
                    continue;
                if((!(y % a1)) && (gcd(y / a1, da) == 1) && (gcd(b1 / y, db) == 1))
                //if((gcd(y, da) == 1) && (gcd(y / db, db) == 1))
                    ans ++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<cmath>

// using namespace std;

// int a0, a1, b0, b1, n;

// int gcd(int a, int b)
// {
//     return b == 0 ? a : gcd(b, a % b);
// }
// int main() {
//     int T;
//     scanf("%d",&T);
//     while(T--) {
//         cin >> a0 >> a1 >> b0 >> b1;
//         int p=a0/a1,q=b1/b0,ans=0, da = p, db = q;
//         for(int x=1;x*x<=b1;x++) 
//             if(!(b1%x)){
//                 if(!(x%a1)&&gcd(x/a1,p)==1&&gcd(q,b1/x)==1) ans++;
//                 int y=b1/x;//得到另一个因子
//                 if(x==y) continue; 
//                 //if(!(y%a1)&&gcd(y/a1,da)==1&&gcd(db,b1/y)==1) ans++;
//                 if((!(y / a1)) && (gcd(y / a1, da) == 1) && (gcd(b1 / y, db) == 1))
//                     //ans ++;
//             }
//         cout << ans << endl;
//     }
//     return 0;
// }