#include <cstdio>
int n,m;
void draw()
{
    int i,j;
    /*the first line*/
    printf("+");
    for(i=1;i<=n;i++)printf("-");
    printf("+\n");

    /*the middle line*/
    for(i=1;i<=m;i++)
    {
        printf("|");
        for(j=1;j<=n;j++)printf(" ");
        printf("|\n");
    }

    /*the last line*/
    printf("+");
    for(i=1;i<=n;i++)printf("-");
    printf("+\n");
    printf("\n");
}
int main()
{
    freopen("1.in","r",stdin);
    while(scanf("%d%d",&n,&m) != EOF)draw();
    return 0;
}