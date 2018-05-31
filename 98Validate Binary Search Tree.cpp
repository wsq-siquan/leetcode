/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool helper(struct TreeNode* root, long int maxv, long int minv) {
    if(!root) {
        return true;
    } else {
        int v = root -> val;
        if(root -> left && (root -> left -> val >= v || root -> left -> val <= minv)) {
            return false;
        }
        if(root -> right && (root -> right -> val <= v || root -> right -> val >= maxv)) {
            return false;
        }
        return helper(root -> left, v, minv) && helper(root -> right, maxv, v);
    }
}

bool isValidBST(struct TreeNode* root) {
    if(!root) {
        return true;
    } else {
        int v = root -> val;
        if(root -> left && root -> left -> val >= v) {
            return false;
        }
        if(root -> right && root -> right -> val <= v) {
            return false;
        }
        return helper(root -> left, v, -2147483649) && helper(root -> right, 2147483648, v);
    }
}
