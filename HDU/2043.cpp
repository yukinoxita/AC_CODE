#include <cstdio>
#include <cstring>
#include <cmath>
int n;
char str[60];
/*
48-57
97-122
65-90

64
33
35-37
94
126
*/
bool check()
{
    int i;
    int cnt =0;
    bool a=0,b=0,c=0,d=0;
    for (i = 0; i < strlen(str); i++)
    {
        int num = str[i];
        if(num >= 48 && num <= 57){a = 1;continue;}
        else if(num >= 65 && num <= 90){b = 1;continue;}
        else if(num >= 97 && num <= 122){c = 1;continue;}
        else if(num == 64 || num == 94 || num ==126 ||(num >= 33 && num <=37 && num != 34)){d = 1;continue;}
        else return false;
    }
    if(a)cnt++;
    if(b)cnt++;
    if(c)cnt++;
    if(d)cnt++;
    if(cnt >= 3)return true;
    return false;
}
int main()
{
    int i;
    freopen("1.in", "r", stdin);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", str);
        if(strlen(str) < 8 || strlen(str) > 16){printf("NO\n");continue;}
        else
        {
            if(check())printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
