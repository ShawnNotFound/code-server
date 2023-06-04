//test
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ver[600400],head[300400],nxt[600400],cnt;
void addedge(int ui,int vi){
    ++cnt;
    ver[cnt]=vi;
    nxt[cnt]=head[ui];
    head[ui]=cnt;
}
int record[300400][20],dpt[300400];
void dfs(int u,int f){
    record[u][0]=f;
    dpt[u]=dpt[f]+1;
    for(int i=1;i<20;i++)
        record[u][i]=record[record[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i]){
        if(ver[i]==f)
            continue;
        dfs(ver[i],u);
    }
}
int lca(int x,int y){
    if(dpt[x]<dpt[y])
        swap(x,y);
    for(int i=19;i>=0;i--)
        if(dpt[record[x][i]]>=dpt[y])
            x=record[x][i];
    if(x==y)
        return x;
    for(int i=19;i>=0;i--)
        if(record[x][i]!=record[y][i])
            x=record[x][i],y=record[y][i];
    return record[x][0];
}
const int MOD = 1000000007;
int qpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)
            ans=(1LL*ans*a)%MOD;
        a=(1LL*a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int fa[600400],n,m;
int get_father(int x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=get_father(fa[x]);
}
void merge(int x,int Lca){
    while(dpt[record[x][0]]>dpt[Lca]){
        int f=record[x][0];
        fa[get_father(x)]=get_father(f);
        fa[get_father(x+n)]=get_father(f+n);
        x=get_father(f);
    }   
}
int ta[300300],tb[300300],Lca[300300];
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=2*n;i++)
        fa[i]=i;
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&ta[i],&tb[i]);
        Lca[i]=lca(ta[i],tb[i]);
        merge(ta[i],Lca[i]);
        merge(tb[i],Lca[i]);
    }
    for(int i=1;i<=m;i++){
        if(Lca[i]!=ta[i]&&Lca[i]!=tb[i]){
            fa[get_father(ta[i]+n)]=get_father(tb[i]);
            fa[get_father(tb[i]+n)]=get_father(ta[i]);
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        if(get_father(i)==get_father(i+n)){
            printf("0\n");
            return 0;
        }
        ans+=(get_father(i)==i);
        ans+=(get_father(i+n)==(i+n));
    }
    printf("%d\n",qpow(2,ans/2));
    return 0;
}