//
//  282_add_operators.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _82_add_operators_h
#define _82_add_operators_h
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperatorsDFS(num, target, 0, 0, "", res);
        return res;
    }
    void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res) {
        if (num.size() == 0 && curNum == target) {
            res.push_back(out);
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if (out.size() > 0) {
                addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
            } else {
                addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
    }
};


#endif /* _82_add_operators_h */
