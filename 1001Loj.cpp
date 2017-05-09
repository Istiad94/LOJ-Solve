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
        int a, n;
        cin>>n;
        a=n/2;
        if(n%2==0)
            printf("%d %d\n",a,a);
        else
            printf("%d %d\n",a,a+1);
    }
    return 0;
}
