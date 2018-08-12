//
//  333_largest_bst_subtree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _33_largest_bst_subtree_h
#define _33_largest_bst_subtree_h

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        if (isValid(root, INT_MIN, INT_MAX)) return count(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
    bool isValid(TreeNode* root, int mn, int mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
    }
    int count(TreeNode* root) {
        if (!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }
};

#endif /* _33_largest_bst_subtree_h */
