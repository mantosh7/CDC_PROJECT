// 94. Binary Tree Inorder Traversal
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> stack;
            TreeNode* curr = root;
    
            while (curr != nullptr || !stack.empty()) {
                while (curr != nullptr) {
                    stack.push(curr);
                    curr = curr->left;
                }
                curr = stack.top();
                stack.pop();
                result.push_back(curr->val);
                curr = curr->right;
            }
    
            return result;
        }
    };
    
    
    // 104. Maximum Depth of Binary Tree
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
        int maxDepth(TreeNode* root) {
            return depth(root);
        }
    private:
        int depth(TreeNode*root)
        {
            if(root==NULL)
            return 0;
            return 1+max(depth(root->left),depth(root->right));
        }
    };
    
    
    // 236. Lowest Common Ancestor of a Binary Tree
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==nullptr || p->val==root->val || q->val==root->val){
                return root;
            }
            TreeNode* left=lowestCommonAncestor(root->left,p,q);
            TreeNode* right=lowestCommonAncestor(root->right,p,q);
            if(left==nullptr){
                return right;
            }else if(right==nullptr){
                return left;
            }else{
                return root;
            }
            return nullptr;
            
        }
    };
    
    
    // 112. Path Sum
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
     **/
    class Solution {
    public:
        bool rootToLeafPathSum(TreeNode* root, int targetSum, int sum){
            if(root == nullptr)
                return false;
            if(root -> left == nullptr && root -> right == nullptr){
                sum = sum + root -> val;
                if(sum == targetSum)
                    return true;   
            }
            return rootToLeafPathSum(root -> left, targetSum, sum + root -> val) || rootToLeafPathSum(root -> right, targetSum, sum + root -> val);
        }
        bool hasPathSum(TreeNode* root, int targetSum) {
            int sum = 0;
            return rootToLeafPathSum(root, targetSum, sum);
        }
    };