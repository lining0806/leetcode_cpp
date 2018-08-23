//
//  750_ip_2cidr.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _50_ip_2cidr_h
#define _50_ip_2cidr_h

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;
        long x = 0;
        istringstream is(ip);
        string t;
        while (getline(is, t, '.')) {
            x = x * 256 + stoi(t);
        }
        while (n > 0) {
            long step = x & -x;
            while (step > n) step /= 2;
            res.push_back(convert(x, step));
            x += step;
            n -= step;
        }
        return res;
    }
    string convert(long x, int step) {
        return to_string((x >> 24) & 255) + "." + to_string((x >> 16) & 255) + "." + to_string((x >> 8) & 255) + "." + to_string(x & 255) + "/" + to_string(32 - (int)log2(step));
    }
};

#endif /* _50_ip_2cidr_h */
