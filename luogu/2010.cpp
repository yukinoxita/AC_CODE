/*
Author  : yukki
Time    : 2020.8.5
OJ      : luogu
Pid     : 2010
 */
#include <cstdio>

#define scnaf scanf
/*
根据题目想要回文那一定是和年份回文
我们可以根据d1到d2进行循环，构造回
文然后判断是否为有效日期并在范围内
*/
int n;
int d1,d2;
int re(int num)
{
    //倒序输出数字
    int a,b,c,d;
    a = num % 10;
    num /= 10;

    b = num % 10;
    num /= 10;

    c = num %10;
    d = num/10;
    return 1000*a+100*b+10*c+d;
}
bool getsu(int num)
{
    if(num > 12 || num < 1)return 0;
    return 1;
}
bool is_run(int y)
{
    if(y % 400 == 0 ||(y%4==0 && y%100 !=0 ))return 1;
    return 0;
}
bool nichi(int year,int mon,int num)
{
    if(num > 31)return false;
    if((mon == 4 || mon == 6 || mon == 9 || mon == 11) && num > 30)return 0;
    if(mon == 2)
    {
        if(is_run(year)  && num > 29)return 0;
        if(!is_run(year) && num > 28)return 0;
    }
    return 1;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&d1,&d2);
    int ans = 0;
    for(i=d1/10000;i<=d2/10000;i++)
    {
        int renum = re(i);
        if(!getsu(renum/100) || !nichi(i,renum/100,renum%100))continue;
        int newnum = 10000*i+renum;
        if(newnum < d1 || newnum > d2)continue;
        printf("%d\n",newnum);
        ans++;
    }
    printf("%d\n",ans);
	return 0;
}

