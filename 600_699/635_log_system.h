//
//  635_log_system.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _35_log_system_h
#define _35_log_system_h

class LogSystem {
public:
    LogSystem() {
        units = {"Year", "Month", "Day", "Hour", "Minute", "Second"};
        indices = {4, 7, 10, 13, 16, 19};
    }
    
    void put(int id, string timestamp) {
        timestamps.push_back({id, timestamp});
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> res;
        int idx = indices[find(units.begin(), units.end(), gra) - units.begin()];
        for (auto p : timestamps) {
            string t = p.second;
            if (t.substr(0, idx).compare(s.substr(0, idx)) >= 0 && t.substr(0, idx).compare(e.substr(0, idx)) <= 0) {
                res.push_back(p.first);
            }
        }
        return res;
    }
    
private:
    vector<pair<int, string>> timestamps;
    vector<string> units;
    vector<int> indices;
};

#endif /* _35_log_system_h */
