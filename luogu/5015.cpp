/*
Author  : yukki
Time    : 2020.8.5
OJ      : luogu
Pid     : 5015
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#define scnaf scanf
using namespace std;
int n;
char str[10];
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    cin.getline(str,10);
    int ans = 0;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] != ' ')ans++;
    }
    printf("%d\n",ans);
	return 0;
}

