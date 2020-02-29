#include<cstdio>
int bit[12];
int num;
void ten_to_bit()
{
    int cnt = 0;
    int n = num;
    int i;
    while(n > 0)
    {
        bit[cnt++] = n % 2;
        n /= 2;//这里用 n>>1 会更快一点
    }
    for(i=cnt-1;i>=0;i--)printf("%d",bit[i]);
    printf("\n");

}
int main()
{
    freopen("1.in","r",stdin);
    while(scanf("%d",&num) != EOF)
        ten_to_bit();
    return 0;
}
