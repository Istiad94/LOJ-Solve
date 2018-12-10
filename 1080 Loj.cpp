#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct info
{
    ll prop, sum;
} tree[300001];

int ara[100001];

void build(int n,int b,int e)
{
    if(b==e)
    {
        tree[n].sum = ara[b];
        return;
    }

    int mid = (b+e)/2, left = 2*n, right = left+1;

    build(left,b,mid);
    build(right,1+mid,e);

    tree[n].sum = tree[left].sum+tree[right].sum;
}

void update(int node, int b, int e, int i, int j, ll x)
{
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

char bits[100005];

int  main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;
    scanf("%d",&test);
    for(int k=1;k<=test;k++)
    {
        int n,q,x,y;

        for(int i=1;i<=300001;i++)
            tree[i].sum = tree[i].prop = 0;

        scanf("%s",bits);
        n = strlen(bits);

        for(int i=0;i<n;++i)
            ara[i+1] = bits[i]-48;

        build(1,1,n);
        char ch[5];

        printf("Case %d:\n",k);
        scanf("%d",&q);

        while(q--)
        {
            scanf("%s",ch);
            if(ch[0]=='I')
            {
                scanf("%d%d",&x,&y);
                update(1,1,n,x,y,1);
            }
            else
            {
                scanf("%d",&x);
                printf("%d\n",query(1,1,n,x,x)%2);
            }
        }

    }
    return 0;
}
