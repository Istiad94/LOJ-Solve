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
#define pq_min priority_queue< int, vector<int>, greater<int> >

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

int row,col;
string grid[500];
int gems[500][500];
vector<pii>cord;

bool inBound(int i,int j)
{
    return(i>=0&&i<row&&j>=0&&j<col);
}

void BFS(int x,int y)
{
    cord.clear();
    cord.push_back(pii(x,y));
    int crystal = 0;
    if(grid[x][y]=='C') crystal++;
    queue<pii>q;
    q.push(pii(x,y));
    grid[x][y] = '#';
    while(q.size())
    {
        int ux = q.front().ff;
        int uy = q.front().ss;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if(inBound(vx,vy)&&grid[vx][vy]!='#')
            {
                if(grid[vx][vy]=='C')
                    crystal++;
                cord.push_back(pii(vx,vy));
                grid[vx][vy] = '#';
                q.push(pii(vx,vy));
            }
        }
    }
    for(int i=0;i<cord.size();i++)
    {
        int x = cord[i].ff;
        int y = cord[i].ss;
        gems[x][y] = crystal;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int test,q;

    scanf("%d",&test);

    for(int k=1;k<=test;k++)
    {
        scanf("%d%d%d",&row,&col,&q);
        for(int i=0;i<row;i++)
        {
            cin>>grid[i];
            mem(gems[i],0);
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]!='#')
                    BFS(i,j);

        printf("Case %d:\n",k);

        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            printf("%d\n",gems[x][y]);
        }
    }
    return 0;
}
