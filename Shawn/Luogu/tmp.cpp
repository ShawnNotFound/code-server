#include<map>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
map<vector<int> ,double> m;
vector<int> ve;
int fa[105],sz[105],all,n,mm,x,y;
int get(int x){
    return fa[x]==x?x:fa[x]=get(fa[x]);
}
double dp(vector<int> ve){
    if (m.count(ve)) return m[ve];
    if (ve.size()==1)
    {
        m[ve] = 0;
        return 0;
    } 
    int sz=ve.size(),p=0;

    for (int i=0;i<sz;i++)
        p+=ve[i]*(ve[i]-1)/2;

    double ans=1.0*all/(all-p);
    
    for (int i=1;i<sz;i++)
        for (int j=0;j<i;j++){
            vector<int> v=ve;
            v[j]+=v[i];
            swap(v[i],v[sz-1]);
            v.pop_back();
            sort(v.begin(),v.end());
            // ans+=1.0*ve[i]*ve[j]/(all-p)*dp(v);
            ans += (1.0 * ve[i] * ve[j]) / (1.0 * (all - p) * dp(v));
        }
    return m[ve]=ans;
}
int main(){
    scanf("%d%d",&n,&mm);

    for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    
    for (int i=1;i<=mm;i++){
        scanf("%d%d",&x,&y);
        x=get(x); y=get(y);
        if (x!=y) fa[x]=y,sz[y]+=sz[x];
    }
    for (int i=1;i<=n;i++)
        if (i==fa[i]) ve.push_back(sz[i]);
    sort(ve.begin(),ve.end());
    all=n*(n-1)/2;
    printf("%.6lf\n",dp(ve));
}
