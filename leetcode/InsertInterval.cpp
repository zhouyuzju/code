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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        vector<pair<int,bool> > list;
        list.push_back(make_pair(newInterval.start,false));
        list.push_back(make_pair(newInterval.end,true));
        for(int i = 0;i < intervals.size();i++){
            list.push_back(make_pair(intervals[i].start,false));
            list.push_back(make_pair(intervals[i].end,true));
        }
        sort(list.begin(),list.end());
        int cnt = 0,idx = 0,start,end;
        while(idx < list.size()){
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

