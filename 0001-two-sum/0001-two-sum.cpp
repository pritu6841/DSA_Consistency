class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int sum=0;
       int a=nums.size();
       for(int i=0;i<a-1;i++){
     for(int j=i+1;j<a;j++){

         if(nums[i]+nums[j]==target){
             return {i,j};
         }
     }
   
       
              
       
       }
    return{};
    }
};
        
    