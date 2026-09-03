class TimeMap {
private: 
    unordered_map<string, vector<pair<int,string>>> timeline;
public:
    TimeMap() {
        timeline = {};
        
    }
    
    void set(string key, string value, int timestamp) {
        timeline[key].emplace_back(timestamp, value);
        
    }
    
    string get(string key, int timestamp) {
        string res  = "";
        if(timeline.contains(key)){
            int L = 0, R = timeline[key].size() - 1, M;
            while(L <= R){
                M = L + (R - L)/2;
                if(timeline[key].at(M).first == timestamp){
                    return timeline[key].at(M).second;
                }else if(timeline[key].at(M).first > timestamp){
                    R = M - 1;
                }else{
                    res = timeline[key].at(M).second;
                    L = M + 1;
                }
            }
        }
        return res;

    }
};
