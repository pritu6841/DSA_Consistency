class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer;
        for(int row = 1; row<=numRows; row++){
            int ans = 1;
            vector<int>temp;
            for(int col = 1; col<=row; col++){
                temp.push_back(ans);
                ans = ans*(row-col) / col;
            }
            answer.push_back(temp);
        }
        return answer;
    }
};