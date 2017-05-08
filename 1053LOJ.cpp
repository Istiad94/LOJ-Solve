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
        int j,a[3];
        for(j=0;j<3;j++)
            cin>>a[j];
        sort(a, a+3);
        if((a[2]*a[2])==(a[0]*a[0])+(a[1]*a[1]))
            printf("Case %d: yes\n", i);
        else
            printf("Case %d: no\n", i);
    }
    return 0;
}
