#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int m,l;
long long n,d[10000];
int main()
{
    scanf("%lld",&n);
    for (int i=1;i<=(int)sqrt((double)n);i++)
        if (n%i==0)
        {
            if (i%2!=0&&i!=1)
                d[++l]=i;
            if ((n/i)%2!=0&&(n/i)!=1)
                d[++l]=n/i;
        }
    printf("%d ", l);
    sort(d+1,d+l+1);
    for (int i=1;i<=l;i++)
    {
        long long r=n/d[i];
        r=r*(d[i]-1);
        printf("%lld ",r);
     }
}

/*
对于这道题，我们可以现将路况进行处理，然后问题变为从s到t最大最小路程是什么
几乎和[HAOI2006]旅行一样了，我们可以通过枚举最小边，求出最大边，但分析复杂度发现是O(m^2),会t掉
我们换一种思路，对道路进行二分，即通过二分枚举最小道路，从而求出最长道路，这样复杂度就是O(mlog（m）)
*/