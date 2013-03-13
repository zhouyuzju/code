/**
 * Easy problem,just try and read carefully about the describe.
 * 2013/3/13
 **/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#define MIN -1001 * 1000
using namespace std;
int main(){
	int n,maxScore = MIN;
	string winName;
	map<string,int> one,two;
	vector<pair<string,int> > lists;
	set <string> names;
	cin >> n;
	for(int i = 0;i < n;i++){
		string tmpName;
		int tmpScore;
		cin >> tmpName >> tmpScore;
		one[tmpName] += tmpScore;
		lists.push_back(make_pair(tmpName,tmpScore));
	}
	for(map<string,int>::iterator it = one.begin();it != one.end();it++)
		if(it->second > maxScore)
			maxScore = it->second;
	//cout << maxScore << endl;
	for(map<string,int>::iterator it = one.begin();it != one.end();it++){
		//cout << it->first << "," << it->second << endl;
		if(it->second == maxScore)
			names.insert(it->first);
	}
	for(int i = 0;i < n;i++){
		string aname = lists[i].first;
		int ascore = lists[i].second;
		if(names.find(aname) != names.end() && two[aname] + ascore>= maxScore){
			cout << aname << endl;
			break;
		}
		else{
			two[aname] += ascore;
		}
	}
}
