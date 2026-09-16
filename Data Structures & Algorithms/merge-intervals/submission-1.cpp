class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(const auto & interval : intervals){
            if(interval[0] <= end){
                end = max(interval[1], end);
            }else{
                result.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }
        result.push_back({start, end});
        return result;
    }
};
