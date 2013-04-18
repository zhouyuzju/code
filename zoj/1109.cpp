#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main(){
	string q;
	char line[30];
	map<string,string> word;
	while(gets(line)){
		if(line[0] == '\0')
			break;
		string aline = line;
		int pos = aline.find(" ");
		string a = aline.substr(0,pos);
		string b = aline.substr(pos + 1);
		word[b] = a;
	}
	while(cin >> q){
		if(word.find(q) != word.end())
			cout << word[q] << endl;
		else
			cout << "eh" << endl;
	}
}
