class Solution {
public:
    bool isPossible(vector<int>& arr) {
        long long sum = 0;
        for(auto s: arr) sum += s;
        priority_queue<int>pq(arr.begin(), arr.end());

        while(pq.top()!= 1){
            long long maxElement = pq.top();
            pq.pop();
            long long remainingSum = sum - maxElement;
            if(remainingSum >= maxElement || remainingSum <= 0) return 0;
            int ele = maxElement % remainingSum;
            if(ele == 0){
                if(remainingSum != 1) return 0;
                else return 1;
            } 
            sum = remainingSum + ele;
            pq.push(ele);
        }
        return pq.top() == 1;
    }
};