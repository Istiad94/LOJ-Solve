#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
    int test, a, i;
    scanf("%d\n", &test);
    for(a=1;a<=test;a++)
    {
        char str1[101],str2[101];
        int s1=0, s2=0;

        gets(str1);
        gets(str2);

        for(i=0;str1[i]!='\0';i++)
            if(isalpha(str1[i]))
                s1+=tolower(str1[i]);

        for(i=0;str2[i]!='\0';i++)
            if(isalpha(str2[i]))
                s2+=tolower(str2[i]);

        if(s1==s2)
            printf("Case %d: Yes\n",a);
        else
            printf("Case %d: No\n",a);

    }
    return 0;
}
