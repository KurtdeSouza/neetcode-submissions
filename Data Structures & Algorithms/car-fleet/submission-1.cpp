class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> m;
        stack<double> result;
        for(int i = 0; i < position.size(); i++){
            m.insert({position[i],speed[i]});

        }
        sort(position.begin(), position.end(), std::greater<int>());
        double arrival;
        int s;
        for(int i = 0; i < position.size(); i++){
            s = m[position[i]];
            arrival = static_cast<double>(target - position[i])/s;
            if(result.size() == 0 || arrival > result.top()){
                result.push(arrival);
            }

            
        }
        return result.size();
    }
};
