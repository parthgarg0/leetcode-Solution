/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int ans = 0;

        while (!q.empty()) {

            int size = q.size();
            long long minIdx = q.front().second;

            long long first, last;

            for (int i = 0; i < size; i++) {

                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                long long idx = curr.second - minIdx;   // normalize

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (node->left)
                    q.push({node->left, idx * 2 + 1});

                if (node->right)
                    q.push({node->right, idx * 2 + 2});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};