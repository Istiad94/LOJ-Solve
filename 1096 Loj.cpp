#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 10007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define D 4
#define new_matrix vector<vector<int> >(D,vector<int>(D,0))
#define matrix vector<vector<int> >

typedef long long ll;
typedef unsigned long long ull;

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

void multiply(int m1[4][4],int m2[4][4])
{
    int result[4][4];
    mem(result,0);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
            {
                result[i][j] += (m1[i][k]%MOD * m2[k][j]%MOD);
                result[i][j] %= MOD;
            }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            m1[i][j] = result[i][j];
}

void power(int p,int m[4][4],int a,int b)
{
    if(p<=1)    return;
    power(p/2,m,a,b);
    multiply(m,m);
    if(p&1)
    {
        int m2[4][4];
        mem(m2,0);
        m2[0][0] = a;
        m2[0][2] = b;
        m2[0][3] = m2[1][0] = m2[2][1] = m2[3][3] = 1;
        multiply(m,m2);
    }
}

int matrix_expo(int n,int a,int b,int c)
{
    if(n<=2)    return 0;
    int m[4][4];
    mem(m,0);
    m[0][0] = a;
    m[0][2] = b;
    m[0][3] = m[1][0] = m[2][1] = m[3][3] = 1;
    power(n-2,m,a,b);
    return (m[0][3]*c)%MOD;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,a,b,c;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d%d%d",&n,&a,&b,&c);
        printf("Case %d: %d\n",k,matrix_expo(n,a,b,c));
    }
    return 0;
}
