#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int n,p[100005];

main()
{
    freopen("2702.in","r",stdin);
    freopen("2702.out","w",stdout);

    scanf("%lld",&n);

    for (int i=1;i<=n;i++) scanf("%lld",&p[i]);

    int cur=0,ans=0;
    for (int i=1;i<=n;i+=2)
    {
        if (i+1<=n) cur+=abs(p[i]-p[i+1]);
        ans=max(ans,cur);
        if (i+2<=n) cur-=abs(p[i+1]-p[i+2]);
        if (cur<0) cur=0;
        ans=max(ans,cur);
    }

    cur=0;
    for (int i=2;i<=n;i+=2)
    {
        if (i+1<=n) cur+=abs(p[i]-p[i+1]);
        ans=max(ans,cur);
        if (i+2<=n) cur-=abs(p[i+1]-p[i+2]);
        if (cur<0) cur=0;
        ans=max(ans,cur);
    }

    printf("%lld\n",ans);

    return 0;
}
