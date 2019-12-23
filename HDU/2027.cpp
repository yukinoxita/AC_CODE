#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char str[102];
int vis[5];
int n;
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    scanf("%d",&n);
    getchar();//2后面有个'\n'所以我们要用它把换行符去掉
    while(n--)
    {
        memset(vis,0,sizeof(vis));
        memset(vis,0,sizeof(vis));
        cin.getline(str,100);
        for(i=0;i<strlen(str);i++)
        {

            if(str[i] == 'a')vis[0]++;
            if(str[i] == 'e')vis[1]++;
            if(str[i] == 'i')vis[2]++;
            if(str[i] == 'o')vis[3]++;
            if(str[i] == 'u')vis[4]++;
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",vis[0],vis[1],vis[2],vis[3],vis[4]);
        if(n)
        printf("\n");
    }
    return 0;
}