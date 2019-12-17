#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
char str[10001];
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int cnt = 0;
        cin>>str;
        for(j=0;j<strlen(str);j++)
            if(str[j] - '0' >= 0 && str[j] - '0' <= 9)cnt++;

        printf("%d\n",cnt);
        memset(str,0,sizeof(str));
    }
    return 0;
}