class Solution:
    def maxOnes(self, arr, k):
        n=len(arr)
        l=0
        r=0
        ans=0
        zc=0
        while r<n:
            if arr[r]==0:
                zc+=1
            while zc>k:
                if arr[l]==0:
                    zc-=1
                l+=1
            if zc<=k:
                ans=max(ans,r-l+1)
            r+=1
        return ans
 