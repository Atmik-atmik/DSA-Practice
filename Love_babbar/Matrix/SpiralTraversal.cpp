#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while(top <= bottom && left <= right) {
            // Traverse top row (left to right)
            for(int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;

            // Traverse right column (top to bottom)
            for(int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            // Traverse bottom row (right to left), if not already traversed , in non squre matrix top and bottom can represetn same row. hence if current is alredy visited no need to visit it again.
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Traverse left column (bottom to top), if not already traversed
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
};
