class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
       vector<vector<int> > ans; 
    sort(num.begin(),num.end());
    if(num.size()<4) {
        return ans;
    }
    map<int,vector<pair<int,int> > > m;
    for(int i=0;i<num.size();i++) {
        for(int j=i+1;j<num.size();j++) {
            m[ num[i]+num[j] ].push_back(pair<int,int>(i,j));
        }
    }   
    for(int i=0;i<num.size();i++) {
        for(int j=i+1;j<num.size();j++) {
            int x = (target - num[i] - num[j]);
            if(m.find(x) != m.end()) {
                for(vector<pair<int,int> >::iterator it = m[x].begin();
                        it != m[x].end(); it ++ ) { 
                    if(it->first <= j) {
                        continue;
                    }
                    if(!ans.size() || ans[ans.size()-1][0] != num[i] ||
                            ans[ans.size()-1][1] != num[j] || 
                            ans[ans.size()-1][2] != num[it->first] ) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[it->first]);
                        tmp.push_back(num[it->second]);
                        ans.push_back(tmp);
                    }
                }
            }   
        }   
    }  
    vector<vector<int> > aa;
    for(int i=0;i<ans.size();i++) {
        int flag = 1;
        for(int j=0;j<aa.size();j++) {
            if(ans[i][0] == aa[j][0] && ans[i][1] == aa[j][1] &&
                    ans[i][3] == aa[j][3]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            aa.push_back(ans[i]);
        }
    }
    return aa;
    }
};

