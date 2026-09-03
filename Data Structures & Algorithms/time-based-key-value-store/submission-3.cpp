class TimeMap {
private: 
    unordered_map<string, vector<pair<int,string>>> timeline;
public:
    TimeMap() {
        timeline = {};
        
    }
    
    void set(string key, string value, int timestamp) {
        if(timeline.contains(key)){
            timeline[key].push_back({timestamp, value});
        }else{
            timeline.insert({key, {{timestamp, value}}});
        }
    }
    
    string get(string key, int timestamp) {
        string res;
        if(timeline.contains(key)){
            int L = 0, R = timeline[key].size() - 1, M;
            int res = 0;
            while(L <= R){
                M = L + (R - L)/2;
                if(timeline[key].at(M).first == timestamp){
                    return timeline[key].at(M).second;
                }else if(timeline[key].at(M).first > timestamp){
                    R = M - 1;
                }else{
                    res = M;
                    L = M + 1;
                }
            }
            if( timeline[key].at(res).first > timestamp){
                return "";
            }
            return timeline[key].at(res).second;
        }else{
            return "";
        }
    }
};
