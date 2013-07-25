class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int,int> > sortedList;
        for(int i = 0;i < numbers.size();i++)
            sortedList.push_back(make_pair(numbers[i],i + 1));
        sort(sortedList.begin(),sortedList.end());
        vector<int> result;
        int i = 0,j = sortedList.size() - 1;
        while(i < j){
            if(sortedList[i].first + sortedList[j].first == target){
                result.push_back(sortedList[i].second);
                result.push_back(sortedList[j].second);
                sort(result.begin(),result.end());
                break;
            }
            else if(sortedList[i].first + sortedList[j].first > target)
                j--;
            else
                i++;
        }
        return result;
    }
};

