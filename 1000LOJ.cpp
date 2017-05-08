#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int test, i;
    cin>>test;

    for(i=1;i<=test;i++)
    {
        int a,b;
        cin>>a>>b;
        printf("Case %d: %d\n",i,a+b);
    }
    return 0;
}
