#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n;
int a,b;
char str[10000];
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        cin>>str;
        int len = strlen(str);
        bool flag = false;
        for(i=0;i<=(n>>1);i++)
            if(str[i] != str[len-1-i]){flag = 1;break;}
        if(flag)printf("no\n");
        else printf("yes\n");
        memset(str,0,sizeof(str));
    }
    return 0;
}