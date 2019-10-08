%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")

#include <cstdio>
#include <map>

using namespace std;

int n,a[200005];
map <int,int> record;

int main()
{
	freopen("2971.in","r",stdin);
	freopen("2971.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    if (n<=10000)
    {
        long long ans=0,sum=0;
        for (int i=1;i<=n;i++)
	  	{
            sum=0;
            for (int j=i;j<=n;j++)
            {
                if (record[a[j]]!=i) sum+=(long long)a[j],record[a[j]]=i;
                if (sum>ans) ans=sum;
            }
        }
        printf("%lld\n",ans);
    }
    else
    {
        long long ans=0,sum=0;
        for (int i=1;i<=n;i++)
        {
            sum+=(long long)a[i];
            if (sum>ans) ans=sum;
            if (sum<0) sum=0;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
