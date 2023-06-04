// luogu-judger-enable-o2
#include<bits/stdc++.h> 
using namespace std;
inline int read(){//读入优化 
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int maxn=100010;//n的最大值 
int n,m,L[maxn],R[maxn],key[maxn],npl[maxn],fa[maxn];
//L为左子树编号，R为右子树编号，key为能力值，npl请见上面，fa为并查集数组 
inline int getf(int o) { 
    return o==fa[o] ? o : fa[o]=getf(fa[o]);
    //路径压缩更快 
}
inline int join(int a,int b) {
	//合并函数 
    if (!a) return b;//判断是否为空 
    if (!b) return a;
    if (key[a]<key[b]) swap(a,b);//维护堆性质 
    R[a]=join(R[a],b);//将b合并到a的右子树 
    if (npl[R[a]]>npl[L[a]]) swap(L[a],R[a]);
	//维护左偏树性质，npl[r]<=npl[l] 
    npl[a]=npl[R[a]]+1;//获得npl值 
    return a;//返回新根编号 
}
inline void work(int a,int b) {
    a=getf(a);b=getf(b);//找根 
    if (a==b) {//已经是朋友 
        puts("-1");
        //不打了 
        return;
    }
    int rt,art,brt;
    //a所属的左偏树的操作 
    key[a]>>=1;//减半 
    rt=join(L[a],R[a]);//合并左右子树 
    L[a]=R[a]=npl[a]=0;//将根节点断掉 
    art=join(rt,a);//重新合并旧根
    fa[rt]=fa[a]=art; 
    //为了路径压缩，要将旧根和子树合并的根都指向新根 
    key[b]>>=1;
    rt=join(L[b],R[b]);
    fa[L[b]]=fa[R[b]]=rt;
    L[b]=R[b]=npl[b]=0;
    brt=join(rt,b);
    fa[rt]=fa[b]=brt;
    //同a的操作 
    rt=join(art,brt);//合并两棵左偏树 
    fa[art]=fa[brt]=rt;
    //将两个旧根指向新根 
    printf("%d\n",key[rt]);
}
int main(){
    while (~scanf("%d",&n)) {//多组数据 
        npl[0]=-1;//特殊处理 
        for (register int i=1;i<=n;++i) {
        	//初始化 
            L[i]=R[i]=npl[i]=0;
            fa[i]=i;
            key[i]=read();
        }
        m=read();
        for (register int i=1;i<=m;++i) 
            work(read(),read());//猴子打架 
    }
}
