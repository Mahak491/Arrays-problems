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
class BSTIterator {
    private: stack<TreeNode*> st;
    bool reverse = true;
public:
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse = isReverse;
        pushAll(root); 
    }
    
    int next() {
      TreeNode* top = st.top();
        st.pop();
        if(!reverse){
        pushAll(top->right);
        }
        else
        {
            pushAll(top->left);
        }
        return top->val;
    }
    
    bool hasNext() {
       if(st.empty()){
           return false;
       } 
        return true;
    }
    
    private:
    void pushAll(TreeNode* node){
        while(node != NULL){
            st.push(node);
            if(reverse == false)
                node = node->left;
            else
                node = node->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};