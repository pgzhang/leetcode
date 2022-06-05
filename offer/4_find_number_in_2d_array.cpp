// Solution 1
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        auto pos = std::lower_bound(matrix[0].begin(), matrix[0].end(), target);
        int dis = 0;
        if (pos == matrix[0].end()){
            dis = cols;
        }
        else{
            if( *pos == target) return true;
            dis = std::distance(matrix[0].begin(), pos);
        }
        if(dis == 0) return false;
        for(int row = 1; row < rows; ++row){
            for(int col=dis-1; col < cols; ++col){
                int v = matrix[row][col];
                if(v == target) return true;
                else if(v > target) {
                    dis = col;
                    if (dis == 0) return false;
                    while(dis > 0 ){
                        --dis;
                        if(matrix[row][dis] == target){
                            return true;
                        }
                        else if (matrix[row][dis] < target){
                            break;
                        }
                    }
                    if(dis == 0 && matrix[row][dis] == target) return true;
                    else if(dis == 0 && matrix[row][dis] > target) return false;
                    else if(dis == 0 && matrix[row][dis] < target) ++dis;
                    break;
                }
            }
        }
        return false;
    }
};

// Solution 2
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int row=0; row<rows; ++row){
            for(int col=0; col<cols; ++col){
                if(matrix[row][col] == target) return true;
            }
        }
        return false;
    }
};

// Solution 3
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;

        int rows = matrix.size();
        int row = 0;
        auto pos = matrix[0].end();
        while((pos= std::find(matrix[row].begin(), matrix[row].end(), target)) == matrix[row++].end()){
            if (row == rows) break;
        }
        if(pos != matrix[rows-1].end()) return true;
        return false;
    }
};