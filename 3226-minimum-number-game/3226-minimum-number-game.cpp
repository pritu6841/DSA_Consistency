class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>,greater<int>> minHeap(nums.begin(), nums.end());
        vector<int>ans;
        while (minHeap.size() >0){
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top(); 
            minHeap.pop();
            ans.push_back(b);
            ans.push_back(a);
        }

        return ans;
    

    }
};