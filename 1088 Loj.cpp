#include<bits/stdc++.h>
using namespace std;
#define all(n) n.begin(),n.end()

typedef long long ll;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cout<<setprecision(10)<<fixed;
    */
    int test,n,p,q,x,y;
    scanf("%d",&test);
    int v[100005];
    for(int kase = 1;kase<=test;kase++)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        sort(v,v+n);
        printf("Case %d:\n",kase);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            int ans = upper_bound(v,v+n,y)-lower_bound(v,v+n,x);
            printf("%d\n",ans);
        }
    }
    return 0;
}
