#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};


int cost[20][3];
int DP[20][3];
int n;

int solve(int house_no,int color)
{
    if(house_no==n) return 0;
    if(DP[house_no][color]!=-1) return DP[house_no][color];

    int x;

    if(color==0)
    {
        x = solve(house_no+1,1);
        x = min(x,solve(house_no+1,2));
    }
    if(color==1)
    {
        x = solve(house_no+1,0);
        x = min(x,solve(house_no+1,2));
    }
    if(color==2)
    {
        x = solve(house_no+1,0);
        x = min(x,solve(house_no+1,1));
    }
    return DP[house_no][color] = x + cost[house_no][color];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;

    scanf("%d",&test);

    for(int i=1;i<=test;i++)
    {
        scanf("%d",&n);

        memset(DP,-1,sizeof(DP));

        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                scanf("%d",&cost[i][j]);

        int ans = solve(0,0);
        ans = min(ans,solve(0,1));
        ans = min(ans,solve(0,2));

        printf("Case %d: %d\n",i,ans);
    }

    return 0;
}
