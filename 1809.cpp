/*************************************************************************
	> File Name: 1809.cpp
	> Author: Xeon
	> Created Time: 2017年04月19日 星期三 18时45分39秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int n,m,v[355],w[5],f[45][45][45][45];
bool use[125];

int main()
{
	freopen("1809.in","r",stdin);
	freopen("1809.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1,b;i<=m;i++)
	{
		scanf("%d",&b);
		w[b]++;
	}
	for (int i=0;i<=w[1];i++)
		for (int j=0;j<=w[2];j++)
			for (int k=0;k<=w[3];k++)
				for (int l=0;l<=w[4];l++)
				{
					int to=i+j*2+k*3+l*4+1;
					if (i>0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+v[to]);
					if (j>0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+v[to]);
					if (k>0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+v[to]);
					if (l>0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+v[to]);
				}
	int ans=0;
	for (int i=0;i<=w[1];i++)
		for (int j=0;j<=w[2];j++)
			for (int k=0;k<=w[3];k++)
				for (int l=0;l<=w[4];l++)
					ans=max(ans,f[i][j][k][l]);
	printf("%d",ans+v[1]);
	return 0;
}
