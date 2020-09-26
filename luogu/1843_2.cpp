/*
Author  : yukki
Time    : 2020.9.1
OJ      : luogu
Pid     : 1843
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,a,b;
class heap
{
    public:
    vector <int> vec;
    void init()
    {
        vec.push_back(0);
    }
    void up(int pos)
    {
        while(pos>>1)
        {
            if(vec[pos] > vec[pos>>1])
            {
                int tmp = vec[pos];
                vec[pos] = vec[pos>>1];
                vec[pos>>1] = tmp;
                pos = pos>>1;
            }
            else break;
        }
    }
    void down(int pos)
    {
        while(pos<<1 <= vec.size() - 1)
        {
            int p = pos << 1;
            if(vec[p+1] > vec[p] && p+1 <= vec.size()-1)p++;
            if(vec[p] > vec[pos])
            {
                int tmp = vec[p];
                vec[p] = vec[pos];
                vec[pos] = tmp;
                pos = p;
            }
            else break;
        }
    }
    void push(int num)
    {
        vec.push_back(num);
        up(vec.size()-1);
    }
    void print()
    {
        vector <int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
};
heap T;
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    cin>>n>>a>>b;
    int times = 0;
    T.init();
    for(i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        T.push(tmp);
        //T.print();
    }
    while(T.vec[1] > a*times)
    {
        times++;
        T.vec[1] -= b;
        T.down(1);
    }
    cout<<times<<endl;
    return 0;
}

