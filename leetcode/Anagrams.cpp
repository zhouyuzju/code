class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if(strs.size() == 0)
            return res;
        map<string,int> amap;
        for(int i = 0;i < strs.size();i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            if(amap.find(tmp) == amap.end())
                amap.insert(make_pair(tmp,i));
            else{
                if(amap[tmp] >= 0){
                    res.push_back(strs[amap[tmp]]);
                    amap[tmp] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};

