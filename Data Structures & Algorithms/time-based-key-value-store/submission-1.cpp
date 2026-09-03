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
            for(auto a : timeline[key]){
                if(a.first <= timestamp){
                    res = a.second;
                }
            }
            return res;
        }else{
            return "";
        }
    }
};
