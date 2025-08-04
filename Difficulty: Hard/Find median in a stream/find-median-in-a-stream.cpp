#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
  public:
    // leftMin is actually the lower-half max-heap, rightMax is the upper-half min-heap
    priority_queue<int> leftMin; // max-heap
    priority_queue<int, vector<int>, greater<int>> rightMax; // min-heap

    void insert(int x){
        if (leftMin.empty()) {
            leftMin.push(x);
            return;
        }
        if (x > leftMin.top())
            rightMax.push(x);
        else
            leftMin.push(x);
        balance();
    }

    void balance(){
        if (rightMax.size() > leftMin.size()) {
            leftMin.push(rightMax.top());
            rightMax.pop();
        }
        else if (leftMin.size() > rightMax.size() + 1) {
            rightMax.push(leftMin.top());
            leftMin.pop();
        }
    }

    double getMedian(){
        double ans;
        if (leftMin.size() > rightMax.size())
            ans = leftMin.top();
        else {
            double first = leftMin.top();
            double sec = rightMax.top();
            ans = (first + sec) / 2.0;
        }
        return ans;
    }

    vector<double> getMedian(vector<int> &arr) {
        vector<double> res;
        for (int x : arr) {
            insert(x);
            res.push_back(getMedian());
        }
        return res;
    }
};
