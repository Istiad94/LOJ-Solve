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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    double ra,rb,rc;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%lf%lf%lf",&ra,&rb,&rc);

        double a = rb + rc;
        double b = ra + rc;
        double c = rb + ra;

        double A = acos(((b*b+c*c-a*a)/(2.0*b*c)));
        double B = acos(((c*c+a*a-b*b)/(2.0*a*c)));
        double C = acos(((b*b+a*a-c*c)/(2.0*a*b)));

        double s = (a+b+c)*0.5;
        double tri_area = sqrt(s*(s-a)*(s-b)*(s-c));
        double segment = 0.5*(ra*ra*A+rb*rb*B+rc*rc*C);
        double agent = tri_area - segment;

        printf("Case %d: %0.10lf\n",k,agent);
    }
    return 0;
}
