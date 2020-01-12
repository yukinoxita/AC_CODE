#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct date
{
    int y,m,d;
}a[20];
char d[9];
int sit = 0;
int check[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isrun(int year)
{
    if(year % 100 == 0 && year % 400 == 0)return true;
    if(year % 100 != 0 && year % 4 == 0)return true;
    return false;
}
void nyr(int when,int yy,int mm,int dd)
{
    int num = when + yy;
    if(num > 2059 || num < 1960)return;
    if(dd > 31)return;
    if(mm > 12)return;
    if(mm == 2)
    {
        if(isrun(num))
        {
            if(dd > 29)return;
        }
        else
        {
            if(dd > 28)return;
        }
    }
    if(mm != 2)
        if(dd > check[mm])return;
    sit++;
    a[sit].y = num;
    a[sit].m = mm;
    a[sit].d = dd;
}
bool cmp(const date &a, const date &b)
{
    if(a.y < b.y)return 1;
    if(a.y == b.y)
    {
        if(a.m < b.m)return 1;
        if(a.m == b.m)
        {
            if(a.d < b.d)return 1;
            return 0;
        }
        return 0;
    }
    return 0;
}
/*
    yy mm dd
    年 月 日
    dd yy mm
    月 日 年
    dd mm yy
    日 月 年


    这个转换需要注意一下
    好好想想
*/
int main()
{
    int i;
    freopen("1.in","r",stdin);
    scanf("%s",d);
    int yy = (d[0] - '0') * 10 + (d[1] - '0'); 
    int mm = (d[3] - '0') * 10 + (d[4] - '0');
    int dd = (d[6] - '0') * 10 + (d[7] - '0');
    nyr(1900,yy,mm,dd);
    nyr(2000,yy,mm,dd);//年月日
    nyr(1900,dd,yy,mm);
    nyr(2000,dd,yy,mm);//月日年
    nyr(1900,dd,mm,yy);
    nyr(2000,dd,mm,yy);//日月年
    sort(a+1,a+sit,cmp);
    for(i=1;i<=sit;i++)printf("%d-%d-%d\n",a[i].y,a[i].m,a[i].d);
    return 0;
}