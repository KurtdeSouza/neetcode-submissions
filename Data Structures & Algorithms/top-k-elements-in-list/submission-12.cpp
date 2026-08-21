class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> initial;
        unordered_map<int, vector<int>> res;

        for(auto i :nums){
            initial[i]++;
        }
        vector<int> keys;
        for(auto&[key ,value]: initial){
            if(res.contains(value)){
                res[value].push_back(key);
            }else{
                res[value] = {key};

            }
            keys.push_back(value);
        }
        sort(keys.begin(), keys.end(),greater<int>());
        vector<int> fin;
        set<int> freq;
        for(auto ke : keys){
            if(!freq.contains(ke)){
                freq.insert(ke);
                for(int i = 0 ; i < res[ke].size(); i++){
                    if(fin.size() < k){
                        std::cout << res[ke][i];
                        fin.push_back(res[ke][i]);
                    }
                }
                std::cout<<"\n";
            }
            
            
        }
        return fin;
    }
};
