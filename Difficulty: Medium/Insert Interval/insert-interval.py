class Solution:
    def insertInterval(self, intervals, newInterval):
        # Code here
        l=[]
        i=0
        n=len(intervals)

        while i<n and intervals[i][1]<newInterval[0]:
            l.append(intervals[i])
            i+=1

        while i<n and intervals[i][0]<=newInterval[1]:
            newInterval[0]=min(newInterval[0],intervals[i][0])
            newInterval[1]=max(newInterval[1],intervals[i][1])
            i+=1

        l.append(newInterval)

        while i<n:
            l.append(intervals[i])
            i+=1

        return l

