#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=2510,M=6200*2+10;
int n,m,s,t;
int h[N],e[M],w[M],ne[M],idx;
int dist[N],q[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}


void spfa()
{
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	int hh=0,tt=1;
	q[0]=s;st[s]=true;
	while(hh!=tt)
	{
		int t=q[hh++];
		if(hh==N) hh=0;
		st[t]=false;

		for(int i=h[t];~i;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[t]+w[i])
			{
				dist[j]=dist[t]+w[i];
				if(!st[j])
				{
					q[tt++]=j;
					if(tt==N) tt=0;
					st[j]=true;
				}
			}
		}
	}
}

int main()
{
	cin>>n>>m>>s>>t;
	memset(h,-1,sizeof h);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c),add(b,a,c);
	}	

	spfa();
	cout<<dist[t];
	return 0;
}

