#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char str[102];
bool vis[102];
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(cin.getline(str,100))
    {
        bool first = true;
        for(i=0;i<strlen(str);i++)
        {
            if(str[i] == ' ')first = true;
            if(first && str[i] != ' '){printf("%c",str[i]-32);first = 0;continue;}
            else printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}