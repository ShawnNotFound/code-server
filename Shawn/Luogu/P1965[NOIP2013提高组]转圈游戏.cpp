#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int n, m, k, s;

int ksm(int a,int b)
{
	int res = 1;
	int t = a;
	while(b)
	{
		if(b & 1) 
        	res = res * t % n; 
		t = t * t % n;
		b >>= 1;
	}
	return res;
}

int main()
{
	cin >> n >> m >> k >>s;
    
    cout << ((s % n) + (m % n) * (ksm(10, k) % n)) % n << endl;
    return 0;
}