//
//  533_find_black_pixel.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _33_find_black_pixel_h
#define _33_find_black_pixel_h

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size(), res = 0;
        vector<int> colCnt(n, 0);
        unordered_map<string, int> u;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++colCnt[j];
                    ++cnt;
                }
            }
            if (cnt == N) ++u[string(picture[i].begin(), picture[i].end())];
        }
        for (auto a : u) {
            if (a.second != N) continue;
            for (int i = 0; i < n; ++i) {
                res += (a.first[i] == 'B' && colCnt[i] == N) ? N : 0;
            }
        }
        return res;
    }
};

#endif /* _33_find_black_pixel_h */
