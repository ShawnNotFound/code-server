#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 2e4 + 10;
const int M = 3e5+10;
int n, m;

int head[N], idx, in[N], out[N];
struct edge{
	int to,nxt;
}e[M];
void add(int i,int j)
{
	e[++idx].to=j;
	e[idx].nxt=head[i];
	head[i]=idx;
	out[i]++;
	in[j]++; 
} 
struct Edge{
	int u,v;
}E[M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		E[i]={u,v};
	}
	int cnt=1,cnt1=1;
	for(int i=1;i<=n;i++) cnt&=(in[i]<=1),cnt1&=(out[i]<=1);
	cout<<n+1<<endl;
	if(cnt){
		for(int i=1;i<=m;i++) cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].v<<endl;
		for(int i=1;i<=n;i++) if(!in[i]) cout<<n+1<<" "<<i<<" "<<i<<endl; 
	} else if(cnt1){
		for(int i=1;i<=m;i++) cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].u<<endl;
		for(int i=1;i<=n;i++) if(!out[i]) cout<<i<<" "<<n+1<<" "<<i<<endl;
	}
	 
	return 0;
}


