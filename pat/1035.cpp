#include <iostream>
#include <cstdio>
#include <vector>
#define PR(x) cout << #x " = " << endl
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	vector<pair<char*,char*> > account;
	for(int i = 0;i < N;i++){
		char* name = new char [11];
		char* pwd = new char [11];
		scanf("%s%s",name,pwd);
		bool modified = false;
		for(int i = 0;pwd[i] != '\0';i++){
			switch(pwd[i]){
				case '1':
					pwd[i] = '@';
					modified = true;
					break;
				case '0':
					pwd[i] = '%';
					modified = true;
					break;
				case 'l':
					pwd[i] = 'L';
					modified = true;
					break;
				case 'O':
					pwd[i] = 'o';
					modified = true;
					break;
				default:
					break;
			}
		}
		if(!modified){
			delete name;
			delete pwd;
		}
		else
			account.push_back(make_pair(name,pwd));
	}
	if(N == 1)
		printf("There is %d account and no account is modified\n",N);
	else if(account.size() == 0)
		printf("There are %d accounts and no account is modified\n",N);
	else{
		printf("%d\n",account.size());
		for(int i = 0;i < account.size();i++)
			printf("%s %s\n",account[i].first,account[i].second);
	}
	return 0;
}
