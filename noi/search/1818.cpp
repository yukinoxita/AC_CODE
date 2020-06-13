#include <cstdio>
#include <cstring>
int n,m;
char map[25][25];
bool vis[25][25];
int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int cnt=0;
bool not_in_map(int x,int y){return x < 0 || x > m-1 || y < 0 || y > n-1;}//判断是否在地图内
void dfs(int x,int y)
{
	cnt++;
	vis[x][y] = true;
	int i;
	int nx,ny;
	for(i=0;i<4;i++)
	{
		nx = x + step[i][0];
		ny = y + step[i][1];
		if(map[nx][ny] == '#' || vis[nx][ny] || not_in_map(nx,ny))continue;//走不了。做过了，不在地图内直接跳过
		dfs(nx,ny);
	}
}
int main()
{
	int i,j;
	freopen("1.in", "r", stdin);
	while(1)
	{
		int sx,sy;
		bool find = false;
		scanf("%d%d",&n,&m);
		if(n == 0 && m == 0)break;
		cnt = 0;
		for(i=0;i<m;i++)scanf("%s",map[i]);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(map[i][j] == '@'){sx = i;sy = j;find=1;break;}
			}
			if(find)break;
		}
		dfs(sx,sy);
		printf("%d\n",cnt);
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
