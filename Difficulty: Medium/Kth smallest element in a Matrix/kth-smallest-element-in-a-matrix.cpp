class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        priority_queue<int> pq;
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                pq.push(mat[i][j]);
                if (pq.size() > k) {
                    pq.pop();  // remove the largest
                }
            }
        }
        return pq.top();  
    }
};
