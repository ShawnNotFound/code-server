#include<bits/stdc++.h>
#define LL long long
#define N 100005
using namespace std;

struct Player{
	int fa,cost,lead;
}R[N<<2];

int n,m;
LL ans;
int size[N],root[N],dis[N],ls[N],rs[N];
LL sum[N];
void BuildHeap(int now){
	size[now]=1;
	root[now]=now;
	sum[now]=R[now].cost;
}
int Merge(int A,int B){
	if(!A||!B) return A+B;
	if(R[A].cost<R[B].cost) swap(A,B);
	rs[A]=Merge(rs[A],B);
	if(dis[ls[A]]<dis[rs[A]]) swap(ls[A],rs[A]);
	dis[A]=dis[rs[A]]+1;
	return A;
}
int main(){
	//freopen("Master.in","r",stdin);
	//freopen("Master.out","w",stdout);
	n=gi();m=gi();
	for(int i=1,b,c,l;i<=n;i++){
		b=gi();c=gi();l=gi();
		R[i]=(Player){b,c,l};
		ans=max((LL)(R[i].lead),ans);
		BuildHeap(i);    //每个忍者看成一个单独的堆
	}
	for(int i=n;i>1;i--){
		int fa=R[i].fa;          //当前的忍者看作为领导,对每个点都进行枚举
		root[fa]=Merge(root[i],root[R[i].fa]);      //合并当前节点和本身的父亲节点
		size[fa]+=size[i];sum[fa]+=sum[i];        //把当前的元素加到父亲数size和sum都想应改变
		while(sum[fa]>m){
			sum[fa]-=R[root[fa]].cost;      //如果超过了删除堆顶元素
			root[fa]=Merge(ls[root[fa]],rs[root[fa]]);     
			size[fa]--;    //更新size
		}
		ans=max(ans,(LL)(R[fa].lead)*(LL)(size[fa]));   //取max的ans
	}
	cout<<ans<<endl;
	return 0;
}

