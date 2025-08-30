class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++){
            bool chk=true;
            for(int r=0;r<n;r++){
                if(!mat[r][i]) chk=false;
            }
            if(!chk) continue;
            for(int c=0;c<n;c++){
                if(c!=i && mat[i][c]) chk=false;
            }
            if(!chk) continue;
            return i;
        }
        return -1;
    }
};