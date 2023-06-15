#include<cstdio>
#include<cstring>
using namespace std; 

struct Monotone_queue
{
    static const int maxn=1000001;
    int n,k,a[maxn];
    int q[maxn],head,tail,p[maxn];//同题目叙述一样，q是单调队列，p是对应编号。
    
    void read()
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
    }//读入不必说了
    
    void monotone_max()//单调最大值
    {
        head=1;
        tail=0;
        for(int i=1;i<=n;++i)
        {
            while(head<=tail&&q[tail]<=a[i])
                tail--;
            q[++tail]=a[i];
            p[tail]=i;
            while(p[head]<=i-k)
                head++;
            if(i>=k)printf("%d ",q[head]);
        }
        printf("\n");
    }
    
    void monotone_min()
    {
        head=1;
        tail=0;//为啥要这样呢?因为head要严格对应首元素，tail要严格对应尾元素，所以当tail>=head时，说明有元素。而一开始队列为空，说一要这样赋值。其实这跟普通队列一样。
        for(int i=1;i<=n;++i)
        {//a[i]表示当前要处理的值
            while(head<=tail&&q[tail]>=a[i])
                tail--;//只要队列里有元素，并且尾元素比待处理值大，即表示尾元素已经不可能出场，所以出队。直到尾元素小于待处理值，满足"单调"。
            q[++tail]=a[i];//待处理值入队。
            p[tail]=i;//同时存下其编号
            while(p[head]<=i-k)
                head++;//如果队首元素已经"过时"，出队。
            if(i>=k)printf("%d ",q[head]);//输出最值，即队首元素。i>=k表示该输出，至于why就自己看题目。
        }
        printf("\n");
        
    }
}worker;

int main()
{
    worker.read();
    worker.monotone_min();
    worker.monotone_max();
    return 0;
}