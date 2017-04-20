/*************************************************************************
	> File Name: 1813.cpp
	> Author: Xeon
	> Created Time: 2017年04月20日 星期四 11时14分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int prime=16000007;
int n,nc,NUM[256];
char st[16000000];
struct _HASH
{
	int vl,cnt;
} _hash[prime];

int hash_push(int num)
{
	int tmp=num%prime;
	while (_hash[tmp].vl!=num&&_hash[tmp].cnt!=0) tmp=(tmp+1)%prime;
	_hash[tmp].vl=num;
	return ++_hash[tmp].cnt;
}

int hash_find(int num)
{
	int tmp=num%prime;
	while (_hash[tmp].vl!=num&&_hash[tmp].cnt!=0) tmp=(tmp+1)%prime;
	return _hash[tmp].cnt;
}

int main()
{
	freopen("1813.in","r",stdin);
	freopen("1813.out","w",stdout);

	scanf("%d%d%s",&n,&nc,st);
	int top=0,
		num=0,
		len=strlen(st);
	for (int i=0;i<n;i++)
		if (NUM[st[i]]==0) num=num*nc+(NUM[st[i]]=(++top));
			else num=num*nc+NUM[st[i]];

	int MOD=1;
	for (int i=1;i<n;i++) MOD=MOD*nc%prime;

	int ans=1;
	hash_push(num);
	for (int i=n;i<len;i++)
	{
		if (NUM[st[i]]==0) num=(num%MOD*nc%prime+(NUM[st[i]]=(++top)))%prime;
			else num=(num%MOD*nc%prime+NUM[st[i]])%prime;
		if (!hash_find(num))
		{
			hash_push(num);
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
