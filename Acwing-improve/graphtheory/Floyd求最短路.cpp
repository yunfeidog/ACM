#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=210,INF=0x3f3f3f3f;
int d[N][N];
int n,m,t;

int main()
{
	cin>>n>>m>>t;
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++) d[i][i]=0;

	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(d[x][y]>INF/2) cout<<"impossible"<<endl;
		else cout<<d[x][y]<<endl;
	}
	return 0;

}

