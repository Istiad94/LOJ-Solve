#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dist1[30000];
int dist2[30000];
vector<int>adj[30000],cost[30000];

int BFS1(int s,int n)
{
    for(int i=0;i<n;i++)
        dist1[i] = -1;
    queue<int>q;
    q.push(s);
    dist1[s] = 0;
    int p = s;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        if(dist1[u]>dist1[p])
            p = u;
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int c = cost[u][i];
            if(dist1[v]==-1)
            {
                dist1[v] = dist1[u] + c;
                q.push(v);
            }
        }
    }
    return p;
}

int BFS2(int s,int n)
{
    for(int i=0;i<n;i++)
        dist2[i] = -1;
    queue<int>q;
    q.push(s);
    dist2[s] = 0;
    int p = s;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        if(dist2[u]>dist2[p])
            p = u;
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int c = cost[u][i];
            if(dist2[v]==-1)
            {
                dist2[v] = dist2[u] + c;
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

    int test,n,u,v,w;
    cin>>test;

    for(int k=1;k<=test;k++)
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

        int p1 = BFS1(0,n);
        int p2 = BFS2(p1,n);
        BFS1(p2,n);

        printf("Case %d:\n",k);

        for(int i=0;i<n;i++)
        {
            printf("%d\n",max(dist1[i],dist2[i]));
            adj[i].clear();
            cost[i].clear();
            dist1[i] = dist2[i] = -1;
        }

    }
    return 0;
}
