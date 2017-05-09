#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);

    int test, i;
    cin>>test;
    for(i=1;i<=test;i++)
    {
        string n;
        long long int d, x=0;
        cin>>n>>d;
        if(n[0]=='-')
            n.erase(n.begin());
        for(int j=0;j<n.size();j++)
        {
            x=x*10+n[j]-'0';
            x=x%d;
        }
        if(x==0)
            printf("Case %d: divisible\n", i);
        else
            printf("Case %d: not divisible\n", i);
    }
    return 0;
}
