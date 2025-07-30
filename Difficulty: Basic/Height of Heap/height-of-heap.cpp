class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        // code here
        int cnt = 0;
        while(n>1){
            cnt += 1;
            n /= 2; //jb tk n == 1 na ho jaye tb tk chlte rho 
        }
        if(cnt == 0) return 1;
        return cnt;
    }
};