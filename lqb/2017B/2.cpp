#include <cstdio>
#include <cstring>
bool vis[1000001];
int prime[100000];
int ans[15];
bool flag = 0;
int main()
{
    int i,j;
    int n = 10000;
    for(i=2;i<=n;i++)
    {
        if(!vis[i])
        for(j=i+i;j<=n;j+=i)vis[j] = 1;
    }
    int sit = 0;
    // for(i=2;i<=n;i++)if(!vis[i])printf("%d ",i);
    for(i=2;i<=n;i++)if(!vis[i])prime[++sit] = i;

    for(j=3;;j++)//公差
    {
        for(i=1;i<sit;i++)
        {
            int num = prime[i];
            int len = 1;
            while(1)
            {
                if(num + j > n)break;
                if(!vis[num]){ans[len] = num;num += j;len++;}
                else break;
                if(len == 11){flag = 1;printf("%d\n",j);break;}
            }
            if(flag)break;
        }
        if(flag)break;
    }
    for(i=1;i<=10;i++)printf("%d ",ans[i]);
    return 0;
}