#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);

    int test;
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        int sum=0, n, v;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>v;
            if(v>=0)
            sum+=v;
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}

