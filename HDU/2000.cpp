#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char a,b,c;
char x[4];
int main()
{
    int i;
    //freopen("2.in","r",stdin);
    while(scanf("%s",x))
    {
        a = min(min(x[0],x[1]),x[2]);
        c = max(max(x[0],x[1]),x[2]);
        for(i=0;i<3;i++){if(x[i]!=a&&x[i]!=c)b = x[i];}
        if(a=='\000')break;
        printf("%c %c %c\n",a,b,c);
        memset(x,0,sizeof(x));
    }

    return 0;
}