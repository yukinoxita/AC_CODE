#include <cstdio>
bool vis[10];
//(abcd-efgh)*ij = 900
bool flag = false;
int main()
{
    int a,b,c,d,e,f,g,h,i,j;
    for(a=1;a<=9;a++)
    {
        if(flag)break;
        vis[a] = 1;
        for(b=0;b<10;b++)
        {
            if(flag)break;
            if(vis[b])continue;
            vis[b] = 1;
            for(c=0;c<10;c++)
            {
                if(flag)break;
                if(vis[c])continue;
                vis[c] = 1;
                for(d=0;d<10;d++)
                {
                    if(flag)break;
                    if(vis[d] || 1000*a+100*b+10*c+d == 5012)continue;
                    vis[d] = 1;
                    for(e=1;e<10;e++)
                    {
                        if(flag)break;
                        if(vis[e])continue;
                        vis[e] = 1;
                        for(f=0;f<10;f++)
                        {
                            if(flag)break;
                            if(vis[f])continue;
                            vis[f] = 1;
                            for(g=0;g<10;g++)
                            {
                                if(flag)break;
                                if(vis[g])continue;
                                vis[g] = 1;
                                for(h=0;h<10;h++)
                                {
                                    if(flag)break;
                                    if(vis[h])continue;
                                    vis[h] = 1;
                                    for(i=1;i<10;i++)
                                    {
                                        if(flag)break;
                                        if(vis[i])continue;
                                        vis[i] = 1;
                                        for(j=0;j<10;j++)
                                        {
                                            if(flag)break;
                                            if(vis[j])continue;
                                            vis[j] = 1;
                                            int num1 = 1000*a+100*b+10*c+d;
                                            int num2 = 1000*e+100*f+10*g+h;
                                            int num3 = 10*i+j;
                                            if((num1 - num2) * num3 == 900)
                                            {
                                                printf("%d-%d*%d=900",num1,num2,num3);
                                                flag = 1;
                                                break;
                                            }
                                            vis[j] = 0;
                                        }
                                        vis[i] = 0;
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
    return 0;
}