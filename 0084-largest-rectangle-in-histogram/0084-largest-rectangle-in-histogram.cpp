class Solution {
public:
    vector<int>nextSmaller(vector<int>& h){
        stack<int>st;
        st.push(-1);
        int n = h.size();
        vector<int>ns(n);
        for(int i = n-1; i>=0; i--){
            while(st.top() != -1 && h[st.top()] >= h[i]) st.pop();
            ns[i] = st.top();
            st.push(i);
        }
        return ns;
        }
    vector<int>previoussmaller(vector<int>& h){
        stack<int> st;
        vector<int>ns(h.size());
        st.push(-1);
        for(int i = 0; i<h.size(); i++){
            while(st.top()!=-1 && h[st.top()]>=h[i]){
                st.pop();
            }
            ns[i] = st.top();
            st.push(i);
        }
        return ns;
    }
    int largestRectangleArea(vector<int>& h) {
       vector<int> ns,ps;
       ns = nextSmaller(h);
       ps = previoussmaller(h);

       int area = INT_MIN;
       for(int i = 0; i<h.size(); i++){
        int l = h[i];
        if(ns[i] == -1){
            ns[i] = h.size();
        }
        int b = ns[i] - ps[i] - 1;
        int a = l*b;
        area = max(area, a);
       }
       return area;
    }
};