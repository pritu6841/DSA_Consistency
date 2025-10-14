class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int currSum = arr[0];
        int maxSum = arr[0];
        for(int i = 1; i<arr.size(); i++){
            if(currSum < 0) currSum = 0;
            currSum += arr[i];
            if(currSum > maxSum) maxSum = currSum;
            
        }
        return maxSum;
    }
};