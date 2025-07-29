class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini = INT_MAX;
       for(int i = 0; i<strs.size(); i++){
        string s = strs[i];
        int size = s.size();
        mini = min(mini, size);
       }
       string a ;
       int k = 0;
       string str = "";
       string pq = strs[0];
       for(int j = 0; j<mini; j++){
        str += pq[k++]; int cnt = 0;
        for(int i = 0; i<strs.size(); i++){
            string tb = strs[i];
            if(tb.starts_with(str) ) cnt++;
        }
        if(cnt  == strs.size()) {
            a = str;
            continue;}
        else break;

       }
       return a;
    }
};