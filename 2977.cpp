#include <cstdio>
#include <cmath>

int n,m,v[55],a[55];
long long sum;

int main()
{
	freopen("2977.in","r",stdin);
	freopen("2977.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&v[i]);
		sum+=v[i];
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}

	v[1]+=a[1]+a[n];
	if (m>100) printf("%d",(int)ceil((double)v[1]/sum*m));
		 else printf("%d",(int)ceil((double)v[1]/sum*m)+1);

	return 0;
}
