#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 1000005
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define ff first
#define ss second
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

class node
{
public:
    int x,y,d;
    node(int a,int b,int c)
    {
        x = a,y = b, d = c;
    }
    bool operator < (const node &o) const
    {
        return d > o.d;
    }
};

typedef long long ll;
typedef unsigned long long ull;

enum COLOR { W = 0, G = 1, B = 2};

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

/*
int lp[32001];
vector<int>prime;

void sieve(int limit = 32001)
{
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}
*/

int r,c;
int level[20][20];
bool visit[20][20];
string g[20];

bool inBound(int i,int j)
{
    return (i>=0&&i<r&&j>=0&&j<c&&g[i][j]!='m'&&g[i][j]!='#'&&visit[i][j]==false);
}

void BFS(int x,int y)
{
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            level[i][j] = INF,visit[i][j] = false;

    priority_queue<node>pq;
    pq.push(node(x,y,0));
    level[x][y] = 0;
    visit[x][y] = true;
    int a,b,c;
    while(pq.size())
    {
        int ux = pq.top().x;
        int uy = pq.top().y;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if(inBound(vx,vy))
            {
                level[vx][vy] = min(level[vx][vy],level[ux][uy]+1);
                if(g[vx][vy]=='a')
                    a = level[vx][vy];
                else if(g[vx][vy]=='b')
                    b = level[vx][vy];
                else if(g[vx][vy]=='c')
                    c = level[vx][vy];
                visit[vx][vy] = true;
                pq.push(node(vx,vy,level[vx][vy]));
            }
        }
    }
    printf("%d\n",max(a,max(b,c)));
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++)
            cin>>g[i];
        printf("Case %d: ",k);
        for(int i=0;i<r;i++)    for(int j=0;j<c;j++)    if(g[i][j]=='h')    BFS(i,j);
    }
    return 0;
}

