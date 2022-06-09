/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       if(root == NULL) return 0;
        
        long ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            long mmin = q.front().second;
            long first,last;
            long s = q.size();
            for(int i=0;i<s;i++){
                long ind = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i==0) first = ind;
                if(i==s-1) last = ind;
                
                if(node->left) q.push({node->left,ind*2});
                
                if(node->right) q.push({node->right,ind*2+1});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
        
         
};