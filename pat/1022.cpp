#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <string>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

vector<string> split(string str){
	vector<string> words;
	while(true){
			int pos = str.find(' ');
			if(pos == 0){
				str = str.substr(1);
				continue;
			}
			if(pos < 0){
				words.push_back(str);
				break;
			}
			string word = str.substr(0,pos);
			str = str.substr(pos + 1);
			words.push_back(word);
		}
	return words;
}

int main(){
	int N;
	scanf("%d",&N);
	map<string,set<int> > titleIdx,authorIdx,publisherIdx,keywordIdx;
	map<int,set<int> > yearIdx;
	for(int i = 0;i < N;i++){
		int id;
		string title;
		string author;
		string keywords;
		string publisher;
		int year;
		cin >> id;
		getchar();
		getline(cin,title);
		getline(cin,author);
		getline(cin,keywords);
		getline(cin,publisher);
		cin >> year;
		titleIdx[title].insert(id);
		authorIdx[author].insert(id);
		publisherIdx[publisher].insert(id);
		vector<string> words = split(keywords);
		for(int j = 0;j < words.size();j++)
			keywordIdx[words[j]].insert(id);
		yearIdx[year].insert(id);
	}
	int M;
	scanf("%d",&M);
	getchar();
	for(int i = 0;i < M;i++){
		string query;
		getline(cin,query);
		int type = query[0] - '0';
		cout << query << endl;
		set<int> ids;
		switch(type){
			case 1:{
				string title = query.substr(3);
				ids = titleIdx[title];
				if(ids.size() == 0){
					printf("Not Found\n");
					break;
				}
				for(set<int>::iterator it = ids.begin();it != ids.end();it++)
					printf("%07d\n",*it);
			       }
				break;
			case 2:{
				string author = query.substr(3);
				ids = authorIdx[author];
				if(ids.size() == 0){
					printf("Not Found\n");
					break;
				}
				for(set<int>::iterator it = ids.begin();it != ids.end();it++)
					printf("%07d\n",*it);
			       }
				break;
			case 3:{
				string keyword = query.substr(3);
				ids = keywordIdx[keyword];
				if(ids.size() == 0){
					printf("Not Found\n");
					break;
				}
				for(set<int>::iterator it = ids.begin();it != ids.end();it++)
					printf("%07d\n",*it);
			       }
				break;
			case 4:{
				string publisher = query.substr(3);
				ids = publisherIdx[publisher];
				if(ids.size() == 0){
					printf("Not Found\n");
					break;
				}
				for(set<int>::iterator it = ids.begin();it != ids.end();it++)
					printf("%07d\n",*it);
			       }
				break;
			case 5:{
				string yearStr = query.substr(3);
				int year = 1000 * (yearStr[0] - '0') + 100 * (yearStr[1] - '0') + 10 * (yearStr[2] - '0') + (yearStr[3] - '0');
				ids = yearIdx[year];
				if(ids.size() == 0){
					printf("Not Found\n");
					break;
				}
				for(set<int>::iterator it = ids.begin();it != ids.end();it++)
					printf("%07d\n",*it);
			       }
				break;
			default:
				break;
		}
	}
	return 0;
}
