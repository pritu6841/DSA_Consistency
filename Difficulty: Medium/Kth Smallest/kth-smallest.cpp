// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>>pq(arr.begin(), arr.end());
        for(int i = 0; i<k; i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};