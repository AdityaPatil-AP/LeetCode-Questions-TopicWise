/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    // Optimised Approach.
    Node *construct(vector<vector<int>> &grid)
    {
        // Time Complexity in normal Approach is O(n^2 * log(n)).
        // We are iterating over the grid log(n) times.
        // How to reduce that to O(n^2).
        // Solution - If we iterate over the four submatrices first and check for them
        // We just have to iterate over the array just once.
        // The base case in this approach would be when the size of square becomes 1.
        // Then it is always a leaf node.
        // Now if all the four submatrices called gives a leaf node with same value. Then the whole is a leaf node.
        // and we can simply return new Node(topLeft->val, true);

        // else it will not a leaf node and we have to return all the pointers.
        int n = grid.size();
        return solve(0, 0, n, grid);
    }

    Node *solve(int x, int y, int length, vector<vector<int>> &grid)
    {
        // Base Case when the side of square is 1. Then it is always a leaf node.
        if (length == 1)
        {
            return new Node(grid[x][y], true);
        }

        Node *topLeft = solve(x, y, length / 2, grid);
        Node *topRight = solve(x, y + length / 2, length / 2, grid);
        Node *bottomLeft = solve(x + length / 2, y, length / 2, grid);
        Node *bottomRight = solve(x + length / 2, y + length / 2, length / 2, grid);

        // If all the submatrices are leaf nodes with the same value, then the current node is also
        // a leaf node.
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            return new Node(topLeft->val, true);
        }

        // else it is not a leaf node so return the node with four submatrices.
        return new Node(topLeft->val, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    // Brute Force Approach
    // Node* construct(vector<vector<int>>& grid) {
    //     // Time Complexity in normal Approach is O(n^2 * log(n)).
    //     int n = grid.size();
    //     return helper(0, 0, n, grid);
    // }

    //     Node* helper(int x1, int y1, int length, vector<vector<int>> &grid){

    //         // If all the values are equal in subgrid, then it is a leaf node.
    //         if(checkEqual(x1, y1, length, grid)){
    //             return new Node(grid[x1][y1], true);
    //         }

    //         // If it is not a leaf node, then we must have four children for it.
    //         // Four different calls
    //         else {
    //             Node* ans = new Node(false, false);
    //             ans->topLeft = helper(x1, y1, length/2, grid);
    //             ans->topRight = helper(x1, y1 + length/2, length/2, grid);
    //             ans->bottomLeft = helper(x1 + length/2, y1, length/2, grid);
    //             ans->bottomRight = helper(x1 + length/2, y1 + length/2, length/2, grid);

    //             return ans;
    //         }
    //     }

    //     bool checkEqual(int x1, int y1, int length, vector<vector<int>> &grid){
    //         int num = grid[x1][y1];
    //         for(int i = x1;i < x1 + length;i++){
    //             for(int j = y1;j < y1 + length;j++){
    //                 if(num != grid[i][j]){
    //                     return false;
    //                 }
    //             }
    //         }

    //         return true;
    //     }
};