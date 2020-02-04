#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[90];
int n;
bool check(char s[])
{
    int i,j;
    char f = s[0];
    if(!((f >= 'a' && f <= 'z') || (f >= 'A' && f <= 'Z') || f == '_'))return false;
    for(i=1;i<strlen(s);i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '_' || (s[i] <= '9' && s[i] >= '0'))continue;
        else return false;
    }
    return true;
}
int main()
{
    int i;
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        cin.getline(str,90);
        if(check(str))printf("yes");
        else printf("no");
        //if(i != n)printf("\n");
        printf("\n");
    }

    return 0;
}
