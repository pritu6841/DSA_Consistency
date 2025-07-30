class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int>ans;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0; i<k; i++) {
            pq.push(arr[i]);
            if(i == k-1) ans.push_back(pq.top());
            else ans.push_back(-1);
        }
        
        for(int i = k; i<n; i++){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};