#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        if(s.length() <= 0)
            return *(new vector<vector<string> >());
        int n = s.length();
        bool isP[1000][1000];
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                isP[i][j] = false;
        for(int i = 0;i < n;i++){
            for(int j = 0;i + j < n && i - j >= 0;j++)
                if(s[i + j] == s[i - j])
                    isP[i - j][i + j] = true;
                else
                    break;
            for(int j = 0;i + j + 1 < n && i - j >= 0;j++)
                if(s[i + j + 1] == s[i - j])
                    isP[i - j][i + j + 1] = true;
                else
                    break;
        }
        return *(construct(isP,0,n,s));        
    }
    
    vector<vector<string> >* construct(bool isP[1000][1000], int start, int n,string& str){
	vector<vector<string> >* r = new vector<vector<string> >();
        if(start == n){
            r->push_back(*(new vector<string>()));
	    return r;
        }
        for(int i = start;i < n;i++)
            if(isP[start][i]){
            	vector<vector<string> >* tmp = construct(isP,i + 1,n,str);
	   	for(int j = 0;j < tmp->size();j++){
			vector<string>* sub = new vector<string>();
			sub->push_back(str.substr(start,i - start + 1));
			for(int k = 0;k < tmp->at(j).size();k++)
				sub->push_back(tmp->at(j)[k]);
			r->push_back(*sub);
		}
		delete tmp;
            }
        return r;
    }
};

int main(){
	string str = "abcde";
	Solution *a = new Solution();
	vector<vector<string> > result = a->partition(str);
	for(int i = 0;i < result.size();i++){
		vector<string> line = result[i];
		for(int j = 0;j < line.size();j++)
			cout << line[j] << "\t";
		cout << endl;
	}
}
