class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res = 0;
        priority_queue<int>pq(gifts.begin(), gifts.end());
        for(int i = 0; i<k ; i++){
            int maxi = pq.top();
            pq.pop();
            int sq = (int)sqrt(maxi); 
            pq.push(sq);
        };
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};