/*
Author  : yukki
Time    : 2020.6.1
OJ      : luogu
Pid     : 5660
 */
#include <cstdio>
#include <cstring>
#define scnaf scanf
int ans;
char str[9];
int main()
{
    register int i,j;
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] == '1')ans++;
    }
    printf("%d\n",ans);
	return 0;
}

