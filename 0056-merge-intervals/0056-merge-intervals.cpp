class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

        vector<vector<int>>ans;
        int first= v[0][0], sec= v[0][1];
        for(int i = 0; i<v.size()-1; i++){
            if(sec >= v[i+1][0]) {
                if(sec < v[i+1][1])
                sec = v[i+1][1];
            }
            else{
                ans.push_back({first, sec});
                first = v[i+1][0];
                sec= v[i+1][1];
            }
        }
        ans.push_back({first, sec});
        return ans;
    }
};