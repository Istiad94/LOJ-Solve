#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
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

int M;
int mods[] = {-1,10,100,1000,10000};

void multiply(int F[2][2], int F2[2][2])
{
  int x =  F[0][0]%M*F2[0][0]%M + F[0][1]%M*F2[1][0]%M;
  int y =  F[0][0]%M*F2[0][1]%M + F[0][1]%M*F2[1][1]%M;
  int z =  F[1][0]%M*F2[0][0]%M + F[1][1]%M*F2[1][0]%M;
  int w =  F[1][0]%M*F2[0][1]%M + F[1][1]%M*F2[1][1]%M;

  F[0][0] = x%M;
  F[0][1] = y%M;
  F[1][0] = z%M;
  F[1][1] = w%M;
}

void power(int p,int F[2][2])
{
    if(p==0||p==1)  return;
    int M[2][2] = {{1,1},{1,0}};
    power(p/2,F);
    multiply(F,F);
    if(p%2==1)  multiply(F,M);
}

int Fibonacci(int a,int b,int n,int m)
{
    M = mods[m];
    if(n==0)    return a%M;
    if(n==1)    return b%M;
    int F[2][2] = {{1,1},{1,0}};
    power(n-1,F);
    return (F[0][0]%M * b%M + F[0][1]%M * a%M)%M;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int a,b,n,m;
        scanf("%d%d%d%d",&a,&b,&n,&m);
        int ans = Fibonacci(a,b,n,m);
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
