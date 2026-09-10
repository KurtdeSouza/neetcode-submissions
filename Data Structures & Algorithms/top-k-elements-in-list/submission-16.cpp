class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<vector<int>> population(nums.size()+1); // [0..6] each is a empty vector
        unordered_map<int,int> population_map;
        for(const auto n: nums){
            population_map[n]++;
        }
        for(const auto [key, value] : population_map){
            population[value].push_back(key);
        }
        vector<int> result;
        for(int i = population.size() - 1; i > -1; i--){
            for(const auto j : population[i]){
                if(k == 0){
                    break;
                }
                result.push_back(j);
                k--;
            }
        }
        return result;


    }
};
