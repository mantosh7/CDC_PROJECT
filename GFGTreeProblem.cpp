// Q. Diameter of a Binary Tree
class Solution {
    public:
        int height(Node* root, int &diameter) {
            if (!root) return 0;
            
            int leftHeight = height(root->left, diameter);
            int rightHeight = height(root->right, diameter);
            
            // Update the diameter (number of edges is nodes - 1)
            diameter = max(diameter, leftHeight + rightHeight);
            
            // Return height of the subtree
            return max(leftHeight, rightHeight) + 1;
        }
        
        int diameter(Node* root) {
            int diameter = 0;
            height(root, diameter);
            return diameter;
        }
    };
    
    
    // Q. Level order traversal
    class Solution {
      public:
        vector<vector<int>> levelOrder(Node *root) {
            vector<vector<int>> result;
            if (!root) return result;
    
            queue<Node*> q;
            q.push(root);
    
            while (!q.empty()) {
                int levelSize = q.size();
                vector<int> levelNodes;
                
                for (int i = 0; i < levelSize; i++) {
                    Node* node = q.front();
                    q.pop();
                    levelNodes.push_back(node->data);
    
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                
                result.push_back(levelNodes);
            }
    
            return result;
        }
    };
    
    
    // Q. Vertical Order Traversal
    class Solution {
    public:
        vector<vector<int>> verticalOrder(Node *root) {
            vector<vector<int>> result;
            if (!root) return result;
    
            // Map to store nodes according to horizontal distance
            map<int, vector<int>> nodesAtDistance;
    
            // Queue to perform level order traversal with horizontal distance
            queue<pair<Node*, int>> q;
            q.push({root, 0});
    
            while (!q.empty()) {
                auto temp = q.front();
                q.pop();
    
                Node* currNode = temp.first;
                int hd = temp.second; // horizontal distance
    
                // Store current node in map corresponding to its horizontal distance
                nodesAtDistance[hd].push_back(currNode->data);
    
                if (currNode->left)
                    q.push({currNode->left, hd - 1});
                if (currNode->right)
                    q.push({currNode->right, hd + 1});
            }
    
            // Traverse the map to collect results in the required order
            for (auto &entry : nodesAtDistance) {
                result.push_back(entry.second);
            }
    
            return result;
        }
    };
      
    
      