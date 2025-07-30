class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int res = 0;
        priority_queue<int, vector<int>, greater<int>>pq(arr.begin(), arr.end());
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            res += (a+b);
            pq.push(a+b);
        }
        return res;
    }
};