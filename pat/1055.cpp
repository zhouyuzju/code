#include<iostream>
#include<cstring>
#include<cstdio>
#include <algorithm>
using namespace std;
struct node{
	char name[10];
	int age,worth;
}a[100005];
int b[20005];
int c[205];
bool cmp2(const node& p,const node& q){
	if(p.worth==q.worth)
	{
		if (p.age==q.age)
		{
			return strcmp(p.name,q.name)<=0;
		}
		return p.age<q.age;
	}
	return p.worth>q.worth;
}
int main()
{
	int n,q,i,M,ma,mb,txt=1,len;
	while(~scanf("%d %d",&n,&q))
	{
		memset(c,0,sizeof(c));
		for (i=0;i<n;++i){
			scanf("%s%d%d",a[i].name,&a[i].age,&a[i].worth);
		}
		sort(a,a+n,cmp2);
		for (len=i=0;i<n;++i){
			if (c[a[i].age]<=100)
			{
				b[len++]=i;
				c[a[i].age]++;
			}
		}
		while(q--){
			scanf("%d%d%d",&M,&ma,&mb);
			if(ma>mb){
				ma^=mb;
				mb^=ma;
				ma^=mb;
			}
			printf("Case #%d:\n",txt++);
			int cnt=0;
			for (i=0;i<len&&cnt<M;++i){
				if(a[b[i]].age>=ma&&a[b[i]].age<=mb){
					printf("%s %d %d\n",a[b[i]].name,a[b[i]].age,a[b[i]].worth);
					cnt++;
				}
			}
			if(cnt==0){
				printf("None\n");
			}
		}
	}
	return 0;
}

