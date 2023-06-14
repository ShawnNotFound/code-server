#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

queue < int > Q; // 标失配结点编号所需的队列 

struct Node{
    int t[2] , f; // t 数组为下个二进制位结点编号，f 为失配结点编号
    bool c; // c 变量为该结点是否为危险代码段的最后一位 
}; // 定义字典树结点结构体
struct AcAutomaton{
    Node N[30001]; // 字典树的结点
    int S = 0; // 字典树的当前非根节点总数
    inline void Insert(char c[] , int l){ 
        int nd = 0; // 定义当前点，当然从根节点 0 开始
        for(int i = 0 ; i < l ; i++)
            if(N[nd].t[c[i] - 48] == 0)
                N[nd].t[c[i] - 48] = ++S , nd = S; // 没有目标节点，新建个
            else
                nd = N[nd].t[c[i] - 48]; // 有目标节点，直接转移当前点
        N[nd].c = true; // 标上病毒段末尾的危险标记      
    } // 函数：向字典树内插入长度为 l 的病毒串 
    inline void PutFail(){
        if(N[0].t[0] > 0)
            Q.push(N[0].t[0]); // 根节点有没有 0 儿子，如果有推入队列
        if(N[0].t[1] > 0)
            Q.push(N[0].t[1]); // 根节点有没有 1 儿子，如果有推入队列
        while(!Q.empty()){
            int nd = Q.front() ; Q.pop(); // 得到队列首
            for(int i = 0 ; i <= 1 ; i++)
                if(N[nd].t[i] > 0){
                    Q.push(N[nd].t[i]);
                    int td = N[nd].f;
                    while(td > 0 && N[td].t[i] <= 0)
                        td = N[td].f; // 要不到根节点，要不找到最长匹配后缀段
                    if(N[td].t[i] <= 0)
                        N[N[nd].t[i]].f = 0; // 失配指针转移到根节点 
                    else{
                        N[N[nd].t[i]].f = N[td].t[i];
                        if(N[N[td].t[i]].c)
                            N[N[nd].t[i]].c = true;
                        // 既然自己后缀都行不通，自己也危险 
                    }
                }else
                    N[nd].t[i] = N[N[nd].f].t[i]; 
        } 
    } // 函数：设置失配指针 
}; // 定义 AC 自动机结构体 

AcAutomaton A; // 新建 AC 自动机 
bool v[30001]; // v 为结点是否是当前搜索路径上的一点
bool f[30001]; // f 为结点是否是否被现在或过往搜索过 
char c[30001];
int n;

void Dfs(int d){ // 通过搜索寻找有没有环 
    v[d] = true; // 作下路径标记 
    for(int i = 0 ; i <= 1 ; i++) 
        if(v[A.N[d].t[i]]){ // 根据路径标记判断是否拥有环
            printf("TAK");
            exit(0); // 找到了环，输出并退出程序 
        }else if(!A.N[A.N[d].t[i]].c && !f[A.N[d].t[i]]){
            // 只有下一位不为危险结点并且有可能成环，才递归搜索
            f[A.N[d].t[i]] = true; // 下一个结点已经被搜索过了 
            Dfs(A.N[d].t[i]); 
        }
    v[d] = false; // 抹除路径标记 
}

int main(){
    scanf("%d" , &n); // 输入病毒串数量（这个不用我打注释了吧……） 
    for(int i = 1 ; i <= n ; i++)
        scanf("%s" , c) , A.Insert(c , strlen(c)); // 输入并插入病毒串;
    A.PutFail(); // 设置每个结点的失配指针
    Dfs(0); // 从字典树的根结点开始找环 
    printf("NIE"); // 既然程序没有退出，就输出无解 
    return 0;
}