#include <cstdio>
#include <algorithm>

#define int long long

int n,facn,fac[100005],cnt[100005];

signed main()
{
	freopen("beats.in","r",stdin);
	freopen("beats.out","w",stdout);
	
	scanf("%lld",&n);
	
	for (int i=1;i*i<=n;i++)
		if (n%i==0)
		{
			fac[++facn]=i;
			if (i*i!=n) fac[++facn]=n/i;
		}
	
	std::sort(fac+1,fac+1+facn);
	
	int ans=0;
	for (int i=facn;i>=1;i--)
	{
		cnt[i]=n/fac[i];
		for (int j=i+1;j<=facn;j++)
			if (fac[j]%fac[i]==0) cnt[i]-=cnt[j];
		ans+=cnt[i]*fac[i];
	}
	
	printf("%lld\n",ans+1);
	
	return 0;
}
