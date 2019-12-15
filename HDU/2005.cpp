#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int r;
char date[15];
int d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ten[4] = {1,10,100,1000};
bool run(int num)
{
    if(num % 400 == 0)return 1;
    if(num % 4 == 0 && num % 100 !=0)return 1;
    return 0;
}
int main()
{
    int i;
 //   freopen("2.in","r",stdin);
    while(scanf("%s",date)!=EOF)
    {
        int year = 0,month = 0,day = 0;
        int sit = 0;
        int ssit = 0;
        int ans = 0;
        for(i=strlen(date)-1;i>=0;i--)
        {
            if(date[i] != '/')
            {
                if(sit == 0)day += (date[i] - '0')*ten[ssit++];
                if(sit == 1)month += (date[i] - '0')*ten[ssit++];
                if(sit == 2)year += (date[i] - '0')*ten[ssit++];
            }
            if(date[i] == '/')ssit=0,sit++;
        }
        ans +=day;
        for(i=1;i<month;i++)ans += d[i];
        if(run(year) && month > 2)ans += 1;
        printf("%d\n",ans);
    }
    return 0;
}