/*************************************************************************
	> File Name: poj1840.cpp
	> Author: Xeon
	> Created Time: 2017年04月19日 星期三 09时54分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

const int prime=100007;

int a[6],ans;
struct _HASH
{
	int vl,cnt;
} _hash[100007];

int hash_push(int num)
{
	int tmp=(num+100000000)%prime;
	while (_hash[tmp].vl!=num&&_hash[tmp].cnt!=0) tmp=(tmp+1)%prime;
	if (_hash[tmp].vl==num) return ++_hash[tmp].cnt;
		else
		{
			_hash[tmp].vl=num;
			return _hash[tmp].cnt=1;
		}
	return 0;
}

int hash_find(int num)
{
	int tmp=(num+100000000)%prime;
	while (_hash[tmp].vl!=num&&_hash[tmp].cnt!=0) tmp=(tmp+1)%prime;
	return _hash[tmp].cnt;
}

int main()
{
	freopen("1812.in","r",stdin);
	freopen("1812.out","w",stdout);

	scanf("%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5]);

	for (int x4=-50;x4<=50;x4++)
		if (x4!=0)
			for (int x5=-50;x5<=50;x5++)
				if (x5!=0)
					hash_push(a[4]*x4*x4*x4+a[5]*x5*x5*x5);
	
	for (int x1=-50;x1<=50;x1++)
		if (x1!=0)
			for (int x2=-50;x2<=50;x2++)
				if (x2!=0)
					for (int x3=-50;x3<=50;x3++)
						if (x3!=0)
							ans+=hash_find(0-a[1]*x1*x1*x1-a[2]*x2*x2*x2-a[3]*x3*x3*x3);
	printf("%d\n",ans);
	return 0;
}
