#include <algorithm> // Required header

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> res;
        int curr_h;
        int area = 0;
        pair<int , int> check;
        int h, ind;
        int start;
        for(int i = 0; i < heights.size() ; i++){
            curr_h = heights[i];
            start = i;
            while(res.size() > 0 && curr_h < res.top().first){
                check = res.top();
                h = check.first;
                ind = check.second;
                res.pop();
                if(area < h * (i - ind)){
                    area = h * (i - ind);
                }
                start = ind;
                

            }
            res.push({curr_h, start});
            

        }
        while(res.size() > 0){
            check = res.top();
            h = check.first;
            ind = check.second;
            res.pop();
            if(area < h * (heights.size() - ind)){
                area = h * (heights.size()- ind);
            }
        }
        return area;
    }
};
