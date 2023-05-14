#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int num[12];
ll l,r,dp[11][11][11][2][2][2][2];

ll f(int p,int a,int b,bool c,bool d,bool _4,bool _8){
    /*
        a:p+1位是多少
        b:p+2位是多少,若是前导0的话是-1
        c:之前是否已经出现连续三个相同的数字
        d:之前是否已经保证x<n
        _4:是否出现过4
        _8:是否出现过8
    */
    if(_4&&_8) return 0;//又有4又有8 不合法 
    if(p<=0) return c;
	//这里是个偷懒,如果当前出现过连续三个相同的数字返回1，否则返回0 
    if (~dp[p][a][b][c][d][_4][_8]) return dp[p][a][b][c][d][_4][_8];//记忆化 
    ll res=0;int lim=!d?num[p]:9;//如果没有严格小于,只能填到num,如果已经严格小于,就可以随便填 
  	for(int i=0;i<=lim;i++)
        res+=f(p-1,i,a,c||(i==b&&i==a),d||(i<lim),_4||(i==4),_8||(i==8));
        //下一位,
		//下一位的上一位(就是这一位),
		//下一位的上上位(就是现在的上一位),
		//以前就出现过||这次填数刚造出来的, 
    return dp[p][a][b][c][d][_4][_8]=res;
}

ll calc(ll x){
    if(x<1e10) return 0;//不是手机号 
    memset(dp,-1,sizeof(dp));
    //拆位 
    int len;
    for(len=0;x;x/=10) num[++len]=x%10;
    //第一位还要考虑前导0,不如直接手算 
	ll res=0;
	for(int i=1;i<=num[len];i++)
    res+=f(10,i,0,0,i<num[len],i==4,i==8);
	return res;
}

int main(){
    cin>>l>>r;
    cout<<calc(r)-calc(l-1);
}