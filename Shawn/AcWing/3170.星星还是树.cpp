#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<iomanip>

#define x first
#define y second

const int INF = 1e8;
const int N = 110;

using namespace std;

typedef pair<double, double> PDD;

int n;
double ans = INF;
PDD p[N];

double get_rand(double l, double r)
{
    return (double)rand() / RAND_MAX * (r - l) + l;
}

double get_dist(PDD a, PDD b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double calc(PDD a)
{
    double res = 0;
    for(int i = 1; i <= n; i ++)
    {
        res += get_dist(a, p[i]);
    }
    ans = min(ans, res);

    return res;
}

void simulate_anneal()
{
    PDD cur(get_rand(0, 10000), get_rand(0, 10000));

    for(double t = 10000; t > 1e-4; t *= 0.99)
    {
        PDD np(get_rand(cur.x - t, cur.x + t), get_rand(cur.y - t, cur.y + t));
        double dx = calc(np) - calc(cur);
        if(exp(-dx / t) > get_rand(0, 1))   
            cur = np;
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> p[i].x >> p[i].y;
    }
    for(int i = 1; i <= 100; i ++)
        simulate_anneal();
    
    cout << fixed << setprecision(0) << ans << endl;

    return 0;
}