#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int d, n, ans;

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> d >> n;
    // if(d == 0)
    //     cout << n << endl;
    // else if (d == 1)
    //     cout << n << "00" << endl;
    // else if(d == 2)
    //     cout << n << "0000" << endl;

    ans = pow(100, d) * n;

	if(n == 100)
		ans += pow(100, d);

    cout << ans << endl;

    return 0; 
}
