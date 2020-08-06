/*
Author  : yukki
Time    : 2020.8.5
OJ      : luogu
Pid     : 5661
 */
#include <cstdio>
#include <algorithm>
#define scnaf scanf
int n;
int head=1;
int V[100010];
int T[100010];
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    int ans = 0;
    int cnt = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int nori,kane,time;
        scanf("%d%d%d",&nori,&kane,&time);
        if(nori == 0)
        {
            ans += kane;
            cnt++;
            V[cnt] = kane;
            T[cnt] = time;
        }
        else
        {
            int idx = -1;
            for(j=cnt;j>=1;j--)
            {
                if(time-T[j] > 45)break;
                if(V[j] >= kane)
                {
                    idx = j;
                }
            }
            if(idx == -1)ans += kane;
            else
            {
                V[idx] = -1;
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}

