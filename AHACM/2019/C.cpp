#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[50010];
int b[50010];
bool vis[100010];
int ans;
bool cmp(const int &a, const int &b){return a>b;}
int main()
{
    register int i;
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++){scanf("%d",&b[i]);vis[b[i]] = 1;}
    int sit = 1;
    for(i=n<<1;i>=1;i--){if(!vis[i])a[sit++] = i;}
    //sort(a+1,a+1+(n>>1),cmp); // z这部分没有必要排序
    sort(a+1+(n>>1),a+1+n); 

    sort(b+1,b+1+(n>>1),cmp);
    sort(b+1+(n>>1),b+1+n);
/*
    for(i=1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",b[i]);
    printf("\n");
*/
    int r = n>>1;
    int l = 1;
    for(i=1;i<=n>>1;i++)
    {
        if(b[i] > a[l]){r--;}
        else {l++;ans++;}
    }
    l = (n>>1)+1;
    r = n;
    for(i=(n>>1)+1;i<=n;i++)
    {
        if(b[i] < a[l]){r--;}
        else {l++;ans++;}
    }

    printf("%d\n",ans);
    return 0;
}
