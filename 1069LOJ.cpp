#include<iostream>
#include<math.h>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int test,i;
    cin>>test;

    for(i=1;i<=test;i++)
    {
        int a,b;
        cin>>a>>b;
        int time=19+abs(a-b)*4+(a*4);
        printf("Case %d: %d\n",i,time);
    }
    return 0;
}
