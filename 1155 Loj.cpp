#include<bits/stdc++.h>
#define mem(n,v) memset(n,v,sizeof(n))

using namespace std;

int capacity[205][205];
int parent[205];
bool visit[205];
int node,edge;

bool isPath(int s,int d)
{
    mem(visit,false);
    mem(parent,-1);
    visit[s] = true;
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int v=0;v<=(node*2+1);v++)
        {
            if(!visit[v]&&capacity[u][v])
            {
                visit[v]  = true;
                parent[v] = u;
                q.push(v);
                if(v==d)    return true;
            }
        }
    }
    return false;
}

int fordFulkerson(int source,int sink)
{
    int maxFlow = 0;
    while(isPath(source,sink))
    {
        int u,v=sink,min_res_cap = INT_MAX;
        while(parent[v]!=-1)
        {
            u = parent[v];
            min_res_cap = min(min_res_cap,capacity[u][v]);
            v = u;
        }
        v = sink;
        while(parent[v]!=-1)
        {
            u = parent[v];
            capacity[u][v]-=min_res_cap;
            capacity[v][u]+=min_res_cap;
            v = u;
        }
        maxFlow += min_res_cap;
    }
    return maxFlow;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,b,d,c,u,v;
    cin>>test;
    for(int kase=1;kase<=test;kase++)
    {
        cin>>node;
        mem(capacity,0);
        for(int i=1;i<=node;i++)
            cin>>capacity[i*2-1][i*2];
        cin>>edge;
        while(edge--)
        {
            cin>>u>>v>>c;
            u*=2,v*=2;
            capacity[u][--v]=c;
        }
        cin>>b>>d;
        while(b--)
        {
            cin>>u;
            capacity[0][u*2-1]=9999;
        }
        while(d--)
        {
            cin>>u;
            capacity[u*2][node*2+1]=9999;
        }
        cout<<"Case "<<kase<<": "<<fordFulkerson(0,node*2+1)<<endl;
    }
    return 0;

}
