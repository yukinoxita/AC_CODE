/*
 *title : 新二叉树
 * */
#include <cstdio>
int n;
struct node
{
    int fa,l,r;
}a[1000];
void dfs(int pos)
{
    if(pos == 0) return;
    printf("%c",'a'-1+pos);
    dfs(a[pos].l);
    dfs(a[pos].r);
}
int main()
{
    register int i;
    freopen("1.in", "r", stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        char buf[3];
        scanf("%s",buf);
        int f =  buf[0] - 'a' + 1;
        int ll = buf[1] - 'a' + 1;
        int rr = buf[2] - 'a' + 1;
        if(buf[1] != '*')
        {
            a[f].l = ll;
            a[ll].fa = f;
        }
        if(buf[2] != '*')
        {
            a[f].r = rr;
            a[rr].fa = f;
        }
    }
    int root = 1;
    while(a[root].fa != 0)
        root = a[root].fa;
    dfs(root);
    return 0;
}
