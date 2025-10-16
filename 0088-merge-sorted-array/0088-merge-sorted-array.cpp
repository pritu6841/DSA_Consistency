class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        for(int i = 0; i<m; i++) nums1[n+i] = nums2[i];

        //now follow shell sorting
        int gap = ceil((double)(n+m)/2);
        bool flag = true;
        while(gap > 0 && flag){
            if(gap == 1) flag = false;
            int idx = gap;
            int i = 0;
            while(idx < n+m){
                if(nums1[i] > nums1[idx]){
                    swap(nums1[i], nums1[idx]);
                }
                i++;
                idx++;
            }
            gap = (gap + 1) / 2;  // integer ceiling

        }
    }
};