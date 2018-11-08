#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n,b1,b2,x[1005],y[1005];
double dis[1005][1005],f[1005][1005];

int main()
{
	freopen("paths.in","r",stdin);
	freopen("paths.out","w",stdout);
	
	scanf("%d%d%d",&n,&b1,&b2); b1++,b2++;
	
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=1000000000;
	
	f[1][1]=0;
	for (int i=1;i<n;i++)
		for (int j=1;j<n;j++)
		{
			int l=max(i,j)+1;
			if (l!=b2) f[l][j]=min(f[l][j],f[i][j]+dis[i][l]);
			if (l!=b1) f[i][l]=min(f[i][l],f[i][j]+dis[j][l]);
		}
	
	double ans=1000000000;
	for (int i=1;i<n;i++)
		ans=min(ans,min(f[i][n],f[n][i])+dis[i][n]);
	
	printf("%.2lf\n",ans);
	
	return 0;
}
