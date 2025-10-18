class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr.size() == 0) return 0;
        int longest = 1;
        int cnt = 1;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i] == arr[i-1] + 1) cnt += 1;
            else if(arr[i] > arr[i-1] + 1) cnt = 1;
            longest = max(longest, cnt);
        }
        return longest;
    }
};