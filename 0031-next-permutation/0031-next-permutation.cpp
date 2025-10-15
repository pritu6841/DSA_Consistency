class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int idx = -1;

        //finding break point
        for(int i = n-2; i>=0; i--){
            if(arr[i] < arr[i+1]) {
                idx = i;
                break;
            }
        }

        //base case
        if(idx == -1) reverse(arr.begin(), arr.end());
        else{
        //find next greater element in the remaining array
        for(int i = n-1; i>=0; i--) {
            if(arr[i] > arr[idx]){
                swap(arr[i], arr[idx]);
                break;
            }
        }

        //sort the remaining array
         reverse(arr.begin()+idx+1, arr.end());
         }
    }
};