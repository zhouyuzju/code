/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<pair<int,bool> > list;
        vector<Interval> result;
        if(intervals.size() == 0)
            return result;
        for(int i = 0;i < intervals.size();i++){
            list.push_back(make_pair(intervals[i].start,false));
            list.push_back(make_pair(intervals[i].end,true));
        }
        sort(list.begin(),list.end());
        int start = list[0].first, end,idx = 0;
        int cnt = 0;
        while(true){
            if(idx >= list.size())
                break;
            if(list[idx].second == false){
                cnt++;
                if(cnt == 1)
                    start = list[idx].first;
            }
            else{
                cnt--;
                if(cnt == 0){
                    end = list[idx].first;
                    result.push_back(Interval(start,end));
                }
            }
            idx++;
        }
        return result;
    }
};

