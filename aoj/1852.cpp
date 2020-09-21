/*
Author  : yukki
Time    : 2020.9.12
OJ      : aoj
Pid     : 1852
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
int n,m;
class QQ
{
    public:
        queue <int> del;
        queue <int> num;

    void Add(int x)
    {
        num.push(x);
    }

    void Delete()
    {
        int x = num.front();
        del.push(x);
        num.pop();
    }

    void Add_tail()
    {
        int x = num.front();
        num.pop();
        num.push(x);
    }
    void print()
    {
        while(!del.empty())
        {
            cout<<del.front()<<" ";
            del.pop();
        }
    }
};
int main()
{
    register int i,j;
    int len;
    QQ qq;
    freopen("in","r",stdin);
    scanf("%d",&len);
    F1(i,len)
    {
        int tmp;
        scanf("%d",&tmp);
        qq.Add(tmp);
    }
    while(!qq.num.empty())
    {
        if(qq.num.size() == 1)
        {
            qq.Delete();
            continue;
        }
        qq.Delete();
        qq.Add_tail();
    }
    qq.print();
    cout<<endl;
    return 0;
}

