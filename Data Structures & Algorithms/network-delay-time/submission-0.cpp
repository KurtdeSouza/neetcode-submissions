class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> m; // map of node to edges with [weight,node]
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

        for(const auto& t : times){
            m[t[0]].push_back({t[1],t[2]});// weight node so minheap can pick lightest edge
        }
        unordered_map<int, int> shortest;
        minheap.push({0,k}); //heap stores min weight to reach a node

        while(minheap.size() != 0){
            auto [weight, node] = minheap.top();
            minheap.pop();
            if(shortest.contains(node)){
                continue;
            }
            shortest[node] = weight;
            for(const auto& [n2, weight2 ] : m[node]){
                if(!shortest.contains(n2)){
                    minheap.push({weight + weight2, n2});
                }
            }

        }
        int result;
        if(shortest.size() != n){
            return -1;
        }
        for(const auto & [node, weight] : shortest){
            result = max(result, weight);
        }
        return result;
    }
};
