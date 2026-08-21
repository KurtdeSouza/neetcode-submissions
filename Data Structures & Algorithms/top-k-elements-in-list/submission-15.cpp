class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto i : nums){
            m[i]++;
        }
        vector<std::vector<int>> buckets(nums.size());
        for(const auto&[key ,value] : m){
            buckets[value-1].push_back(key);
        }
        vector<int> res;
        
        for(int i = buckets.size() - 1; i > -1; i--){
            for(int j = 0; j < buckets[i].size(); j++){
                if(res.size() < k){
                    res.push_back(buckets[i][j]);

                }
            }
        }
        
        return res;
    }
};
