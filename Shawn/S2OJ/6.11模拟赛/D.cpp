#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

char map[705][705];
int book[705][705];
int flag[705][705];
int n,m;
int yx,yy,vx,vy,tx,ty;

struct sair
{
    int x, y, step;
}

struct Step
{
    int x, y;
    int step, num;
    int dir;
}

struct Step{
    int x,y,step,num,dir;
};

int dir[4][2]={0,1,0,-1,1,0,-1,0};
sair Q[1000005];
int Qs,Qe;

void push(sair a)
{
    Q[Qe++]=a;
}

void pop()
{
    ++Qs;
}

sair Front(){
    return Q[Qs+1];
}

void bfsV(){
    sair s,e;
    s.x = vx;
    s.y = vy;
    s.step = 0;
    memset(book,-1,sizeof(book));
    push(s);
    flag[s.x][s.y] = 1;
    book[s.x][s.y] = 0;
    while(Qs != Qe)
    {
        s=Front();
        pop();
        int co=1;
        int tmp=s.y+co;
        while(tmp<m&&map[s.x][tmp]!='I'){
            if(book[s.x][tmp]==-1){
                book[s.x][tmp]=s.step;
            }
            co++;
            tmp=s.y+co;
        }
        co=-1;
        tmp=s.y+co;
        while(tmp>=0&&map[s.x][tmp]!='I'){
            if(book[s.x][tmp]==-1){
                book[s.x][tmp]=s.step;
            }
            co--;
            tmp=s.y+co;
        }
        co=1;
        tmp=s.x+co;
        while(tmp<n&&map[tmp][s.y]!='I'){
            if(book[tmp][s.y]==-1){
                book[tmp][s.y]=s.step;
            }
            co++;
            tmp=s.x+co;
        }
        co=-1;
        tmp=s.x+co;
        while(tmp>=0&&map[tmp][s.y]!='I'){
            if(book[tmp][s.y]==-1){
                book[tmp][s.y]=s.step;
            }
            co--;
            tmp=s.x+co;
        }
        for(int i=0;i<4;i++){
            e.x=s.x+dir[i][0];
            e.y=s.y+dir[i][1];
            if(e.x>=0&&e.x<n&&e.y>=0&&e.y<m&&map[e.x][e.y]!='I'&&!flag[e.x][e.y]){
                flag[e.x][e.y]=1;
                e.step=s.step+1;
                push(e);
            }
        }
    }
}

void bfsY()
{
    sair s,e;
    queue<sair> Q;
    s.x = yx;
    s.y = yy;
    s.step = 1;
    Q.push(s);

    memset(flag,0,sizeof(flag));
    
    while(Q.size())
    {



        s = Q.front();
        Q.pop();

        for(int i=0;i<4;i++)
        {
            e.x = s.x + dir[i][0];
            e.y = s.y + dir[i][1];

            if(e.x>=0&&e.y<n&&e.y>=0&&e.y<m&&s.step<book[e.x][e.y]&&!flag[e.x][e.y])
            {
                e.step=s.step+1;
                flag[e.x][e.y]=1;
                if(e.x==tx&&e.y==ty)
                {
                    puts("YES");
                    return;
                }
                Q.push(e);
            }
        }
    }
    puts("NO");
}

int main()
{
    cin >> n >> m;

    Qs=0,Qe=1;
    
    for(int i=0;i<n;i++)
        cin >> map[i];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(map[i][j]=='Y')
            {
                yx=i;
                yy=j;
            }
            else if(map[i][j]=='V')
            {
                vx=i;
                vy=j;
            }
            else if(map[i][j]=='T')
            {
                tx=i;
                ty=j;
            }
        }
    }

    bfsV();

    bfsY();
}
