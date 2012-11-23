#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.first < b.first)
		return true;
	else if(a.first == b.first)
	{
		if(a.second <= b.second)
			return true;
		else 
			return false;
	}
	else
		return false;
}
int main()
{
	int N,M;
	while(cin >> N >> M)
	{
		int minWi,maxWi;
		vector <pair <int,int> > pairs;
		for(int i = 0;i < N;i++)
		{
			cin >> minWi >> maxWi;
			pair <int,int> newpair = make_pair(minWi,maxWi);
			pairs.push_back(newpair);
		}
		int* weights = new int[M];
		for(int i = 0;i < M;i++)
			cin >> weights[i];
		sort(weights,weights + M);
		sort(pairs.begin(),pairs.end(),cmp);
		int count = 0;
		/*for(int i = 0;i < pairs.size();i++)
			cout << pairs[i].first << " " << pairs[i].second << endl;*/
		for(int i = 0;i < M;i++)
		{
			int right = 1001;
			int index = -1;
			for(int j = 0;j < pairs.size();j++)
			{
				if(pairs[j].first <= weights[i] && pairs[j].second >= weights[i])
				{
					if(pairs[j].second < right)
					{
						right = pairs[j].second;
						index = j;
					}
				}
			}
			if(index != -1)
			{
				count++;
				pairs.erase(pairs.begin() + index);
			}
			/*for(int i = 0;i < pairs.size();i++)
				cout << pairs[i].first << " " << pairs[i].second << endl;*/
		}
		cout << count << endl;
		delete weights;
	}
}