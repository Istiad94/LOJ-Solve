#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

vector<int>adj[30000],cost[30000];
int dist[30000];

int BFS1(int s,int n)
{
    for(int i=0;i<n;i++)
        dist[i]=-1;
    dist[s] = 0;
    int p = s;
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();

        if(dist[u]>dist[p])
            p = u;

        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(dist[v]==-1)
            {
                dist[v] = dist[u]+cost[u][i];
                q.push(v);
            }
        }
    }
    return p;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,n,u,v,w;
    cin>>t;

    for(int k=1;k<=t;k++)
    {
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int a = BFS1(0,n);
        int b = BFS1(a,n);
        printf("Case %d: %d\n",k,dist[b]);
        for(int i=0;i<n;i++)
        {
            dist[i] = -1;
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
