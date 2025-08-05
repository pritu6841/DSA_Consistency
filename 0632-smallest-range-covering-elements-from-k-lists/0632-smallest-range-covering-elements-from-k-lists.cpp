class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<int>ans;
        pair<int, int>ans2;
        int idx = 0;
        int greatest = INT_MIN;int smallest = INT_MAX;
        priority_queue<pair<int, pair<int, int>>,
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i<n; i++){ 
            pq.push(make_pair(nums[i][0], make_pair(i, 0)));
            greatest = max(greatest, nums[i][0]);
            if(nums[i][0] < smallest){
                smallest = nums[i][0];
                idx = i;
            }
            }
        int mini = INT_MAX;
        int j = 0;
        int m = nums[idx].size() ;
        while(j<m){
            pair<int, pair<int, int>> p = pq.top();
            int small = p.first;
            int i = p.second.first;
            int j = p.second.second;
            m = nums[i].size();
            cout<<greatest-small<<endl;
            if(greatest - small < mini){
                
                ans2.first = small;
                ans2.second = greatest;
                mini = greatest - small;
            }
            else if(greatest - small == mini){
                if(small < ans2.first){
                    cout<<small<<"-> "<<ans2.first<<endl;
                    ans2.first = small;
                    ans2.second = greatest;
                }
            }
            pq.pop();
            if(j+1<m){
                pq.push(make_pair(nums[i][j+1], make_pair(i, j+1)));
                greatest = max(greatest, nums[i][j+1]);
            }
            else break;
            
        }
        ans.push_back(ans2.first);
        ans.push_back(ans2.second);
        return ans;
    }
};