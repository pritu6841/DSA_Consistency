class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;

        for(auto &num: s){
            if(!s.count(num-1)){
                int cnt = 1;
                int curr = num;
                while(s.count(curr+1)){
                    curr++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};