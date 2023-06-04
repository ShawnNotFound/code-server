// #include<iostream>
// #include<cstring>
// #include<cmath>
// #include<algorithm>

// #define int long long 

// using namespace std;

// char x[15], y[10], z[15];

// signed main()
// {
//     cin >> y + 1 >> z + 1;

//     int lenz = strlen(z + 1);


//     for(int i = 1; i <= 12; i ++)
//     {
//         if(i < 12 - lenz)
//             x[i] = '9';
//         else if(i == 12 - lenz)

//     }
// }

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string y, z;
    cin >> y >> z;

    // 枚举前六位
    long long ans = 1e18;
    for (int i = 0; i < 1000000; i++) {
        string x_str = to_string(i) + y;
        if (x_str.size() != 12) continue; // 如果不足12位，则不符合要求

        // 计算差值
        long long diff = stoll(x_str) - stoll(z);
        if (diff < 0) diff = -diff;

        // 更新答案
        ans = min(ans, diff);
    }

    cout << ans << endl;

    return 0;
}
