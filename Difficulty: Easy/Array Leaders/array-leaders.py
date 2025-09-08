class Solution:
    def leaders(self, arr):
        ans = []
        n = len(arr)
        ans.append(arr[n-1])
        max = arr[n-1]
        for i in range (n-2,-1,-1):
            if arr[i] >= max:
                ans.append(arr[i])
                max = arr[i]
        
        return reversed(ans)

