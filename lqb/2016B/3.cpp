#include <cstdio>
bool vis[10];
int ans;
int main()
{
    int a,b,c,d,e,f,g,h,i;
    for(a=1;a<=9;a++)
    {
        vis[a] = 1;
        for(b=1;b<=9;b++)
        {
            if(vis[b])continue;
            vis[b] = 1;
            for(c=1;c<=9;c++)
            {
                if(vis[c])continue;
                vis[c] = 1;
                for(d=1;d<=9;d++)
                {
                    if(vis[d])continue;
                    vis[d] = 1;
                    for(e=1;e<=9;e++)
                    {
                        if(vis[e])continue;
                        vis[e] = 1;
                        for(f=1;f<=9;f++)
                        {
                            if(vis[f])continue;
                            vis[f] = 1;
                            for(g=1;g<=9;g++)
                            {
                                if(vis[g])continue;
                                vis[g] = 1;
                                for(h=1;h<=9;h++)
                                {
                                    if(vis[h])continue;
                                    vis[h] = 1;
                                    for(i=1;i<=9;i++)
                                    {
                                        if(vis[i])continue;
                                        int var2 = b*(100*g+10*h+i);
                                        int var3 = (100*d+10*e+f)*c;
                                        int var1 = a*(100*g+10*h+i)*c;
                                        int var4 = 10*(100*g+10*h+i)*c;
                                        if(var1 + var2 + var3 == var4)
                                        {
                                            ans++;
                                            printf("%d + %d%/%d + %d%d%d/%d%d%d == 10\n",a,b,c,d,e,f,g,h,i);
                                        }
                                    }
                                    vis[h] = 0;
                                }
                                vis[g] = 0;
                            }
                            vis[f] = 0;
                        }
                        vis[e] = 0;
                    }
                    vis[d] = 0;
                }
                vis[c] = 0;
            }
            vis[b] = 0;
        }
        vis[a] = 0;
    }
    printf("%d",ans);
    return 0;
}