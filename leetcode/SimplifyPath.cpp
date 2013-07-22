#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        if(path.size() == 0)
            return result;
        int idx = 0, n = path.size();
        vector<string> names;
        bool isHidden = false;	//hidden files like: "/.hidden"
        while(idx < n){
            if(path[idx] == '/'){
                idx++;
                while(idx < n && path[idx] == '/')
                    idx++;
            }
            else if(path[idx] == '.'){
                idx++;
                if(idx < n && path[idx] == '.' && names.size() > 0)
                    names.pop_back();
                else if(idx < n && path[idx] != '.' && path[idx] != '/')
                    isHidden = true;
            }
            else{
    	        string fileName;
                if(isHidden)
                    fileName = ".";
                else
                    fileName = "";
                isHidden = false;
                while(idx < n && path[idx] != '/' && path[idx] != '.'){
                    fileName += path[idx];
                    idx++;
                }
                names.push_back(fileName);
            }
        }
	for(int i = 0;i < names.size();i++)
            result += "/" + names[i];
        if(result.size() == 0)
            return "/";
        return result;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->simplifyPath("/.hidden") << endl;
	return 0;
}
