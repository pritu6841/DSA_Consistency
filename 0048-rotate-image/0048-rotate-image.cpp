class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
    int n = mat.size();

    // Step 1: Transpose (swap only once)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (auto &row : mat) {
        reverse(row.begin(), row.end());
    }
}

};