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
        double area,r;
        cin>>r;
        area=(4*r*r)-(2*acos(0.0)*r*r);
        printf("Case %d: %.2lf\n", i, area);
    }
    return 0;
}
