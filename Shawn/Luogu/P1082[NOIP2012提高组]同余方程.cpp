#include<bits/stdc++.h>
using namespace std;

long long x, y;//目前方程真正的解 

void exgcd(long long a, long long b)
{
	//当前目的：求解 ax + by = gcd(a, b) 这么一个方程
	
	if(b == 0) //a, b不断改变的过程中，b最终必然会成为0
	{
		//在 b = 0 时方程还要成立？ 使 x = 1, y = 0 ，必然成立 
		x = 1;
		y = 0; //建议返回0。不过y = 7能AC，证明了最后一个等式不受最后一个y影响
		return;
	} 
	
	exgcd(b, a % b);//把下一层系数传进去（先求下一个方程的解 ）
	
	//现在我们已经拿到了下一个方程的解x, y
	long long tx = x;//暂时存一下x，别丢了
	x = y;
	y = tx - a / b * y; 
}

int main()
{
	long long a, b;
	cin >> a >> b;
	exgcd(a, b);
    
	x = (x % b + b) % b;//我们求出来的x必然满足方程，但不一定是最小正整数解，所以要进行答案处理
	printf("%lld\n", x);
	return 0;
}