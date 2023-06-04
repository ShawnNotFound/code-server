#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring> 
#include<vector>

typedef long long ll;

using namespace std;

ll a, b;
int g, h, k, t;
bool flag = false;

int r(ll x, ll y)
{
	if(b != 1) return r(x / y, y);
	else return x;
}

/*
1.直接在生成的时候就保证有g存在，只需要保证ka,kb没有公共因数即可 
*/


bool kcd(int ka, int kb)
{
	if(ka * a < g || kb * b < g) return false;
	for(int i = g + 1; i <= max(ka, kb); i ++)
	{
		if((ka % i == 0) && (kb % i == 0)) return false;
	}
	return true;
}

void init()
{
	flag = false;
	a = 1;
	b = 1;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i ++)
	{
		cin >> g >> h;
		init();
		for(int ka = g; ka <= 1e18; ka += g)
		{
			for(int kb = g; kb <= ka; kb += g)
			{
				if(k != 1)
				{
					if(!kcd(ka, kb)) 
						continue;
					else if(r(ka * a, kb * b) == h)
					{
						cout << ka * a << " " << kb * b << endl;
						flag = true;
						break;
					}
				}
				else 
				{
					cout << ka * a << " " << kb * b << endl;
					flag = true;
					break;
				}
					
			}
			if(flag)
				break;
		}
		if(!flag)
			cout << "impossible" << endl; 
	}
	return 0;
}
