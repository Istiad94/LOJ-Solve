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

int block;

class query
{
public:
    int indx,left,right;
    query(int i,int l,int r)
    {
        indx = i;
        left = l;
        right = r;
    }
    bool operator < (const query &other)    const
    {
        if(left/block == (other.left / block))
            return right < other.right;
        return left / block < other.left / block;
    }

};

int A[100005];
int F[100005];
int R[100005];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q,l,r,t;
    vector<query>Q;

    scanf("%d",&t);

    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&n,&q);

        block = sqrt(n);

        for(int i=0;i<n;i++)
            scanf("%d",&A[i]);

        mem(F,0);
        Q.clear();

        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&l,&r);
            Q.push_back(query(i,l-1,r-1));
        }

        sort(all(Q));

        int s = Q[0].left;
        int e = Q[0].left;
        int ans = 1;
        F[A[s]]++; // Major Point

        for(int i=0;i<q;i++)
        {
            while(s < Q[i].left)
            {
                F[A[s]]--;
                if(F[A[s]]==0)
                    ans--;
                s++;
            }
            while(s > Q[i].left)
            {
                s--;
                F[A[s]]++;
                if(F[A[s]]==1)
                    ans++;
            }
            while(e < Q[i].right)
            {
                e++;
                F[A[e]]++;
                if(F[A[e]]==1)
                    ans++;
            }
            while(e > Q[i].right)
            {
                F[A[e]]--;
                if(F[A[e]]==0)
                    ans--;
                e--;
            }
            R[Q[i].indx] = ans;
        }
        printf("Case %d:\n",k);
        for(int i=0;i<q;i++)
            printf("%d\n",R[i]);
    }
    return 0;
}
