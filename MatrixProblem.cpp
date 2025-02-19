// 566. Reshape the Matrix
class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            vector<vector<int>> mat2(r,vector<int>(c));
            int m = mat.size(), n = mat[0].size();
            int row=0,col=0;
            if (m * n != r * c) return mat; 
            for(int i=0;i<mat.size();i++)
            {
                for(int j=0;j<mat[0].size();j++)
                {
                    mat2[row][col]=mat[i][j];
                    col++;
                    if(col==c)
                    {
                        col=0;
                        row++;
                    }
                }
            }
            return mat2;
        }
    };
    
    
    // 867. Transpose Matrix
    class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& matrix) {
            vector<vector<int>> tra(matrix[0].size(),vector<int>(matrix.size()));
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    tra[j][i]=matrix[i][j];
                }
            }
            return tra;
        }
    };
    
    
    // 498. Diagonal Traverse
    class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
            
            vector<int> res;
            map<int, vector<int>> mp;
            
            for(int i = 0 ; i < matrix.size() ; i++) 
                for(int j = 0 ; j < matrix[0].size() ; j++)
                    mp[i + j].push_back(matrix[i][j]);
            
            for(auto i : mp) {
                if((i.first)%2 == 0) 
                    reverse(i.second.begin(), i.second.end()); 
                
                for(auto k : i.second) res.push_back(k);
            }
            return res;
        }
    };
    
    
    // 1572. Matrix Diagonal Sum
    class Solution {
    public:
        int diagonalSum(vector<vector<int>>& mat) {
            int sum=0;
            for(int i=0;i<mat.size();i++)
            {
                for(int j=0;j<mat[0].size();j++)
                {
                    if(i+j==mat.size()-1||i==j) sum+=mat[i][j];
                }
            } 
            return sum;
        }
    };