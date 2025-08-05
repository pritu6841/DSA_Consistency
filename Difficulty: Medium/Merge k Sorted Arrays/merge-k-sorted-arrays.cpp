class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        // code here
        vector<int>ans;
        pair<int, pair<int, int>>p;
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>>pq;
                      
        for(int i = 0; i<k; i++) pq.push(make_pair(arr[i][0], make_pair(i ,0)));
        int i, j;
        while(!pq.empty()){
            p = pq.top();
            ans.push_back(p.first);
            i = p.second.first;
            j = p.second.second;
            if(j+1<k) pq.push(make_pair(arr[i][j+1], make_pair(i, j+1)));
            pq.pop();
        }
        return ans;
    }
};