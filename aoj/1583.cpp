#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
using namespace std;
stack <char> st;
map <char,char> m;
char str[1020];
void clear()
{
    while(!st.empty())
        st.pop();
}
int main()
{
    m.insert(make_pair('}','{'));
    m.insert(make_pair(')','('));
    m.insert(make_pair(']','['));
    freopen("in","r",stdin);
    while(cin>>str)
    {
        bool flag = 0;
        clear();
        for(int i=0;i<strlen(str);i++)
        {
            if(st.empty()){st.push(str[i]);continue;}
            if(st.top() == m[str[i]])
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
        if(st.empty())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
