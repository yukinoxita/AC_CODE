#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,r;
int bit[100];
char alpha[6]={'A','B','C','D','E','F'};
int sit;
bool flag;
void print()
{
    int i;
    if(flag)printf("-");
    for(i=sit;i>=1;i--)
    {
        if(bit[i]<10)printf("%d",bit[i]);
        else printf("%c",alpha[bit[i]%10]);//这一步能看懂吗
    }
}
void kenkan()
{
    int num = n;
    sit = 0 ;
    while(num)
    {
        bit[++sit] = num % r;
        num /= r;
    }
}
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        flag = false;
        if(n<0){flag = true;n = -n;}
        kenkan();
        print();
        printf("\n");
    }
    return 0;
}