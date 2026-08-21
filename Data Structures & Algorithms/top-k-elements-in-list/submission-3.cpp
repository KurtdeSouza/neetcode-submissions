class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i : nums){
            m[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }
        vector<int> answer;
        while(answer.size() < k){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};