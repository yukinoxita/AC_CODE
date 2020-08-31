#include <cstdio>
#include <cstring>
char str[1024];
int cnt[5];//p k h t
bool vis[5][14];
int main()
{
    register int i;
    scanf("%s",str);
    int sit;
    for(i=0;i<strlen(str);i+=3)
    {
        if(str[i] == 'P')sit = 1;
        else if(str[i] == 'K')sit = 2;
        else if(str[i] == 'H')sit = 3;
        else if(str[i] == 'T')sit = 4;
        int ans = 0;
        ans += (str[i+1] - '0') * 10 + (str[i+2] - '0');
        cnt[sit]++;
        if(vis[sit][ans])
        {
            printf("GRESKA");
            return 0;
        }
        vis[sit][ans] = 1;
    }
    for(i=1;i<=4;i++)printf("%d ",13-cnt[i]);
    return 0;
}
