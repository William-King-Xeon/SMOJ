/*************************************************************************
	> File Name: 1829-hash.cpp
	> Author: Xeon
	> Created Time: Sun 23 Apr 2017 09:40:43 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

const int numprime=1572869;
const int prime=196613;

struct HASH
{
	int num1,num2,cnt,pos;
} _hash[prime];

int n,k,sum[100005][35],Max;

int hash_find(int num1,int num2)
{
	int tmp=(num1+1000000000)%prime;
	while ((_hash[tmp].num1!=num1||_hash[tmp].num2!=num2)&&_hash[tmp].cnt!=0)
		tmp=(tmp+(num1+1000000000)%prime)%prime;
	return _hash[tmp].pos;
}

int hash_push(int num1,int num2,int pos)
{
	int tmp=(num1+1000000000)%prime;
	while ((_hash[tmp].num1!=num1||_hash[tmp].num2!=num2)&&_hash[tmp].cnt!=0)
		tmp=(tmp+(num1+1000000000)%prime)%prime;
	if (_hash[tmp].cnt==0)
	{
		_hash[tmp].num1=num1;
		_hash[tmp].num2=num2;
		_hash[tmp].pos=pos;
	}
	return ++_hash[tmp].cnt;
}

int main()
{
	freopen("1829.in","r",stdin);
	freopen("1829.out","w",stdout);

	scanf("%d%d",&n,&k);
	for (int i=1,set;i<=n;i++)
	{
		scanf("%d",&set);
		for (int j=1;j<=k;j++)
			if (set&(1<<j-1)) sum[i][j]=sum[i-1][j]+1; else sum[i][j]=sum[i-1][j];
	}

	for (int i=0;i<prime;i++) _hash[i].pos=-1;

	for (int i=0;i<=n;i++)
	{
		int num1=0,num2=0;
		for (int j=2;j<=k;j++)
		{
			num1=(num1*10%numprime+sum[i][j]-sum[i][j-1])%numprime;
			num2=(num2*13%numprime+sum[i][j]-sum[i][j-1])%numprime;
		}
		int ans=hash_find(num1,num2);
		if (ans!=-1) Max=max(i-ans,Max);
		hash_push(num1,num2,i);
	}
	printf("%d\n",Max);
	return 0;
}
