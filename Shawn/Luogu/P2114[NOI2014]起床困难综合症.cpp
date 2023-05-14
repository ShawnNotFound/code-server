#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

char opt[5];
int n, m, t, ans;
int x = 0, y = -1;

int main()
{
    cin >> n >> m;

    while(n --)
    {
        cin >> opt + 1 >> t;
        if(opt[1] == 'A')
            x &= t, y &= t;
        if(opt[1] == 'O')
            x |= t, y |= t;
        if(opt[1] == 'X')   
            x ^= t, y ^= t;
    }

    for(int i = 29; ~i; --i)
    {
        if(x >> i & 1)
            ans += 1 << i;
        else if(y >> i & 1 && (1 << i) <= m)
            ans += 1 << i, m -= 1 << i;
    }

    cout << ans << endl;

    return 0;
}
// #include<bits/stdc++.h>
// int n,m,ans,x,a1=0,a2=-1;
// char str[5];
// int main(){
// 	scanf("%d%d",&n,&m);
// 	while(n--){
// 		scanf("%s%d",str,&x);
// 		if(str[0]=='A') a1&=x, a2&=x;
// 		if(str[0]=='X') a1^=x, a2^=x;
// 		if(str[0]=='O') a1|=x, a2|=x;
// 	}
// 	for(int j=29;~j;--j){
// 		if(a1>>j&1) ans+=1<<j;
// 		else if(a2>>j&1&&(1<<j)<=m) ans+=1<<j, m-=1<<j;
// 	} printf("%d",ans);
// 	return 0;
// }