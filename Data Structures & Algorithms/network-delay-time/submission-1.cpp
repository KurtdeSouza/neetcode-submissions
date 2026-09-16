class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> node_map;
        unordered_map<int, int>weight_map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lightest_node;
        int result;
        //building adjacency list
        for(const auto time : times){
            node_map[time[0]].push_back({time[1], time[2]});
        }
        lightest_node.push({0, k}); //to reach starting node, it costs 0
        while(lightest_node.size() != 0){
            auto [weight, node] = lightest_node.top();
            lightest_node.pop();
            if(weight_map.contains(node)){
                continue; //seen this node already
            }
            weight_map[node] = weight;
            for(const auto& n : node_map[node]){ //visit neighbors
                if(!weight_map.contains(n.first)){
                    lightest_node.push({weight + n.second, n.first});

                }
                //result = min(weight + n.second, result);
            }
        }
        if(weight_map.size() != n){
            return -1;
        }
        for(const auto & [node, weight] : weight_map){
            result = max(result, weight);
        }
        return result;


    }
};
