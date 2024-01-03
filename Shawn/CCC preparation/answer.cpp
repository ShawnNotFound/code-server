#include <iostream>

using namespace std;
typedef long long ll;
#define int long long

int a[10101];

signed main(){
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
	}
	for(int len = 1; len <= n; ++len){
		int l = 1, r = len;
		int cz = 1e15;
		while(r <= n){
			int L = l, R = r, nowcz = 0;
			while(L <= R){
				nowcz += abs(a[L] - a[R]);
				L++;
				R--;
			}
			++l;++r;
			cz = min(cz, nowcz);
		}
		printf("%lld ", cz);
	}
	return 0;
}