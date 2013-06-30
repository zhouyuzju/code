#include <iostream>
#include <cstring>
#define MAXN (1<<14)
#define NOCOLOR -1
#define MULTICOLOR -2
struct seg
{
	int le, ri, c;
};
seg st[MAXN];
int color[MAXN];
void init(int le, int ri, int t)
{
	st[t].le = le;
	st[t].ri = ri;
	st[t].c = NOCOLOR;
	if(le != ri)
	{
		int mid = (le + ri) / 2;
		init(le, mid, 2 * t);
		init(mid + 1, ri, 2 * t + 1);
	}
}

void insert(int le, int ri, int c, int t)
{
	if(st[t].le == le && st[t].ri == ri)
	{
		st[t].c = c;
		return;
	}
	if(st[t].c != MULTICOLOR)
	{
		st[2 * t].c = st[t].c;
		st[2 * t + 1].c = st[t].c;
		st[t].c = MULTICOLOR;
	}
	int mid = (st[t].le + st[t].ri) / 2;
	if(mid >= ri)
		insert(le, ri, c, 2 * t);
	else if(mid < le)
		insert(le, ri, c, 2 * t + 1);
	else
	{
		insert(le, mid, c, 2 * t);
		insert(mid + 1, ri, c, 2 * t + 1);
	}
}
void findcolor(int t)
{
	if(st[t].c == NOCOLOR)
		return;
	else if(st[t].c == MULTICOLOR)
	{
		findcolor(2 * t);
		findcolor(2 * t + 1);
	}
	else
	{
		for(int i = st[t].le; i <= st[t].ri; ++i)
			color[i] = st[t].c;
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		init(0, 8000, 1);
		int le, ri, c;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d%d", &le, &ri, &c);
			insert(le, ri - 1, c, 1);
		}
		memset(color, NOCOLOR, sizeof(color));
		findcolor(1);
		int prec = NOCOLOR, segcnt[MAXN];
		memset(segcnt, 0, sizeof(segcnt));
		for(int i = 0; i <= 8001; ++i)
		{
			if(prec != color[i] && prec != -1)
				segcnt[prec]++;
			prec = color[i];
		}
		for(int i = 0; i < 8001; ++i)
			if(segcnt[i] > 0)
				printf("%d %d\n", i, segcnt[i]);
		printf("\n");
	}
	return 0;
}


