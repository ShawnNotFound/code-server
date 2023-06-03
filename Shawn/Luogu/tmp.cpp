/*
Work by : Dreamcatcher
Time : O(能过)
*/
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int INF=0x7fffffff;
const int Mod=114514;
const int N=1e6+7;

int read() {
	int x=0,f=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
    for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch&15);
	return f?-x:x;
}

void print(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
    putchar(x%10+48);
}

int Ans,q[N],a[N],n,up[N],far[N],k;

signed main() {
   n=read();k=read();
   for(int i=1;i<=n;i++) a[i]=read();
   int head=0,tail=0;
   for(int i=1;i<k;i++){
       while(head<=tail&&a[q[tail]]>=a[i]) --tail;
       q[++tail]=i;
   }
   for(int i=k;i<=n;i++){
       while(head<=tail&&a[q[tail]]>=a[i]) --tail;
       q[++tail]=i;
       while(head<=tail&&q[head]<i-k+1) ++head;
       up[i-k+1]=a[q[head]];
   }
   head=0;tail=0;
   for(int i=1;i<=n;i++){
       while(head<=tail&&up[q[tail]]<=up[i]) --tail;
       q[++tail]=i;
       if(i>=k) while(head<=tail&&q[head]<i-k+1) head++;
       far[i]=up[q[head]];
       Ans+=(a[i]-far[i]);
   }
   print(Ans);putchar('\n');Ans=0;
   int Up=0,right=0;
   for(int i=1;i<=n;i++){
       if(far[i]^Up||right<i){
           Ans++;Up=far[i];right=i+k-1;
       }
   }print(Ans);
   return 0;
}



