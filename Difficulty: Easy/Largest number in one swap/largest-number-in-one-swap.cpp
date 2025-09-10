class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        
        vector<vector<int>> arr(10);
        
        for(int i=0; i<s.size(); i++){
            
            int t = s[i] - '0';
            
            arr[t].push_back(i);
        }
        
        for(int i=0; i<s.size(); i++){
            
            int t = s[i] - '0';
            
            bool flag = false;
            
            int index = -1;
            
            for(int  j = 9; j>t; j--){
                
                int val = -1;
                
                if(arr[j].size() > 0 ) val = arr[j][arr[j].size() - 1];
                
                if(val > i) {
                    index = val;
                    break;
                }
            }
            
            if(index != -1){
               swap(s[i], s[index]);
               break;
                
            }
        }
        
        return s;
    }
};

