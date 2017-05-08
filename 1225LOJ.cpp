#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int test,i;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        char n[15];
        scanf("%s",n);
        int a, j, flag=0;
        int len = strlen(n)-1,limit=strlen(n)/2;
        for(a=0,j=len;a<=limit;a++,j--)
            if(n[a]!=n[j])
            {
                flag=1;
                break;
            }
        if(flag==0)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
    }
    return 0;
}

