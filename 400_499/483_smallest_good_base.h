//
//  483_smallest_good_base.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _83_smallest_good_base_h
#define _83_smallest_good_base_h

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stol(n);
        for (int i = log(num + 1) / log(2); i >= 2; --i) {
            long long left = 2, right = pow(num, 1.0 / (i - 1)) + 1;
            while (left < right) {
                long long mid = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum = sum * mid + 1;
                }
                if (sum == num) return to_string(mid);
                else if (sum < num) left = mid + 1;
                else right = mid;
            }
        }
        return to_string(num - 1);
    }
};

#endif /* _83_smallest_good_base_h */
