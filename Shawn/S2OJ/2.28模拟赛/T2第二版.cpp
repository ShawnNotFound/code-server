#include <bits/stdc++.h>
typedef long long ll;


using namespace std;

ll T, g, h;
ll R(ll a, ll b)
{
	if(a < b) swap(a, b);
	return b == 1 ? a : R(a / b, b);
}

void solve()
{
		cin >> g >> h;
		for(ll i = g; 1; i += g)
		{
			if(R(i * h + g, i) == h)
			{
				cout << i << " " << i * h + g << endl;
				break;
			}
		}
}

main()
{
	cin >> T;
	while(T --) solve();
	return 0;
}
