// Q. Rotate a Matrix by 90 Degrees
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n=mat.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(mat[i][j],mat[i][n-j-1]);
        }
    }
}


// Q. Boundary Traversal of a Matrix
class Solution {
public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> >& mat) {
        int i=mat.size();
        int j=mat[0].size();
        int c=0;
        int row=0,col=0;
        vector<int> trav;
        while(c<i*j)
        {
            if (row == 0 && col < j) {  
            // 1. Move right (First row)
            trav.push_back(mat[row][col]);
            col++;
        } 
        else if (col == j) {  
            // 2. Move down (Last column)
            row++;
            trav.push_back(mat[row][col - 1]);
        } 
        else if (row == i) {  
            // 3. Move left (Last row)
            col--;
            trav.push_back(mat[row - 1][col]);
        } 
        else if (col == 0 && row > 0) {  
            // 4. Move up (First column)
            row--;
            trav.push_back(mat[row][col]);
        }
            c++;
        }
        return trav;
    }
};