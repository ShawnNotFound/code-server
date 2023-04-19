#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int a, b, x = 1, y = 1;

void exgcd(int a, int b, int& x, int& y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return;
	}

	exgcd(b, a % b, y, x);

	y -= a / b * x;
}

int main()
{	
	cin >> a >> b;

	exgcd(a, b, x, y);

	x = (x % b + b) % b;

	cout << x << endl;
}
