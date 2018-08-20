//
//  491_find_subsequences.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _91_find_subsequences_h
#define _91_find_subsequences_h

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> out;
        helper(nums, 0, out, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void helper(vector<int>& nums, int start, vector<int>& out, set<vector<int>>& res) {
        if (out.size() >= 2) res.insert(out);
        for (int i = start; i < nums.size(); ++i) {
            if (!out.empty() && out.back() > nums[i]) continue;
            out.push_back(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};

#endif /* _91_find_subsequences_h */
