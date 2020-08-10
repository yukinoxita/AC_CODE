/*
Author  : yukki
Time    : 2020.6.1
OJ      : luogu
Pid     : 1981
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#define scnaf scanf
int n;
char str[1000010];
int num[1000100];
int su[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main()
{
    register int i,j;
    int sit = 1;
    freopen("in","r",stdin);
    scanf("%s",str);
    int tmp = 0;
    int bit = 0;
    int ans = 0;
    memset(num,-1,sizeof(num));
    //for(i=1;i<1000100;i++)printf("%d\n",num[i]);
    for(i=strlen(str)-1;i>=0;i--)
    {
        if(str[i] != '+' && str[i] != '*')
        {
            tmp += (str[i]-'0')*su[bit++];
        }
        else if(str[i] == '+')
        {
            bit = 0;
            num[sit] = abs(num[sit]);
            num[sit] = ((num[sit]%10000)*(tmp%10000))%10000;
            sit++;
            tmp = 0;
        }
        else
        {
            bit = 0;
            num[sit] = abs(num[sit]);
            num[sit] = (abs(num[sit]%10000)*(tmp%10000))%10000;
            tmp = 0;
        }
    }
    num[sit] = abs(num[sit]);
    num[sit] *= tmp;
    sit++;
    for(i=1;i<sit;i++)ans += (num[i])%10000;
    printf("%d\n",ans%10000);
	return 0;
}

