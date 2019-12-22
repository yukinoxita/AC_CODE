#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char str[102];
bool vis[102];
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(cin>>str)//while(scanf("%s",str)!=EOF)   same!!!
    {
        int sit = 0;
        char maxx = 'A';        
        for(i=0;i<strlen(str);i++){if(maxx<str[i]){maxx = str[i];sit = i;}}
        for(i=0;i<strlen(str);i++)
        {
            printf("%c",str[i]);
            if(str[i] == maxx)printf("(max)");
        }
        printf("\n");
        memset(str,0,sizeof(str));
        memset(vis,0,sizeof(vis));
    }

}